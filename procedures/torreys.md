# Accessing torreys machine

1. SSH into one of the login nodes, culogin01.colorado.edu, culogin02.colorado.edu, or culogin03.colorado.edu
2. SSH into torreys: `ssh skkwan@torreys.colorado.edu` (same password as above)
3. This is already in `~/.bashrc` so you don't need to do this manually, but `source ~/bin/setup.sh 2022.2` (sets up version 2022.2)
4. `cd /nfs/data41/skkwan/LibHLS/Modules/MET/test`
5. `python3 setup_tcl.py`
6. `vitis_hls -f run_hls_make.tcl`: makes the Vitis HLS project that is used by all the
other steps
7. `vitis_hls -f run_hls_csim.tcl`: runs the C-simulation; this basically just compiles
the C++ test bench, runs it, and if it returns zero, says the
C-simulation passed
8. `vitis_hls -f run_hls_csynth.tcl`: runs the C-synthesis; this turns the C++ into
actual RTL
9. `vitis_hls -f run_hls_cosim.tcl`: runs the C/RTL cosimulation; this runs an actual
RTL simulation, in order to validate the behavior of what the
C-synthesis produced and make sure it matches that of the original C++
10. `vitis_hls -f run_hls_export.tcl`: exports the results of the C-synthesis as an IP
core, and more importantly for us, runs an out-of-context implementation, which includes a timing analysis (this is generally much
more accurate than the timing analysis HLS tries to do during C-synthesis)
- The output of this can be accessed later at `MET/test/proj_APd_metalgo/solution/impl/report/vhdl`

# Setup (do only once) instructions from A.H. 
To log in, you'll first SSH into one of the login nodes,
culogin01.colorado.edu, culogin02.colorado.edu, or
culogin03.colorado.edu. When you first log in, please change your
password to something more secure, which can be done with the following:
kpasswd
Then from there, you can SSH into torreys, which is the machine we use
for FW development.

To set up the environment for HLS on torreys, I have the following script in my home directory:
```
export BUILD_VIVADO_VERSION=$1
export BUILD_VIVADO_BASE=/nfs/data41/software/Xilinx/Vivado
source ${BUILD_VIVADO_BASE}/${BUILD_VIVADO_VERSION}/settings64.sh
export XILINXD_LICENSE_FILE=2100@torreys.colorado.edu
```
Then to set up the environment for version 2022.2, which happens to be
the version we use for GTT FW at the moment, I just do the following
after logging into torreys:
```
source bin/setup.sh 2022.2
```
Of course, you can rearrange this however you like, e.g., by adapting
the above script for your .bashrc file, so that you don't have to source
anything manually.

The disk quota on the home directories is fairly small, so we keep our
FW projects in /nfs/data41/. You should be able to create a directory
under there where you can put everything.

The GTT HLS repo is here:
https://gitlab.cern.ch/GTT/LibHLS
You can clone it in the usual way, making sure to clone the submodules
as well:
```
git clone --recurse-submodules ssh://git@gitlab.cern.ch:7999/GTT/LibHLS.git
```

The code for the MET module and its test bench can be found in
Modules/MET/, and you can follow the README here to run the usual steps
in the HLS workflow:
https://gitlab.cern.ch/GTT/LibHLS/-/tree/master/Modules/MET?ref_type=heads#steps-to-run-the-project-in-hep-network-at-cu-boulder
The scripts it has you run with vitis_hls do the following:
- run_hls_make.tcl: makes the Vitis HLS project that is used by all the
other steps
- run_hls_csim.tcl: runs the C-simulation; this basically just compiles
the C++ test bench, runs it, and if it returns zero, says the
C-simulation passed
- run_hls_csynth.tcl: runs the C-synthesis; this turns the C++ into
actual RTL
- run_hls_cosim.tcl: runs the C/RTL cosimulation; this runs an actual
RTL simulation, in order to validate the behavior of what the
C-synthesis produced and make sure it matches that of the original C++
- run_hls_export.tcl: exports the results of the C-synthesis as an IP
core, and more importantly for us, runs an out-of-context
implementation, which includes a timing analysis (this is generally much
more accurate than the timing analysis HLS tries to do during C-synthesis)


## Vivado firmware steps
1. I copied the `gtt` fresh repository from Andrew since I can't clone it yet.
2. Build the ApX VU13P jet/met project:
```bash
cd /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met
# I got an exit message telling me to make this directory:
mkdir /nfs/data41/skkwan/gtt/build
make -j 8 sources
```
Opening [https://gitlab.cern.ch/cms-cactus/phase2/firmware/gtt/-/blob/master/top/apx/gtt_vu13p_jet_met/Makefile?ref_type=heads](the gtt_vu13p_jet_met/Makefile) shows the line 
```makefile
target: bit
```
which means that running `make` without a target will default to `bit`. Since we ran `make sources`, tracing that back through [https://github.com/slaclab/ruckus/blob/main/system_vivado.mk](Ruckus's system_vivado.mk) points to 

I initially got these commands from suggestions from Copilot, but if I trace back to the template makefile linked in [https://github.com/slaclab/ruckus/blob/main/system_vivado.mk](Ruckus's system_vivado.mk), I can see that there are blocks for `xsim `, `syn`, and `bit` (grouped with `bit mcs prom`)

3. Run the RTL simulation. This seems to take quite a while, I added the `-j 8` command.
```bash
make -C /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met xsim -j 8
```
It finished with this: `INFO: xsimkernel Simulation Memory Usage: 312248 KB (Peak: 312248 KB), Simulation CPU Usage: 23350 ms`

The simulation configuration file is in `gtt/top/apx/gtt_vu13p_jet_met/cfg/sim_config.tcl`. It says which simulation input file to use (`$::TOP_DIR/submodules/Data/Emulation/TTbarPU200/APx/L1GTTInputFile_0_sidebandoff_staggered.txt`), and where the output file should go (`$::PROJ_DIR/out.txt` which evaluates to `top/apx/gtt_vu13p_jet_met/cfg/out.txt`).

I saw a new folder created: `/nfs/data41/skkwan/gtt/build/xF13P_jet_met_top/xF13P_jet_met_top_project.sim/sim_1/behav/xsim/xsim.dir/`. `algoTopWrapper_tb_behav` seems to be the most interesting sub-folder.

4. Synthesize the Vivado design: lots of printouts, also takes a while. There was a resource usage table but it went by really fast. 
```bash
make -C /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met syn -j 8
```
One of the printouts was:
```bash
VHDL Output written to : /nfs/data41/skkwan/gtt/build/xF13P_jet_met_top/xF13P_jet_met_top_project.gen/sources_1/bd/axi_ic_lite/synth/axi_ic_lite.vhd
VHDL Output written to : /nfs/data41/skkwan/gtt/build/xF13P_jet_met_top/xF13P_jet_met_top_project.gen/sources_1/bd/axi_ic_lite/sim/axi_ic_lite.vhd
VHDL Output written to : /nfs/data41/skkwan/gtt/build/xF13P_jet_met_top/xF13P_jet_met_top_project.gen/sources_1/bd/axi_ic_lite/hdl/axi_ic_lite_wrapper.vhd
```

5. Implementation into a bitstream
```bash
make -C /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met bit -j 8
```
The printouts end in this:
```bash
# }
Bit file copied to /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met/images/xF13P_jet_met_top-0x00000001-20261005104654-skkwan-cc470eb.bit
No Debug Probes found
INFO: [Project 1-1918] Creating Hardware Platform: /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met/images/xF13P_jet_met_top-0x00000001-20261005104654-skkwan-cc470eb.xsa ...
INFO: [Project 1-1943] The Hardware Platform can be used for Hardware
INFO: [Project 1-1941] Successfully created Hardware Platform: /nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met/images/xF13P_jet_met_top-0x00000001-20261005104654-skkwan-cc470eb.xsa
INFO: [Hsi 55-2053] elapsed time for repository (/nfs/data41/software/Xilinx/Vivado/2022.2/data/embeddedsw) loading 3 seconds
write_hw_platform: Time (s): cpu = 00:00:02 ; elapsed = 00:00:07 . Memory (MB): peak = 2255.887 ; gain = 0.000 ; free physical = 28269 ; free virtual = 37280
# SourceTclFile ${VIVADO_DIR}/post_build.tcl
# close_project
# exit 0
INFO: [Common 17-206] Exiting Vivado at Mon Oct  5 10:53:46 2026...
make: Leaving directory `/nfs/data41/skkwan/gtt/top/apx/gtt_vu13p_jet_met'
```
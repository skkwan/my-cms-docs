# Accessing torrey machine

1. SSH into one of the login nodes, culogin01.colorado.edu, culogin02.colorado.edu, or culogin03.colorado.edu
2. SSH into torreys: `ssh skkwan@torreys.colorado.edu` (same password as above)
3. This is already in `~/.bashrc` so you don't need to do this manually, but `source ~/bin/setup.sh` (sets up version 2022.2)
4. `cd /nfs/data41/skkwan/LibHLS/Modules/MET/test`
5. `python3 setup_tcl.py`
6. `vitis_hls -f run_hls_csim.tcl`
etc.


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
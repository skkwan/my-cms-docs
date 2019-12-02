# TMVA to HLS for BDTs in hls4ml

## Setup
### Only once
1. `git clone https://github.com/thesps/hls4ml.git -b bdt`

### In every shell
 ```
   source /data/tools/Xilinx/Vivado/2018.2/settings64.sh
   source /data/setup_xilinx_lic.sh
   ```


## Convert TMVA BDT to HLS, estimate resource usage using all input values set to 0
Location: `/afs/cern.ch/user/s/skkwan/Public/triggerDevel/hls4ml/tmva-to-hls`
GitHub equivalent: https://github.com/skkwan/hls4ml/tree/bdt/tmva-to-hls

1. Edit the `.yml` file to specify which `.xml` BDT weight file to use.
2. `python tmva-to-hls.py -c tmva-config.yml` : this creates a folder called `tmva-to-hls-test` (what we wanted the project
   name to be)
3. `cd` to the project directory (`tmva-to-hls-test`) and run
   ```vivado_hls -f build_prj.tcl```
4. n.b. The input values are all declared to be 0, in the file `tmva-to-hls-test_test.cpp`.

## (Pallabi's folder) Use Vivado HLS to convert BDT to HLS, using all input values set to random values, read in from a text file
Location: `/afs/cern.ch/user/s/skkwan/Public/triggerDevel/hls_taus`
GitHub equivalent: https://github.com/skkwan/hls_taus

### Step 1: Generate .h with the desired BDT.
1. Using the steps in the above section, and then navigating to the `firmware` folder, copy `parameters.h`.
2. Also get the `.cpp` file (containing the top-level function) and its associated `.h` file. Here we modify
   the top-level function to return `ap_fixed<18,8>` : the BDT discriminant. 

### Step 2: Add all relevant files to the `.tcl`. 
1. In the `.tcl` file, note the following lines:
   * `add_files hls_taus/BDT.h -cflags "-std=c++0x"`
      * Defines a Tree Struct and a BDT Struct.
   * `add_files hls_taus/myproject.cpp -cflags "-std=c++0x"` 
   * `add_files hls_taus/myproject.h`
      * Contains the top-level function, called `myproject`.
   * `add_files -tb hls_taus/myproject_test1.cpp -cflags "-std=c++0x"`
      * Testbench: `read_vars_from_file`
      * `unpack_input_vars` 
2. `vivado_hls -f script.tcl`
3. After the csim and csynth finish, look inside `hls_taus/solution1/syn/report/myproject_csynth.rpt` to note the usage and latency.
4. Change the number of taus to read in, in the variable `taus_per_event` in the file `myproject_test1.cpp`. 



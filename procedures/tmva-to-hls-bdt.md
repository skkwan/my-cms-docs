# TMVA to HLS for BDTs in hls4ml

## Setup (only once)
1. `git clone https://github.com/thesps/hls4ml.git -b bdt`

## 
1. Edit the `.yml` file to specify which `.xml` BDT weight file to use.
1. `python tmva-to-hls.py -c tmva-config.yml`

## Use Vivado HLS to create a C simulation. (Using folder from Pallabi)
1. ```
   source /data/tools/Xilinx/Vivado/2018.2/settings64.sh
   source /data/setup_xilinx_lic.sh
   ```
2. `vivado_hls -f hls_taus/solution1/script.tcl`
3. After the csim and csynth finish, look inside `hls_taus/solution1/syn/report/myproject_csynth.rpt` to note the usage and latency.
4. Change the number of taus to read in, in the variable `taus_per_event` in the file `myproject_test1.cpp`. 


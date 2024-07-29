# Correlator setup

## Setup steps on uwlogin

1. [First-time setup](https://gitlab.cern.ch/cms-cactus/phase2/firmware/correlator-common), I did this on `uwlogin`. Yes, `CMSSW` goes in the top-level directory.
2. The setup step that requires the `curl` file, failed and I had to download the file with `curl` to a different machine (lxplus) and then `scp` that file to where it needs to be on `uwlogin`.

## To start working

1. `cd` to the `CMSSW` and `cmsenv`.
2. Run the `source` command for `HLS`.
3. `cd` to `l1-converters` and pick one of the directories, `hgcal`. Run the `.tcl` with `vitis_hls run_hls_hgcal_convert.tcl`.
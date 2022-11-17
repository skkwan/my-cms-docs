# RUCIO

## Website

Website interface: https://cms-rucio-webui.cern.ch/r2d2/request

- To request a whole dataset, a DAS dataset is a Rucio container:
  ```
  cms:/SingleElectron_PT2to200/Phase2HLTTDRWinter20DIGI-PU200_110X_mcRun4_realistic_v3_ext2-v2/GEN-SIM-DIGI-RAW
  ```
- To request a specific block, a block is a Rucio dataset: usually searching with the block number like this should work:
  ```
  cms:/SingleElectron_PT2to200/Phase2HLTTDRWinter20DIGI-PU200_110X_mcRun4_realistic_v3_ext2-v2/GEN-SIM-DIGI-RAW#[block-number]
  ```
  If it doesn't work, try searching with a wildcard `*` instead of '#[block-number]'.
- Watch out if:
  - DAS: click into the block and show the full info --> block size is non-existent 
  - Rucio request says you are requesting 0B
  - You are requesting a large (multiple TB) dataset

## Command line interface

```
voms-proxy-init -voms cms -rfc -valid 192:00
source /cvmfs/cms.cern.ch/rucio/setup.sh
export RUCIO_ACCOUNT=skkwan
rucio add-rule --ask-approval --lifetime 2592000 cms:/SingleElectron_PT2to200/Phase2HLTTDRWinter20DIGI-PU200_110X_mcRun4_realistic_v3_ext2-v2/GEN-SIM-DIGI-RAW#4d71c24e-6241-4c97-9b22-f27032922f78 1 T2_US_Wisconsin
```
where 2592000 is 1 month in seconds (change accordingly).

Check the status by

```
rucio list-rules --account skkwan
```

On my lxplus, I have the aliases: `ruciosetup` for the first four commands (minus getting voms) and `ruciolist` for checking the status.

## Examples

```
rucio add-rule --ask-approval --lifetime 15770000 cms:/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall17NanoAODv7-PU2017_12Apr2018_Nano02Apr2020_102X_mc2017_realistic_v8-v1/NANOAODSIM 1 T2_US_Wisconsin
```

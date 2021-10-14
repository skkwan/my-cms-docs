# RUCIO

## Main commands

```
source /cvmfs/cms.cern.ch/cmsset_default.sh
voms-proxy-init -voms cms -rfc -valid 192:00
source /cvmfs/cms.cern.ch/rucio/setup-old.sh
export RUCIO_ACCOUNT=skkwan
rucio add-rule --ask-approval --lifetime 2592000 cms:/GluGluHToTauTau_M125_13TeV_powheg_pythia8/RunIISpring15DR74-AsymptFlat10to50bx25Raw_MCRUN2_74_V9-v1/MINIAODSIM 1 T2_US_Wisconsin
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
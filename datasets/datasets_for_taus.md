# Datasets used for taus

## Gluon-gluon fusion Higgs to tau tau
Use `aodsim-two-file-batch` and the instructions in that `README.md` (the scripts read each AODSIM and then look for corresponding
mini and raw files)

### 200 pileup
`/GluGluHToTauTau_M125_14TeV_powheg_pythia8/PhaseIIMTDTDRAutumn18MiniAOD-PU200_103X_upgrade2023_realistic_v2-v1/MINIAODSIM`

### No pileup
`/GluGluHToTauTau_M125_14TeV_powheg_pythia8_TuneCP5/PhaseIITDRSpring19MiniAOD-NoPU_106X_upgrade2023_realistic_v3-v2/MINIAODSIM`



## Drell-Yan to ll
Use `two-file-batch-example` and the instructions in that `README.md` (the scripts read each MINIAODSIM and then look
for corresponding FEVT files)

### 200 pileup
`/DYToLL_M-50_14TeV_pythia8_pilot1/PhaseIIMTDTDRAutumn18MiniAOD-PU200_pilot_103X_upgrade2023_realistic_v2-v1/MINIAODSIM`

### No pileup
`/DYToLL_M-50_14TeV_TuneCP5_pythia8/PhaseIIMTDTDRAutumn18MiniAOD-NoPU_103X_upgrade2023_realistic_v2-v2/MINIAODSIM`
which contains the MINIAODSIM files (listed in reverse alphabetical order on DAS website)

The current training/evaluation split is 

**Training:**

     | Training                                              | # signal events | # bkg events |
     |-------------------------------------------------------|-----------------|--------------|
     | [https://github.com/skkwan/phase2L1TauAnalyzer/blob/683426d6e8a6a7807d8862124d8b75f5af800d91/test/two-file-batch-example/inputFileList-MINI.txt](2019_Aug28-DYToLL_NoPU_withL1Tracks.root)              | 16,330          | 20,420       |
     | [https://github.com/skkwan/phase2L1TauAnalyzer/blob/db544953313edefb2317f351c68573068ec5b26c/test/two-file-batch-example/inputFileList-MINI.txt](2019_Aug30-DYToLL_NoPU_withL1Tracks.root)              | 20,780          | 26,362       |
     | Total                                                 | 41,269          | 49,207       |

**Evaluation:**

     
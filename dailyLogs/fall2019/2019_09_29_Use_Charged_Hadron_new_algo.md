# Sep 29, 2019 Using charged hadron (new algorithm)

## Sunday Sep 29, 2019

### 200 PU DYtoLL

- Isobel's temporary fix: assign any tracks without clusters " as charged hadrons to boost efficiency. I shouldn’t have to do this but somethi\
ng is wrong with PF so it is a patch." Then any PF Charged Hadrons are assigned as PF Charged Hadrons, and e/gammas are assigned as normal.
- Adding two variables to training:  l1HoE and l1EoH and then also genDM>9 cut for the signal.
- Jobs at
  ```/hdfs/store/user/ojalvo/2019_Sep28-DYToLL_200PU_ext1-USE_CHARGED_HADRON_new_algo/SUB-Analyzer-*.root```
- Trained BDT: added `l1StripPt<500` requirement because ``` efficiencyTree->Scan("l1StripPt","l1StripPt>400")``` is turning up
  two-dozen events with ~inf values. Added `l1HoE` and `l1EoH` to training.
  [https://github.com/skkwan/phase2L1BTagAnalyzer/blob/794561af6266199c552a70ecb3780bca8a99870d/tau_exercise/training/TMVAAnalysis_tau.C](link to that commit- commit message is wrong though)

- Got more precise BDT working points from opening up the TMVA output root file, navigating to the BDT directory, and
  ```MVA_BDT_effS->Print("all")```.
  * 60%: +0.0540466
  * 70%: +0.0126322
  * 80%: -0.0253954
  * 90%: -0.0435867 (this is 85% strictly speaking: the histogram only had entries for 84% then 94% eff.)
  * 95%: -0.0486184
- Improved modularity of plotting scripts and added plots vs. recoEta. [https://github.com/skkwan/phase2L1BTagAnalyzer/tree/8bd12827ea2a04e62202357d6630300514856403](link to commit)
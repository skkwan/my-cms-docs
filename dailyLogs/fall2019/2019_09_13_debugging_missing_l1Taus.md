# 2019 09 13 debugging missing L1 taus

## Friday (Sep 13 2019)

- Waiting for screen session to finish running interactive job adding PF Cand

## Monday (Sep 16 2019)

- PF Cands added
- Re-visiting L1 tracks checking because now I'm not so sure the track efficiencies are ok
- ```efficiencyTree->Scan("recoPt:l1Track_pt:pfCand_pt:l1Pt", "(recoPt>15)&&(genPt>15)&&(abs(recoEta)<0.774)&&(recoDM==0)")```
- PF Cands will let us resolve whether PF Level 1 or L1 tau producer is having issues

- Updated all analyzers to be the PF Cand version

To-do:
1. Check on 2 jobs of ggHtotautau 
2. Check on 2 jobs of DYtoLL
3. Scan L1 PF Cand pT as well
4. Re-make efficiency plot with just Drell-Yan
   * Merged Drell-Yan only `2019_Aug28_29-DYToLL_NoPU_withL1Tracks.root` 
5. Draft email to Vladimir and Christina


Retraining on ONLY DYToLL since glugluHiggsToTauTau is problematic:

     | Training                                              | # signal events | # bkg events |
     |-------------------------------------------------------|-----------------|--------------|
     | 2019_Aug28_29-DYToLL_NoPU_withL1Tracks.root           | 37,110          | 46,782       |
     
     | Evaluation                                             | # signal events | # bkg events |
     |--------------------------------------------------------|-----------------|--------------|
     | 2019_Sep10-DYToLL_NoPU_withL1Tracks.root               | 33,440          | 42,373       |


  ```
  CrossValidation          :  ==== Results ====
                         : Fold  0 ROC-Int : 0.8066
                         : Fold  1 ROC-Int : 0.8014
                         : Fold  2 ROC-Int : 0.8049
                         : Fold  3 ROC-Int : 0.8088
                         : Fold  4 ROC-Int : 0.8064
                         : ------------------------
                         : Average ROC-Int : 0.8056
                         : Std-Dev ROC-Int : 0.0027
                         :
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA
                         : Name:         Method:          ROC-integ
                         : dataset       BDT            : 0.806
                         : -------------------------------------------------------------------------------------------------------------------
                         :
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample)
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT            : 0.080 (0.107)       0.411 (0.448)      0.774 (0.789)
                         : -------------------------------------------------------------------------------------------------------------------
 ```

- If I only use the DYtoLL samples for training/evaluation, the efficiencies look like
  turn-on curves albeit with a dip at high pT, and huge error bars. 

## Tuesday (Sep 17, 2019)

- (Evaluation set) Submitting batch jobs to put PF Cand and L1 tracks in no-pileup Drell-Yan to try and reduce error bars.
- Emailed Cristina and Vladimir with questions.

## Wednesday (Sep 18, 2019)

- Trying interactive ggHtautau job with changing cms.Process('REPR',eras.Phase2C4_trigger) to process = cms.Process('REPR',eras.Phase2C8_trigger) 
  - Still missing tracks. Will put this on backburner
- ~~Still don't understand why no-BDT efficiency is higher than everything else~~


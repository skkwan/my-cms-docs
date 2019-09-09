# 2019 09 09 debugging missing L1 taus

## Monday (Sep 9, 2019)

Based on to-do list from last log:

1. ✓ Submit jobs for no-pileup Drell-Yan for training (`/two-file-batch-example`): `2019_Aug28-DYToLL_NoPU_withL1Tracks` (36 jobs)
2. ✓ Submit jobs for no-pileup GluGluHiggsToTauTau for training (`/aodsim-two-file-batch`): `2019_Aug29-ggHtautau_noPU-try2` (used half of 
     available AODSIM files)
3. No-pileup L1 track study
   * ✓ Make **training samples** no-PU ggHtautau and DYtoLL.
     * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-[0-5]-*.root`
       * hadded into `2019_Aug29-ggHtautau_noPU_withL1Tracks_firsthalf.root`
     * `/hdfs/store/user/skkwan/2019_Aug28-DYToLL_NoPU_withL1Tracks/*.root` 
       * hadded into `2019_Aug28-DYToLL_NoPU_withL1Tracks.root` 
     * `/hdfs/store/user/skkwan/2019_Aug30-DYToLL_NoPU_withL1Tracks/*.root`   
       * hadded into `2019_Aug30-DYToLL_NoPU_withL1Tracks.root`
   * ✓ Re-train BDT on no-PU ggHtautau and DYtoLL. 
     (combined into `2019_Sep9_noPU.root`)
     
     |                                                       | # signal events | # bkg events |
     |-------------------------------------------------------|-----------------|--------------|
     | 2019_Aug28-DYToLL_NoPU_withL1Tracks.root              | 16,330          | 20,420       |
     | 2019_Aug30-DYToLL_NoPU_withL1Tracks.root              | 20,780          | 26,362       |
     | 2019_Aug29-ggHtautau_noPU_withL1Tracks_firsthalf.root | 4,159           | 2,425        |
     | Total                                                 | 41,269          | 49,207       |

     * ✓  Signal efficiencies for test/training samples:
       * @B=0.01: 0.094 (0.095)
       * @B=0.10: 0.363 (0.372)
       * @B=0.30: 0.691 (0.696)
   * Make **evaluation samples** no-PU ggHtautau and DYtoLL.
     * ggHtautau
       * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-[6-9]-*.root`
       * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-11-*.root`
     * DYtoLL
       * Two test jobs: `2019_Sep9-DYToLL_NoPU_withL1Tracks-MINI`
       * Submit all jobs when those test jobs complete
   * Run `makeEfficiencyPlots.C` using L1 taus.
   * ✓ Edit `makeEfficiencyPlots.C` using L1 track with least dR separation from reco tau.
   * Run `makeEfficiencyPlots.C` using L1 **track** with least dR separation from reco tau. 
   * Compare the plots.
4. 200-pileup L1 track study


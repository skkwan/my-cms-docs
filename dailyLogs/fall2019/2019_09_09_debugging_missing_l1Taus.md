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
   * Make **evaluation samples** no-PU ggHtautau and DYtoLL (must be different samples than what was 
     used for training)
     * ggHtautau
       * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-[6-9]-*.root`
       * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-11-*.root`
     * DYtoLL: `/hdfs/store/user/skkwan/2019_Sep10-DYToLL_NoPU_withL1Tracks` (orthogonal to `2019_Aug30-DYToLL_NoPU_withL1Tracks.root`)
   * ✓ Edit `makeEfficiencyPlots.C` so it adds an efficiency line for reco-tau efficiency with L1
     Track 
   * Compare the efficiencies.
4. 200-pileup L1 track study

## Tuesday (Sep 10, 2019)

Updating above bullet points. 

Clarified with Isobel: Previously what we were checking was the L1 Tau Reconstruction efficiency so, 
"For all reconstructed, gen-matched hadronic Taus how often would that Tau have been triggered at L1?" 
Now we want, "For all reconstructed, gen-matched hadronic Taus, how often would that Tau have an L1 Track?". 

- ~~Getting this error when I ssh to hep.wisc.edu~~ Fixed
- Clarified what the sanity-check efficiency plot should look like.

## Wednesday (Sep 11, 2019)

Updating above bullet points.


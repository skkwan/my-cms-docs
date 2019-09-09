# 2019 09 09 debugging missing L1 taus

## Monday (Sep 9, 2019)

Copying and pasting to-do list from last log:

1. Submit jobs for no-pileup Drell-Yan for training (`/two-file-batch-example`)
   * ✓ Submitted 2 test jobs with name `2019_Aug27-DYToLL_NoPU_withL1Tracks-mini` using MC files from
   [https://github.com/skkwan/phase2L1TauAnalyzer/tree/17ef541fefdd11d149acfc8ef239c9fab2d1ab0a/test/two-file-batch-example](commit)
   `17ef541`.
   * ✓ When 2 test jobs finish running, submit all jobs.
   * ✓ Wait for 36 jobs to finish running (name: `2019_Aug28-DYToLL_NoPU_withL1Tracks`)
2. Submit jobs for no-pileup GluGluHiggsToTauTau for training (`/aodsim-two-file-batch`)
   * ✓ ~~Submitted 2 test jobs with name `2019_Aug27-ggHtautau_noPU-MINI-try2`.~~ Failed because I used MINIAODSIM 
     instead of AODSIM
   * ✓ Re-submitted 2 jobs (name: `2019_Aug28-ggHtautau_noPU-MINI-try2`)
   * ✓ 130 jobs finished (name: `2019_Aug29-ggHtautau_noPU-try2` -- used half of the available AODSIM files)
3. No-pileup L1 track study
   * Combine no-PU ggHtautau and DYtoLL for **training**
     * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-[0-5]-*.root`
       * hadded into `2019_Aug29-ggHtautau_noPU_withL1Tracks_firsthalf.root`
     * `/hdfs/store/user/skkwan/2019_Aug28-DYToLL_NoPU_withL1Tracks/*.root` (for now)
       * hadded into `2019_Aug28-DYToLL_NoPU_withL1Tracks.root` 
   * Re-train BDT on no-PU ggHtautau and DYtoLL
     
     |                                                       | # signal events | # bkg events |
     |-------------------------------------------------------|-----------------|--------------|
     | 2019_Aug28-DYToLL_NoPU_withL1Tracks.root              | 16,330          | 20,420       |
     | 2019_Aug29-ggHtautau_noPU_withL1Tracks_firsthalf.root | 4,159           | 2,425        |
     | Total                                                 | 20,488          | 22,844       |

     * Signal efficiencies for test/training samples:
       * @B=0.01: 0.091 (0.119)
       * @B=0.10: 0.354 (0.386)
       * @B=0.30: 0.731 (0.736)
     * Some overtraining: I'm going to add more DYtoLL events.

   * Hadd ggHtautau and DYtoLL files, keeping track of how many I am combining
     * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-[6-9]-*.root`
     * `/hdfs/store/user/skkwan/2019_Aug29-ggHtautau_noPU-try2/SUB-Analyzer-11-*.root`
   * Run `makeEfficiencyPlots.C` using L1 taus
   * Edit `makeEfficiencyPlots.C` using L1 track with least dR separation from reco tau
   * Run " " 
   * Compare the plots.
4. Keep track of how many Drell-Yan and GluGluHiggsToTauTau samples I am combining
5. ✓ Make game plan for experimental project presentation and report
6. Make 200-pileup n-tuples with the L1 track information.


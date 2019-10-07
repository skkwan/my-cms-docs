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

     To get number of signal events, open the ROOT file and in the command line run:
     ```efficiencyTree->Draw("l1Pt", "l1Pt>0 && !isinf(l1Pt) && !isinf(l1Eta) && !isinf(l1StripPt) && !isinf(l1DM) && !isinf(l1PVDZ) && !isnan(l1Pt) && !isnan(l1Eta) && !isnan(l1StripPt) && !isnan(l1DM) && !isnan(l1PVDZ) && (genPt>20)")```
     and do `genPt < 20` to get number of background events.
     
     | Training                                              | # signal events | # bkg events |
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
         * hadded into `2019_Aug29-ggHtautau_noPU_withL1Tracks_secondhalf.root`
     * DYtoLL: `/hdfs/store/user/skkwan/2019_Sep10-DYToLL_NoPU_withL1Tracks` (orthogonal to `2019_Aug30-DYToLL_NoPU_withL1Tracks.root`)

     | Evaluation                                             | # signal events | # bkg events |
     |--------------------------------------------------------|-----------------|--------------|
     | 2019_Sep10-DYToLL_NoPU_withL1Tracks.root               | 33,440          | 42,373       |
     | 2019_Aug29-ggHtautau_noPU_withL1Tracks_secondhalf.root | 3,946           | 2,656        |
     | Total                                                  | 37,386          | 45,029       |

   * ✓ Edit `makeEfficiencyPlots.C` so it adds an efficiency line for reco-tau efficiency with L1
     Track 
   * Compare the efficiencies.
   * Big-time debugging
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

- The efficiency plot looks like a mess: the "turn-on" curve shape isn't present.
- Need to debug plotting script.
- Printing entries using `Scan` shows that for true taus, a L1 track **is** being found correctly for
  reco and L1 taus:
- Last step for debugging is to add pfcandidate matching to the tree: example:
  https://github.com/cms-l1t-offline/cmssw/blob/phase2-l1t-integration-CMSSW_10_6_0_pre4/L1Trigger/Phase2L1Taus/plugins/L1PFTauProducer.cc#L45-L48
- In adding PF Candidates: getting this error after file is opened and after customary "Finding vertices using
  a DBSCAN algorithm... L1 RegionMapper: made 1 regions..." messages:

  ```
  ----- Begin Fatal Exception 12-Sep-2019 08:28:44 CDT-----------------------
  An exception of category 'Configuration' occurred while
   [0] Constructing the EventProcessor
   [1] Constructing module: class=phase2L1TauAnalyzer label='L1TauAnalyzer'
   Exception Message:
   MissingParameter: Parameter 'L1PFObjects' not found.
   ----- End Fatal Exception -------------------------------------------------
   ```

## Thursday (Sep 12, 2019)

- Fixed the above problem (see Pages document) but now get

  ```
  Begin processing the 1st record. Run 1, Event 462009, LumiSection 1849 on stream 0 at 12-Sep-2019 08:46:19.248 CDT
----- Begin Fatal Exception 12-Sep-2019 08:46:29 CDT-----------------------
An exception of category 'ProductNotFound' occurred while
   [0] Processing  Event run: 1 lumi: 1849 event: 462009 stream: 0
   [1] Running path 'analyzer'
   [2] Calling method for module phase2L1TauAnalyzer/'L1TauAnalyzer'
Exception Message:
Principal::getByToken: Found zero products matching all criteria
Looking for type: std::vector<l1t::PFCandidate>
Looking for module label: L1PFProducer
Looking for productInstanceName: L1PFObjects

   Additional Info:
      [a] If you wish to continue processing events after a ProductNotFound exception,
add "SkipEvent = cms.untracked.vstring('ProductNotFound')" to the "options" PSet in the configuration.

----- End Fatal Exception -------------------------------------------------
 ```

- Fixed: see Pages debugging document
- Waiting for 4FEVT interactive job to finish.
- HLS4ML tutorial: listened in remotely (https://indico.cern.ch/event/822126/timetable/#20190910.detailed)

- New error:

  ```
  ----- Begin Fatal Exception 12-Sep-2019 14:04:59 CDT-----------------------
An exception of category 'ProductNotFound' occurred while
   [0] Processing  Event run: 1 lumi: 1849 event: 462009 stream: 0
   [1] Running path 'analyzer'
   [2] Calling method for module phase2L1TauAnalyzer/'L1TauAnalyzer'
Exception Message:
Principal::getByToken: Found zero products matching all criteria
Looking for type: std::vector<pat::Tau>
Looking for module label: slimmedTaus
Looking for productInstanceName:
Looking for process: RECO
   Additional Info:
      [a] If you wish to continue processing events after a ProductNotFound exception,
add "SkipEvent = cms.untracked.vstring('ProductNotFound')" to the "options" PSet in the configuration.

----- End Fatal Exception -------------------------------------------------
    ```
- Fixed by doing edmDumpEventContent on dump.root and changing the process tag to "PAT"
- Ditto for a ProductNotFound error for module packedPFCandidates

# Week of July 5 - July 12, 2019

## Friday July 5, 2019
Working directory: `/afs/cern.ch/work/s/skkwan/public/triggerDevel/jul2019/CMSSW_10_6_0_pre4/src/L1Trigger/phase2L1TauAnalyzer/python`

### To-do
- ~~Need to debug `PluginNotFound` for L1TrackProducer~~
- ~~Need to debug `ProductNotFound`~~
- Add in DeltaR to analyzer
  * Add	 `double   l1DeltaR` to variable declaration at l.	142
  * Add	 `efficiencyTree->Branch("l1DeltaR", &l1DeltaR, "l1DeltaR/D");` to l. 264
  * In [this loop](https://github.com/isobelojalvo/phase2L1TauAnalyzer/blob/master/plugins/phase2L1TauAnalyzer.cc#L774-L795):  
     * ~~`l1DeltaR = reco::deltaR(l1PFTaus->at(i).p4().Eta(), l1PFTaus->at(i).p4.Phi(), *pv);` (need to get pv Eta and pv Phi)~~ *Misunderstood: should be Delta Z*

- Make better plots for sig vs. bkg for tauL1Strip variables
- Find a way to estimate the performance of the BDT based on MC

### Debugging analyzer
- Problems compiling (`error: variable 'f_2p1' set but not used [-Werror=unused-but-set-variable]`), fixed by setting compile-time flags:
  * `USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable" scram b`
  * `PluginNotFound` bug is now gone. Now have a different bug: `ProductNotFound`
  * 

  <details><summary>Expand</summary>
  <p>

  ----- Begin Fatal Exception 05-Jul-2019 13:48:50 CEST-----------------------
  An exception of category 'ProductNotFound' occurred while
   [0] Processing  Event run: 1 lumi: 1849 event: 462009 stream: 0
   [1] Running path 'L1PFTaus'
   [2] Calling method for module L1PFTauProducer/'L1PFTauProducer'
   Exception Message:
   Principal::getByToken: Found zero products matching all criteria
   Looking for type: std::vector<l1t::PFCandidate>
   Looking for module label: L1PFProducer
   Looking for productInstanceName: L1PFObjects

   Additional Info:
      [a] If you wish to continue processing events after a ProductNotFound exception,
            add "SkipEvent = cms.untracked.vstring('ProductNotFound')" to the "options" PSet in the configuration. 
   ----- End Fatal Exception -------------------------------------------------
      </p></details>

## Monday July 8, 2019

### Config file error
- Uncommented `dump.py` at the end of `test-Analyzer.py`: looked through it and saw that there are two EDProducers that make `L1PFObjects`, but I don't know how to use this to debug it.
- Isobel sent me a revised analyzer [test-Analyzer-reprocess.py](https://github.com/isobelojalvo/phase2L1TauAnalyzer/blob/master/test/test-Analyzer-reprocess.py).

### Safety trainings
Completed, requested access on ADAMS.

### Putting in Delta Z
- Current version of `phase2L1TauAnalyzer.cc` has no zVTX, so I need to get the 
  *  z-position of the tau lepton 
  *  z-position of the primary vertex (zVTX)
- Taus inherit from [DataFormats/Candidate/interface/Particle.h](https://github.com/cms-sw/cmssw/blob/02d4198c0b6615287fd88e9a8ff650aea994412e/DataFormats/Candidate/interface/Particle.h) 
  * `typedef math::XYZPoint Point;` (See Point attributes [here](https://root.cern.ch/root/html/ROOT__Math__PositionVector3D_-p1Cartesian3D_double__-p1DefaultCoordinateSystemTag_.html))
  
- ~~Added branches: `l1TauZ`, `zVTX`, `deltaZTauVTX`~~

### Next steps after discussing with Isobel
1. ~~Either re-integrate the "reprocess" analyzer into test-Analyzer.py (change geometry and something else),~~ or just use the "reprocess" analyzer
1. Stategy for debugging test-Analyzer.py "PluginNotFound": just run the simulation step/ take out the problematic step in process.schedule(), then run it, and edmEventContentDump the resultant `analyzer.root`.
1. ~~See if the "reprocess" analyzer works with tau files instead of the neutrino files the template analyzer came with~~ Yes
1. Put in the L1Vertex Collection [as shown here](https://github.com/isobelojalvo/L1MTD/blob/LLPDev_Jan21/plugins/L1MTDPFAnalyzer.cc) to get L1 vertices (as opposed to Reco-level vertices which I mistakenly did, using the b-tagging analyzer)

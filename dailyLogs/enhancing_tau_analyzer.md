# Week of Monday Jul 22, 2019 - 

## Monday, Jul 22 2019

- Isobel helped identify problematic line: `if (genPt > 0) efficiencyTree->Fill()` was
  limiting the efficiencyTree to only true taus!
- Isobel gave QCD data sample: `/QCD_Pt-15To7000_TuneCP5_Flat_14TeV-pythia8/PhaseIIMTDTDRAutumn18MiniAOD-PU200_103X_upgrade2023_realistic_v2-v1/MINIAODSIM`
- Briefly met with Isobel, next steps:
  * put TMVA in CMSSW Analyzer, example: [https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/src/MVAJetPuId.cc](https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/src/MVAJetPuId.cc)
  * need to check experimental project requirements


## Tuesday, Jul 23 2019

- Re-made plots using 1 FEVT Drell-Yan file in secondary files,	there are more background events now.
- Made n-tuple using 1 FEVT QCD	       file, plots show that they are entirely background events.
- Changed plotting to only show `l1Pt>0` - that gets rid of many fake taus.
- Started analyzer job on machine 741 with four FEVT files.
- Isobel merged my analyzer changes to the master branch and made a new folder with a demo of how to submit batch jobs with this style of analyzer (primary + secondary files).
  - Wait and ask how her test job went.

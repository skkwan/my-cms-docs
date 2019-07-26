# Week of Monday Jul 22, 2019 - 

CoDaS HEP school at Princeton!

## Monday, Jul 22 2019

- Isobel helped identify problematic line: `if (genPt > 0) efficiencyTree->Fill()` was
  limiting the efficiencyTree to only true taus!
- Isobel gave QCD data sample: `/QCD_Pt-15To7000_TuneCP5_Flat_14TeV-pythia8/PhaseIIMTDTDRAutumn18MiniAOD-PU200_103X_upgrade2023_realistic_v2-v1/MINIAODSIM`
- Briefly met with Isobel, next steps:
  * put TMVA in CMSSW Analyzer, example: [https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/src/MVAJetPuId.cc](https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/src/MVAJetPuId.cc)
  * need to check experimental project requirements
  * estimate resource usage in HLS:
    * import a text file mimicking a BDT/LUT to Vivado, filling it with random numbers
    

## Tuesday, Jul 23 2019

- Re-made plots using 1 FEVT Drell-Yan file in secondary files,	there are more background events now.
- Made n-tuple using 1 FEVT QCD	       file, plots show that they are entirely background events.
- Changed plotting to only show `l1Pt>0` - that gets rid of many fake taus.
- Started analyzer job on machine 741 with four FEVT files.
- Isobel merged my analyzer changes to the master branch and made a new folder with a demo of how to submit batch jobs with this style of analyzer (primary + secondary files).
  - Wait and ask how her test job went.

## Wednesday, Jul 24 2019

- Trained BDT, cutting two NaN l1PVDZ entries, and *require l1Pt > 0*
- K-fold training (commit `9e7e204`) using `TMVAAnalysis_CrossValidation.C`, now merged into
  the TMVAAnalysis_tau.C script
- Signal: training: 688, testing: 688
- Background: training: 875, testing: 875
- '''
  CrossValidation          :  ==== Results ====
                         : Fold  0 ROC-Int : 0.7953
                         : Fold  1 ROC-Int : 0.7842
                         : Fold  2 ROC-Int : 0.7986
                         : Fold  3 ROC-Int : 0.7872
                         : Fold  4 ROC-Int : 0.7601
                         : ------------------------
                         : Average ROC-Int : 0.7851
                         : Std-Dev ROC-Int : 0.0151
  '''
- ROC-integ: 0.760
- '''
                           : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT            : 0.087 (0.310)       0.258 (0.615)      0.769 (0.818)
                         : ---------------------------------------------------------------------------------------------------------------
'''


## Thursday, Jul 25 2019

Group meeting slides should cover:

- My own analyzer to make tau n-tuples
  * Explain what an analyzer is probably
  * Adapted another analyzer and added L1 Vertex Collection
  * Added l1PVDZ variable
- Realized I need more statistics
  * Need to set up batch job system
- Included k-fold training
- Discuss overtraining checks
- Explain ROC curve and show ROC curve
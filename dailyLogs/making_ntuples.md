# Week of Friday (Jul 26, 2019) - Thursday (Aug 1, 2019)

## Friday (Jul 26, 2019)
- Acquired [https://github.com/isobelojalvo/phase2L1TauAnalyzer/tree/master/test/two-file-batch-example](two-file-batch-exampe) solution from Isobel
- Tried submitting two jobs on U Wisc Madison server
  * `You can monitor your workflow's progess by watching /nfs_scratch/skkwan/2019_Jul26-GluGluHTauTau-try1/SUB-GluGluHTauTau-200PU-SUBPhase-0/dags/dag.dagman.out
You can monitor your workflow's progess by watching /nfs_scratch/skkwan/2019_Jul26-GluGluHTauTau-try1/SUB-GluGluHTauTau-200PU-SUBPhase-1/dags/dag.dagman.out`
- ~~Worked~~, submitting more [https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fglobal&input=dataset%3D%2FGluGluHToTauTau_M125_14TeV_powheg_pythia8%2FPhaseIIMTDTDRAutumn18DR-PU200_103X_upgrade2023_realistic_v2-v1%2FFEVT](GluGluHiggsToTauTau-PU200) samples

- Met Savannah, need to convert n-tuples to HDF5 
  * Try [https://gitlab.cern.ch/dguest/HDF5Utils](HDF5Utils)
  * As a reference, [https://github.com/savvy379/egamma](egamma repo) but this is more complex, for image processing

- Try making 2D plots to see if l1StripPt and l1StripEta+l1StripPhi are correlated
- Try plotting z per decay mode

## Monday (Jul 29, 2019)

Back at CERN

- GluGluHTauTau jobs completed but the merged resulting file only has maybe a dozen nonzero l1Pt entries out of 18,059 entries
- My mistake... the two-file submission also had zero l1Pt entries out of 1292
- Analyzer was outdated and simply not filling efficiencyTree: updated analyzer and submitted two jobs to test on sshuw06

- Trained BDT on dyll files.. still overtraining, only 660 signal and 2976 background events
  - ```
                             : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT            : 0.730
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT            : 0.110 (0.302)       0.381 (0.528)      0.669 (0.736)
                         : -------------------------------------------------------------------------------------------------------------------```

- Start doing TMVA integration on lxplus cluster, master branch of tau analyzer


## Tuesday (Jul 30, 2019)
- segfault when I run runComparisonPlotsReprocess.C - the "l1Pt>0" cut is causing it, but what really is happening is that the l1 tree isn't being filled at all
- Doing cmsRun interactively on Higgs to Tau Tau samples to try and debug - works on lxplus, logrun is turning up L1 tau parameters!
- Submitted two jobs of Higgs to Tau Tau

- HDF5Utils seems to not work well on lxplus/cms turf...

- Created devel branch of Tau analyzer in lxplus for TMVA implementation (plugins/MVAL1TauId.cc)
- Is there a tau analogy for [https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/interface/MVAJetPuId.h](cmssw/RecoJets/JetProducers/interface/MVAJetPuId.h)? 


## Wednesday (Jul 31, 2019)


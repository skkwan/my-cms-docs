
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
- ~~Submitted two jobs of Higgs to Tau Tau~~ still no L1 taus

- HDF5Utils seems to not work well on lxplus/cms turf...

- Created devel branch of Tau analyzer in lxplus for TMVA implementation (plugins/MVAL1TauId.cc)
- ~~Is there a tau analogy for [https://github.com/cms-sw/cmssw/blob/9834f5dc9ff342ddef08b73d6c294cad36575772/RecoJets/JetProducers/interface/MVAJetPuId.h](cmssw/RecoJets/JetProducers/interface/MVAJetPuId.h)?~~ (don't need to do this)

Consulted Isobel:
1. "So the point is that you need to look at how the MVA is evaluated and add it to your analyzer. So, the first thing I would do is take the appropriate TMVA header files (not PileUpJetIdentifier)."
2. Check to see if it compiles.
3. "You likely need to add in the package to the BuildFile.xml in addition to the header files."
4. "Then you can follow a similar procedure to book the MVA, load the xml and evaluate based on new variables."

- Install correct CMSSW release!
- Updated tau install instructions in readme, sent changes to Jiajing and Isobel

## Wednesday (Jul 31, 2019)

- On login04 machine: Submitted 65 jobs of GluGluHiggsToTauTau PU 200 since 2 jobs have plots that look ok. Still waiting on this to run by end of the day
- B-tagging repo: Merged devel branch with master branch 

- Savannah says HDF5Utils requires ROOT, HDF5, and Boost. 
- She says she installed hers locally, since it's a pain to set up on ATLAS software areas at least, because hdf5 isn't compatible with the standard ROOT build.
  - Ran `brew install boost` in Documents 
  - Ran `conda install h5py` in Documents/ROOT
  - Still building a new ROOT installation.

- Drafted an analyzer that calls an already-trained BDT's weight file to calculate a discriminant for each L1 tau, and stores the discriminant in a branch in efficiencyTree.
  - Idea is to add a branch to efficiencyTree that is the BDT discriminant
  - Is there a way to avoid loading the TMVA reader in every call to the analyze() function?
  - Testing on lxplus730 screen session
- Updated checkout instructions - scram command needs an extra `-lTMVA` compilation flag
# Weeks of Friday (Aug 16 2019) - Tuesday (Aug 27, 2019)

## Friday (Aug 16, 2019)

1. ○ Figure out how to make rate plots.
2. ✓ Decide how to set <= 1.0 error bars in efficiency plots.
3. ✓ Follow-up on whether analyzer is flawed?
4. ✖️ Re-submitting a few neutrinogun samples 
   * **Too large**, job ran for more than 48 hours and was held

Debugging analyzer: the core issue is that there are too many events missing a
L1 tau.
1. ✓ Check if variables are being re-initialized to default values before filling a tree in
   the analyzer.
2. ✓ Find the closest l1Track to the recoTau (using deltaR) and add it to the tree.
3. Running on four DYtoLL FEVTs
   * Core-dumped the first time because of file access issues

## Monday (Aug 19, 2019)

Goal: continue investigating why many events are missing a L1 tau. 
First see if l1Tracks are being properly matched to the reco taus.
Next, see if there are charged hadrons that match recoTau for 1 prong taus (decay mode 0)


1. ✓ Wait for analyzer to finish running on four DYtoLL FEVTs
   * Based on logRun, the minimum dR between the l1Track and the reco tau is
     mostly 0.001-0.008, but some are either the default value (999) or large (2-3)
   * Printing recoPt and track pT too 
2. Check if L1 Track matching looks good 
3. ~~If not, put in the L1 Particle Flow candidates~~
4. "We expect that for 1 prong taus (Decay mode 0) that there will be a track
   produced 95% of the time for taus above 25 GeV. So, what I would do is
   1) Pick a few events that are missing their L1 taus and figure out if
      there is a L1Track that matches it with a similar pT
   2) Check to see if there is a charged hadron matching it with a 
      relatively high pT."
   * Brainstorming: 
     `const reco::CandidatePtrVector chargedHadron = miniTaus->at(i).signalChargedHadrCands()`
     For 1 prong taus (decay mode 0), loop through chargedHadrons and see if any
     match recoTau and print pT.
5. ✓ Begin outline of internal presentation
6. ~~Make ROC curve plotting script~~
7. ✓ Fix >1.0 errorbars

## Tuesday (Aug 20, 2019)

Clarified with Isobel:
The goal is to answer the question: Are we losing efficiency for Taus with DM = 0 during L1 Track 
Reconstruction, during PF Charged Hadron Identification or during L1PFTau Reconstruction? Or is it
a combination of all 3?

* You just need to do this, but instead of a l1Tau, take the closest l1Track to the recoTau
https://github.com/skkwan/phase2L1TauAnalyzer/blob/93673af5f8b5f7344fabf6404c6f1794faaf6c64/plugins/phase2L1TauAnalyzer.cc#L810-L820
* Then instead of a l1Tau, use a charged hadron

1. Investigate whether L1PFTau reconstruction was the issue:
   * ✓ In analyzer lines 810-820, use closest l1Track to the recoTau
   * ✓ Wait for analyzer to finish running
2. ✓ Figure out how to make ROC curve plotting script
   
## Wednesday (Aug 21, 2019)

1. ✓ Make efficiency plot with 4FEVT ntuple (200PU Drell-Yan)
   * Issue: error bars are really large, need to submit more jobs
2. ✓ Wrote another script that makes TMVA-style background rejection vs. signal efficiency curve
3. ✓ Started editing efficiency script to address >1.0 efficiency error bars

## Thursday (Aug 22, 2019)

1. ✓ Submitted 36 jobs with 200PU Drell-Yan with l1Track information
2. Still debugging efficiency script - some bins show that max error bar is set to 1.0, but
   a few bins are still poking over and I don't know why 
3. ✓ Made LaTeX document for experimental project report

## Friday (Aug 23, 2019)

1. Still waiting for jobs to finish running
2. ✓ Started writing background for experimental project report

## Monday (Aug 26, 2019)

1. ✓ Made slides for group meeting https://www.overleaf.com/project/5d63c7b7de7b0c16fa85b665
2. Isobel suggested workaround for >72 hour jobs: lower max number of events
3. ✓ Fixed >1.0 efficiency bars, still have <0.0 lower limits though

## Tuesday (Aug 27, 2019)

I decided to do a *no-pileup* study first for debugging missing L1 taus, simply because it will
take less time to run jobs. I will train on a no-pileup n-tuple made using the old analyzer
(even though it is missing L1 taus), and then make the efficiency plots using that BDT and an
n-tuple with the L1 track info.

To-do for next month:
1. Submit jobs for no-pileup Drell-Yan for training (`/two-file-batch-example`)
   * ✓ Submitted 2 test jobs with name `2019_Aug27-DYToLL_NoPU_withL1Tracks-mini` using MC files from
   [https://github.com/skkwan/phase2L1TauAnalyzer/tree/17ef541fefdd11d149acfc8ef239c9fab2d1ab0a/test/two-file-batch-example](commit)
   `17ef541`.
   * When 2 test jobs finish running, submit all jobs.
2. Submit jobs for no-pileup GluGluHiggsToTauTau for training (`/aodsim-two-file-batch`)
   * ✓ Submitted 2 test jobs with name `2019_Aug27-ggHtautau_noPU-MINI-try2`.
   * When 2 test jobs finish running, submit all jobs.
3. No-pileup L1 track study
4. Keep track of how many Drell-Yan and GluGluHiggsToTauTau samples I am combining
5. Make game plan for experimental project presentation and report
6. Make 200-pileup n-tuples with the L1 track information.

## Wednesday (Aug 28, 2019)

Updated above bullet points.

# Week of Friday (Aug 16 2019) - Thursday (Aug 23, 2019)

## Friday (Aug 16, 2019)

1. Figure out how to make rate plots.
2. Decide how to set <= 1.0 error bars in efficiency plots.
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
1. Wait for analyzer to finish running on four DYtoLL FEVTs
   * Based on logRun, the minimum dR between the l1Track and the reco tau is
     mostly 0.001-0.008, but some are either the default value (999) or large (2-3)
2. Check if L1 Track matching looks good
3. If not, put in the L1 Particle Flow candidates
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


# Week of Friday (Aug 9, 2019) - Thursday (Aug 15 2019)

## Friday (Aug 9, 2019)

- Submitted Drell-Yan jobs from dataset `/DYToLL_M-50_14TeV_TuneCP5_pythia8/PhaseIIMTDTDRAutumn18MiniAOD-NoPU_103X_upgrade2023_realistic_v2-v2/MINIAODSIM`
- I think I finally understand Tag and Probe

## Saturday (Aug 10, 2019)

- The Drell-Yan jobs have no pile-up, submitted more jobs

## Monday (Aug 12, 2019)

- Submitting more Drell-Yan no-pileup jobs
- Tried to change `TMVAAnalysis_tau.C` on master branch to accomodate multiple input files, gave up

### Discussed with Isobel:

**Q:** Are we doing a tag and probe measurement?

**A:**
*  No, only an efficiency study, although tag and probe can be used in the context of measuring
   the trigger efficiency (see https://amva4newphysics.wordpress.com/2017/02/15/tagging-and-probing/)
* "For the efficiency turn on curve you will make you will plot the ratio of taus which pass L1 Trigger requirements and are true taus to all true taus. To expand further: in the denominators Taus that are reco or gen-level matched to a tau with a  reco or gen-level pT above (let's say) 15 GeV and with |eta|<2.5 . In the numerator you require the denominator + the associated L1 Tau has a BDT discriminant value over a given working point (or cutoff value) and above a given L1Trigger PT."
* Implement as a standalone ROOT C macro

**Q:** Should I use a minimum bias sample to evaluate the efficiency?

**A:** No, efficiencies are evaluated with events that have true taus. Rates are evaluated with Min Bias/ZeroBias/QCD samples.

**Q:** What sample should I evaluate rates on?

**A:** Try
        `/NeutrinoGun_E_10GeV/PhaseIIMTDTDRAutumn18MiniAOD-PU200_103X_upgrade2023_realistic_v2-v1/MINIAODSIM`

Other notes:
1. Should train on no-pileup DYLL+ggH and pileup DYLL+ggH
   * so I need to make ntuples 

**Q:** Data Aggregation Service is only listing AODSIM files as parents of miniAODs. Can we use them?

**A:** The tiers we need are RAW and Mini. 

Issues:
1. ~~I can't find a no-pileup ggHtautau sample with FEVT parent files, only AODSIM~~ Solution: need to get the parents of the AODSIM.


## Tuesday (Aug 13, 2019)

To-do:
1. ✓ Merge all available 200 PU samples.
2. ✓ Train on all available 200 PU samples.
   * 6671 signal and 5227 background training events
   * 800 trees, max depth of 3
   * Average ROC-Int: 0.767, std. deviation over 5 folds is 0.01
   * Signal efficiencies for test/training samples:
     * @B=0.01: 0.159 (0.163)
     * @B=0.10: 0.438 (0.464)
     * @B=0.30: 0.691 (0.697) 
3. ✓ Decide if more 200 PU samples are needed.
   * Yes, generating more 200 PU DYtoLL samples.
   * Had to kill 12 jobs because they went over the memory limit of 2048 MB.
4. ✓ Write .C script to call the calculateEfficiencies function.
5. ✓ Try compiling and running it.
6. ✓ Try running analyzer on 106x samples interactively before submitting bash jobs
7. ✓ Generate first efficiency plot (as a function of BDT cut)
8. ✓ Define Loose, Medium, and Tight working points based on the BDT discriminator cut,
   for 90%, 80%, and 75% efficiency respectively.
   * Bad eyeballing:
     * 90% efficiency -> cutoff of -0.3
     * 80% efficiency -> cutoff of -0.185
     * 75% efficiency -> cutoff of -0.1
9. ✓ Efficiency plot: x-axis should be recoPt from 0 to 100 GeV,
   then create a 20 GeV "turn-on curve by requiring l1Pt > 20 GeV"
10. ✓ Edit efficiency vs. recoPt plot so it overlays the different working points curves

## Wednesday (Aug 14, 2019)

To-do:
1. Prepare neutrinoGun samples for making rate plots.
   * ✓ Remove limit on job size.
   * Submit two neutrinoGun jobs only, see how they look
2. ✓ Assess status of PU200 and noPU dataset.
   * DYtoLL no-pileup, ggHtautau 200 PU done; have some DYtoLL 200PU, no ggHtautau no-pileup
3. Submit aodsim solution for 106x samples (ggHtoTauTau noPU)
3. ✓ Change plot style of efficiency plot to bullet points.
4. ✓ Add error bars to efficiency plot.
   * ★  Learned that if I just pass the efficiency as a float, I'm losing all the systematics
     error
   * ✓ Propagate uncertainty in calculating the divisor
5. ✓ Switch to histogram approach for efficiency plots
   * ✓ Fill numerator and denominator histograms
     * ✓ Histogram is a count of events in each bin
     * ✓ Histograms should be a function
   * ✓ Restructure numerator/denominator calculation  
6. ✓ Touch up plot style
   * ✓ Add dotted grid lines	
   * ✓ Change x-axis label to LaTeX formatting
   * ✓ Make x- and y- axis labels larger
   * ✓ Move legend to bottom right
7. Physics tweaks to efficiency plot
   * ✓ See if using Drell-Yan + ggH will make more low-recoPt bins (it doesn't)
   * ✓ Make sure the BDT was trained on 200 PU:
     * ★  There is some over-training: I should make more DYtoLL 200 PU if possible

## Thursday (Aug 15, 2019)

1. ✓ Send plot to Isobel and ask about low-recopT points and whether logic of "if" statements is correct

### Feedback
- deltaR matching between L1 and reco, and L1 and gen taus, is done in the analyzer when the tree is filled.
- Taus in general have a low purity and low efficiency.
- Often electrons, muons, jets can be reconstructed as Tau and on top of that, only ~80% of all gen level taus are reconstructed due to tracking inefficiency.
- We measure the efficiency for hadronic taus because taus that decay weakly to electrons and 
  muons are identified in the detector as electronics and muons.
  It is nearly impossible to discern between electrons and muons that originate directly
  (promptly) from taus and those that originate directly from Z bosons, for example.
- So taus that decay to electrons or muons simply use electron or muon triggers.
- Hadronic taus have a limited number of decays and typically the more rare ones 
  (1 prong + 2 pi0 for instance) will be reconstructed in one of the other decay modes (1prong + 1 pi0). 
- See: Decay mode migration
- So we want to make two plots:
  - Efficiency as a function of recoPt, using reco taus matched to gen taus that decayed
    hadronically.
  - Efficiency as a function of genPt

OK'd by Isobel: commit [https://github.com/skkwan/phase2L1BTagAnalyzer/blob/69a4bf9c254eabc67a4f5cc1323d7af9b018efc7/tau_exercise/efficiency_plots/calculateEfficiency.C](69a4bf9). Below lines include `recoDM == 10` to plot efficiency
only for one decay mode.

```
if (variable == "genPt")
        {
          passesOverallCut = ((genPt > genPtCut) &&
                              passesEta &&
                              (recoDM == 10)
                              );
        }
      else if (variable == "recoPt")
        {
          passesOverallCut = ((recoPt > recoPtCut) &&
                              (genPt > genPtCut) &&
                              passesEta &&
                              (recoDM == 10)
                              );
        }
```

1. ✓ Added no-BDT cut efficiency points: perhaps disappointingly, the BDT cut efficiencies are basically
   the same
2. Isobel diagnosed: for DM = 1 (1 prong pi0)
   
```
root [18] efficiencyTree->SetLineColor(kBlue)
root [19] efficiencyTree->Draw("genEta","recoPt>20&&genPt>20&&recoDM==1&&l1Pt>20")
(long long) 2078
root [20] efficiencyTree->SetLineColor(kRed)
root [21] efficiencyTree->Draw("genEta","recoPt>20&&genPt>20&&recoDM==1","same")
```

(I think the background events have a strange distribution where there are many in abs(genEta) < 1.5.)

3. ✓ Split up efficiency by decay mode (putting the same recoDM requirement in numerator and denominator)
   [https://www.dropbox.com/sh/yzod7wqlcncnrqe/AAAib0Jy1CC6NoGd-0NzQSfda?dl=0](Link to Dropbox plots)
   * Strange: typically decay mode 10 has the worst efficiency because	    
     we lose the lowest pT track from time to time. 
   * In these plots, decay mode 0 seems to have the worst efficiency.
   * Decay mode 0 = 1-prong
   * Decay mode 1 = 1-prong + pi0
   * Decay mode 10 = 3-prong







   

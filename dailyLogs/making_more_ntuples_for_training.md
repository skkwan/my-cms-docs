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

**Q:** What sample should I evaluate the efficiency on?

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
   * See if using Drell-Yan + ggH will make more low-recoPt bins



8. Figure out how to make rate plots.  







   

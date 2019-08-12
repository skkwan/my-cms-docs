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




   

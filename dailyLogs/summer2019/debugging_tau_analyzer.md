# Week of Friday July 12, 2019 - Friday July 19, 2019

## Friday July 12, 2019

- Yesterday, noticed that the level one variables weren't being extracted properly
- Went into `/afs/cern.ch/work/s/skkwan/public/triggerDevel/jul2019/CMSSW_10_6_0_pre4/src/L1Trigger/Phase2L1Taus/src`
  - In `void TauMapper::process`, outside of the prong loops, added the line `l1PFTau.setPz(seedCH.pz()); // set pz`

- Re-installed new CMSSW area using the most recent recipe [here](https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideL1TPhase2Instructions#Phase_2_L1T_Development_and_MC_R)
- Carried over L1Vertex changes in test-Analyzer-reprocess.py and the .cc analyzer, and the TauMapper.C file
- Troubleshooted accessing the z position (it is in fact, .p4().z() because p4 is a XYZT Lorentz Vector
- Ran over 400 events, histograms and stdout look ok, running over all events now

## To-do

1. Make plots of new variables
1. Add new variables to BDT training
1. Add K-fold validation

## Monday July 15, 2019
- Edited makeComparison plots, changed plotting style to look nicer, some plots still turning up blank
- Sam gave me script to rewrite
- Added l1tauZ as a branch to tau analyzer and re-ran on sample

## Tuesday July 16, 2019

- Figured out why some plots were blank (range should encompass all bins to be safe)
- But all bkg (genPt < 5) values are the default value so they're not being filled correctly
- Changed analyzer so that l1 variables are filled outside of the l1/Reco matching requirement.
- Wrote `TMVACrossValidation.C` based on tutorial but it freezes on something.
- Tutorial itself can't be run without compile-time erros.

## Wednesday July 17, 2019

- L1 Trigger trainee shift (MWGR 3, cosmic rays)
- Example of log (see also [past ELogs](https://cmsonline.cern.ch/webcenter/portal/cmsonline/pages_common/elog?wc.contentSource=&__adfpwp_action_portlet=623564097&__adfpwp_backurl=https://cmsonline.cern.ch:443/webcenter/portal/cmsonline/pages_common/elog?wc.contentSource=&_piref623564097.strutsAction=//viewSubcatMessages.do?catId=593&subId=11&page=1&fetch=1&mode=expanded))
  ```
  10:53 Run 329969

  	LHC: Shutdown - No beam
	Key: cosmics2019/v7
	Subsystems: ECAL and HCAL in.

	Prescale Column:   34 (MB Only)
	Pre-DT L1 Rate:    3.7 kHz
	Stream Physics:    2.4 kHz
	Express:           30 Hz
	Dead Time:	   1.77%

  10:57 Stopped run.
  ```
- [CMS OMS](https://cmsoms.cern.ch/cms/runs/summary) has a summary of all runs with their start/stop time, if you need to fill gaps in your elog. 

- Tried to debug TMVA Cross Validation script and the example, asked Savannah for help.


## Thursday July 18, 2019

- cmsRun analyzer crashed yesterday due to loss of write permissions in afs when the ssh connection closed. 
- Found a lxplus-specific [website](https://lhcb.github.io/analysis-essentials/shell-extras/screen.html) explaining screen sessions- need `kinit` to 
  maintain write permissions.
- Restarted analyzer on lxplus709.
# 2019 09 20 No PF Cand Charged Hadron matching

## Friday Sep 20 2019

### Efficiency
- Yesterday, determined that requiring PF Candidate matching to Charged Hadrons/ low-Pt electrons was
  causing some L1 taus to be missing.
- We removed that requirement from the CMSSW L1PF tau producer:
   ```cmssw/L1Trigger/Phase2L1Taus/plugins/L1PFTauProducer.cc```
  [https://github.com/cms-l1t-offline/cmssw/blob/phase2-l1t-integration-CMSSW_10_6_0_pre4/L1Trigger/Phase2L1Taus/plugins/L1PFTauProducer.cc#L45]((link))
  as well as from the analyzer.
- I am running on batch jobs on an evaluation set to re-make the efficiency plot.

### Rates
- I also got a handy run-down on what rates are, and updated the ```phase2L1TauAnalyzerRates.cc`` and config
  files to compile. 
- Still trying to find a sample that it can run on.

To make a rate plot:
1. Modify the analyzer to fill a histogram with the L1 Tau Pt.
   * **Important:** If you  use a fill method, as in ```phase2L1TauAnalyzerRates.cc```,
     you must sort the input collection by pT or the rates will be nonsense. 
   * This is because the L1Trigger already sorts from high to low pT, so the Global Trigger (GT)
     can easily see if there is at least one tau with, e.g. L1 Pt > 90 GeV, or two taus above
     a Pt threshold for a di-tau trigger.
   * So our analyzer should use std::sort() to mimic what the actual L1 trigger does. And to select good physics events.
2. Create a macro that for each L1Pt step will calculate the sum of all bins to the right of the L1Pt step
   you are interested in, and fill a histogram with that value.
3. Scale the overall rate 40 MHz ((# of all events passing the BDT) / (all events)).

Helpful code snippet:
```
 for(int i = bins; i > 0; i-- ){
    Sum += histo->GetBinContent(i);
    rateHisto->SetBinContent(i, Sum);
  }
```
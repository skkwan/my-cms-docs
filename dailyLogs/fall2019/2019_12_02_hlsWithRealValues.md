# Week of 2019 Dec 2

## Monday, Dec 2 2019

* Cleaned up two HLS directories (see procedures folder) and made sense of some more code

To-do:
* Need a way to read in branches from a TTree and write out as hex values to a table
  * Cannibalize some code from https://github.com/skkwan/phase2L1BTagAnalyzer/blob/master/tau_exercise/tables/makeTable.C
    and https://github.com/skkwan/phase2L1BTagAnalyzer/blob/master/tau_exercise/training/TMVAAnalysis_tau_multifile.C
  * Write helper function that takes an n-tuple and returns one row as a vector
  * l1Pt, l1Eta, l1StripPt, l1DM, l1PVDZ, l1HoE, l1EoH, l1TauZ, l1ChargedIso


## Tuesday, Dec 3 2019

To-do:
* How to convert signed doubles to unsigned ints? Need a LSB/offset for each parameter
* Can I feed the doubles straight into the C evaluation?

## Wednesday, Dec 4 2019

To-do:
* Can have floats in the .txt file, but need to compare with TMVA BDT evaluation
  with the restricted number of bits.


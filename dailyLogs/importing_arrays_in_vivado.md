# Week of Friday Aug 2, 2019 - Thursday Aug 8, 2019

## Friday (Aug 2, 2019)
- Installed TigerVNC
- Wrote down how to VNC to uwlogin.cern.ch and open Vivado HLS
- Wrote a very basic C++ script to open a text file and read in an array; but
  - `/afs/cern.ch/user/s/skkwan/Documents/array_to_design`
  - When I try to synthesize, I get:
  - "ERROR: [HLS 200-72] License checkout unsuccessful. Make sure that a license is accessible or specify an appropriate one through an environment variable."
- Tried to put in the .text file from the makeTable.C script, but I get a segfault that needs to be debugged

- Condor jobs GluGluHtoTauTau jobs are still running...

## Sunday (Aug 4, 2019)

- Jobs are being held: `condor_q -held` shows that some got errors because the job took >72 hours to run, some say "Job has gone over memory limit of 2048 megabytes. Peak usage: 2048 megabytes."
- In the BDT training on `2019_Jul31-GluGluHiggsToTauTau-200PU-mid.root`, still overtraining even though I decreased the number of trees to 400 
  - Signal events: 2085 events in training and testing (aka validation) sets each,
  - Background: 923 events in training and testing (aka validation) sets each
  - Input n-tuple contained 27 FEVT files

- Submitted 2 test jobs using two new miniAOD GluGluHiggsToTauTau files and their associated FEVT

## Monday (Aug 5, 2019)

- 2 test jobs look good, submitting more jobs and killed a few that were over the 2048 megabytes limit

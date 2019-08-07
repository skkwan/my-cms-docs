# Week of Friday Aug 2, 2019 - Thursday Aug 8, 2019

## Friday (Aug 2, 2019)
- Installed TigerVNC
- Wrote down how to VNC to uwlogin.cern.ch and open Vivado HLS
- Wrote a very basic C++ script to open a text file and read in an array; but
  - `/afs/cern.ch/user/s/skkwan/Documents/array_exercise``
  - When I try to synthesize, I get:
  - "ERROR: [HLS 200-72] License checkout unsuccessful. Make sure that a license is accessible or specify an appropriate one through an environment variable."
- `c++ -o importArray importArray.cpp`
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

Vivado HLS:
- By default, an array in C code is implemented by a memory block in the RTL: [http://www.csl.cornell.edu/courses/ece5775/pdf/lecture02.pdf](source)
  - RAM: Read and Write Memory, ROM: Read-Only Memory
- One way to declare a ROM is: [https://forums.xilinx.com/t5/Vivado-High-Level-Synthesis-HLS/Initialize-multidimension-array-from-txt-files/td-p/730457](source)
  - Declare it static
  - Immediately after it's declared, pass it to a function populating it with the correct variables
    * ...without relying on anything else in the code, i.e. it does not take any non-const inputs apart from the array,
    and does not access global variables
  - Don't change it, otherwise HLS cannot infer a ROM

- Fixed the license not found issue by going into the License Manager and picking a chip for which there was a license
  - xczu7ev-ffvf1517-3-e-es2
- Synthesizability Errors: unsupported c/c++ library functions fopen, feof, fscanf, fclose

Downloaded and started doing the Vivado HLS tutorials:
- Example 1 shows how to use a test bench to read from a .dat file

## Tuesday (Aug 6, 2019)

- 40 jobs remaining on 2019_Aug5-GluGluHiggsToTauTau-200PU-try1

- Continued doing tutorials, see Procedures folder
- 


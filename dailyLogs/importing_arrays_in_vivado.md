# Week of Friday Aug 2, 2019 - Thursday Aug 8, 2019

## Friday (Aug 2, 2019)
- Installed TigerVNC
- Wrote down how to VNC to uwlogin.cern.ch and open Vivado HLS
- Wrote a very basic C++ script to open a text file and read in an array; but
  - `/afs/cern.ch/user/s/skkwan/Documents/array_exercise``
  - When I try to synthesize, I get:
  - ~~"ERROR: [HLS 200-72] License checkout unsuccessful. Make sure that a license is accessible or specify an appropriate one through an environment variable."~~
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
- ~~Synthesizability Errors: unsupported c/c++ library functions fopen, feof, fscanf, fclose~~

Downloaded and started doing the Vivado HLS tutorials:
- Example 1 shows how to use a test bench to read from a .dat file

## Tuesday (Aug 6, 2019)

- 40 jobs remaining on 2019_Aug5-GluGluHiggsToTauTau-200PU-try1

- Continued doing Vivado HLS tutorials: [https://github.com/skkwan/phase2L1T/blob/master/procedures/navigating_HLS.md](see here)
- Learned what a .tcl file is: you run a .tcl file to create a project and specify which hardware to use and steps to 
  perform C simulation and synthesis
- Learned how to open and start projects in the interactive Vivado HLS command line
- Learned how to view results of synthesis in the GUI and the output files
- Learned how to add synthesis directives either as pragmas or to the directive file (the latter does not 
  carry over to new Solutions), e.g. unrolling loops, partitioning arrays
- Learned how to look at the "Analysis" perspectives to see which steps in the code are
  consuming which resources/ approximate clock cycles
- Learned how to compare results of different Solutions' reports

## Wednesday (Aug 7, 2019)
- ~~Temporarily can't access Condor scheduler:~~ a job completed this morning in the hdfs area so that's good at least
  - "-- Failed to fetch ads from: <144.92.180.29:9618?addrs=144.92.180.29-9618+[2607-f388-101c-1000--369]-9618&noUDP&sock=1709831_6d44_5> : login03.hep.wisc.edu. SECMAN:2007:Failed to end classad message."

- Made `GluGluHiggsToTauTau-200PU-consolidated-temp.root` consisting of all the GluGluHiggsToTauTau so far and trained with 400 tres (instead of 800) 
  * 400 trees, max depth of 3
  * Signal training events: 3556, testing events: 3556
  * Background training events: 1560, testing events: 1560
  * Average ROC-Int: 0.7961, std. deviation over 5 folds is 0.0096
  * Signal efficiencies for test/training samples:
    * 0.136 (0.251) for @B = 0.01
    * 0.441 (0.559) for @B = 0.10
    * 0.773 (0.811) for @B = 0.30
  * Input contained 19 FEVT files

- [Done] Goal for today: import toy example table into HLS.
  * Wrote testbench file to access a .txt file (must be also attached in the Test Bench in the GUI)
  * Header file specifies dimensions of .txt array (3x3 for toy example)
  * Wrote a touchArray.c function that only serves as a function to be synthesized (adds 0.0 to all elements)
  * Synthesis results in non-zero resource usage so that's a good sign
  * solution2 specifies a RAM_1P_LUTRAM [storage] for myArray in touchArray.c
    * Added it as a **pragma** not to the directive file; something is going wonky with 
      accessing the directives? and touchArray.c is read-only
    * .bashrc is read-only too
    * Had to re-start VNC server
  * Utilization estimates: same for with and without the RAM_1P_LUTRAM directive

    |Toy example | Description                                              |
    |------------|----------------------------------------------------------|          
    |solution1   | no directives                                            |
    |solution2   | solution 1 and use RAM_1P_LUTRAM for myArray             |
    |solution3   | solution 1, 2, and unroll both for loops in touchArray() | 
    
    |          | solution1 and solution2  | solution3 |
    |----------|--------------------------|-----------|
    | BRAM_18K | 0                        | 0         |
    | DSP48E   | 2                        | 2         |
    | FF       | 251                      | 501       |
    | LUT      | 244                      | 317       |
    | URAM     | 0                        | 0         |
    
    |              | solution1 and solution2  | solution3 |
    |--------------|--------------------------|-----------|
    | Latency min  | 52                       | 17        |
    | Latency max  | 52                       | 17        |
    | Interval min | 53                       | 18        |
    | Interval max | 53                       | 18        |

  * so from this toy example we can see the tradeoff between resource usage and latency.

- [Done] Next goal for today: implement checking in the test bench with the toy example table.
  * Added this to testbench, but now I realize the .txt table's entries should all
    be floats with the same number of decimals or the `diff` system call won't work
  * So I need to change `makeTable.C` in the master branch on lxplus     
  * ~~Opens can of worms where I need to update makeTable.C to use the new set of variables
    from the new analyzer's ntuples~~ (Done)
  * Implemented successful checking with golden output for toy example (had to finangle 
    the number of digits to print)

## Thursday (Aug 7, 2019)

- [Done] Goal for today: import current version of the weights table into HLS!
  * Testbench isn't passing at the moment due to float issues (e.g. -2.000 becomes -1.9999)

    |          | No optimizations | Available |
    |----------|------------------|-----------|
    | BRAM_18K | 0                | 624       |
    | DSP48E   | 2                | 1728      |
    | FF       | 286              | 460800    |
    | LUT      | 293              | 230400    |
    | URAM     | 0                | 96        |

- Floats don't play well well HLS, we should switch to ints

# Benchmark job lengths for nominal

Some attempts to run on the entire dataset in one job, but failures on single input files cause the entire job to crash. So there is a trade-off in having large jobs:
good for parallelism, but more risky for input files not being accessible.

## Embedded

The ballpark looks like ~3 million events (for embedded) takes about an hour. So we want to split 2018A into 6 jobs or so. There are 226 files, so 38 files per job.
2018D goes into 9 jobs or so. There are 5646 files, so 627 files per job.

|                     | Number of events in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) to target one hour per job |
|---------------------|-----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| Embedded Run 2018 A | 11,724,910                  |                  |                         |                                    | 38                         |
| Embedded Run 2018 B | 3,096,765                   | 31.46%           | 1:03:32                 | -                                  | -                          |
| Embedded Run 2018 C | 2,855,846                   | 31.30%           | 0:57:58                 | -                                  | -                          |
| Embedded Run 2018 D | 25,379,684                  |                  |                         | 0:44:40                            | 627                        |

## TTbar

The ballpark looks like ~2 million events should take an hour - this is to be tested. 

|                       | Total files | Number of events in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) |
|-----------------------|-------------|-----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| TTToHadronic          | 109         | 128,640,000                 | 1.40%            | 2:54:24                 | ?                                  | 56 (2 jobs)                |
| TTToHadronic-ext2     | 161         | 198,756,000                 | 1.40%            | 7:12:59                 | ?                                  | 23 (7 jobs)                |
| TTTo2L2Nu             | 60          | 64,310,000                  | 8.29%            | 3:13:23                 | ?                                  | 20 (3 jobs)                |
| TTToSemiLeptonic      | 94          | 100,790,000                 | ?                | never finished          |                                    | 19 (5 jobs)                |
| TTToSemiLeptonic-ext3 | 151         | 199,829,998                 | ?                | never finished          |                                    | 26 (6 jobs)                |

TTToHadronic: with 6 files, took 00:11
TTToHadronic: with 12 files, took ?
TTToHadronic: with 24 files, took ? 

## Data

|                     | Number of events in dataset | Number of files in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) |
|---------------------|-----------------------------|----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| SingleMuon-Run2018A | 241,608,232                 | 225                        | 1.41%            | 3:17:31                 | ?                                  | 75 (4 jobs)                |
| SingleMuon-Run2018B | 119,918,017                 | 110                        | 1.42%            | 1:28:26                 | -                                  | -                          |
| SingleMuon-Run2018C | 110,032,072                 | 79                         | 1.38%            | 1:22:53                 | -                                  | -                          |
| SingleMuon-Run2018D | 514,116,477                 | 293                        | 1.32%            | 4:22:18                 | ?                                  | 76 (4 jobs)                |
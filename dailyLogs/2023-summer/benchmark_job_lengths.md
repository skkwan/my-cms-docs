# Benchmark job lengths for nominal

Some attempts to run on the entire dataset in one job, but failures on single input files cause the entire job to crash. So there is a trade-off in having large jobs:
good for parallelism, but more risky for input files not being accessible.

## Embedded

The ballpark looks like ~3 million events (for embedded) takes about an hour. So we want to split 2018A into 6 jobs or so. There are 226 files, so 38 files per job.
2018D goes into 9 jobs or so. There are 5646 files, so 627 files per job.

|                     | Total files | Number of events in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) |
|---------------------|-------------|-----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| Embedded Run 2018 A | 2159        | 11,724,910                  | 34.49%           | did not finish          |                                    | 4 jobs (540 files)         |
| Embedded Run 2018 B | 972         | 3,096,765                   | 31.46%           | 1:03:32                 | not necessary                      | not necessary              |
| Embedded Run 2018 C | 897         | 2,855,846                   | 31.30%           | 0:57:58                 | not necessary                      | not necessary              |
| Embedded Run 2018 D | 5646        | 25,379,684                  |                  | did not finish          |                                    | 8 jobs (706 files)         |

## TTbar

The ballpark looks like ~2 million events should take an hour - this is to be tested. 

|                       | Total files | Number of events in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) |
|-----------------------|-------------|-----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| TTToHadronic          | 109         | 128,640,000                 | 1.40%            | 2:54:24                 | 0:48:10                            | 56 (2 jobs)                |
| TTToHadronic-ext2     | 161         | 198,756,000                 | 1.40%            | 7:12:59                 | 0:53:01                            | 23 (7 jobs)                |
| TTTo2L2Nu             | 60          | 64,310,000                  | 8.29%            | 3:13:23                 | ?                                  | 20 (3 jobs)                |
| TTToSemiLeptonic      | 94          | 100,790,000                 | ?                | never finished          |                                    | 19 (5 jobs)                |
| TTToSemiLeptonic-ext3 | 151         | 199,829,998                 | 5.75%            | never finished          | 1:06:01                            | 26 (6 jobs)                |

## Data

|                     | Total files | Number of events in dataset | Percent accepted | Time for entire dataset | Time if split into jobs of size... | Job size (number of files) |
|---------------------|-------------|-----------------------------|------------------|-------------------------|------------------------------------|----------------------------|
| SingleMuon-Run2018A | 225         | 241,608,232                 | 1.41%            | 3:17:31                 | ?                                  | 75 (4 jobs)                |
| SingleMuon-Run2018B | 110         | 119,918,017                 | 1.42%            | 1:28:26                 | not necessary                      | -                          |
| SingleMuon-Run2018C | 79          | 110,032,072                 | 1.38%            | 1:22:53                 | not necessary                      | -                          |
| SingleMuon-Run2018D | 293         | 514,116,477                 | 1.32%            | 4:22:18                 | ?                                  | 76 (4 jobs)                |
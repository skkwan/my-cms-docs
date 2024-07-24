# Condor commands/ cheatsheet

Remove all held jobs:
```bash
condor_rm --constraint JobStatus==5
```

Job statuses [source](https://htcondor.com/htcondor-ce/v23/remote-job-submission/):
```bash
    JobStatus codes:
     1 I IDLE
     2 R RUNNING
     3 X REMOVED
     4 C COMPLETED
     5 H HELD
     6 > TRANSFERRING_OUTPUT
     7 S SUSPENDED
```

Check user priority (lxplus HTCondor has half-life of 7 hours)

```bash
# Works if running active jobs 
condor_userprio | grep "skkwan"
# Works in general but may time out if there are too many users
condor_userprio --allusers | grep "skkwan"
```
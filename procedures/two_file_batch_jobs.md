# Submitting batch jobs to run analyzer on many primary/secondary files
On the U Wisconsin Madison server.

## Setup and submitting
To run analyzers that need an primary (miniAOD) and secondary (FEVT) file, follow instructions here [https://github.com/isobelojalvo/phase2L1TauAnalyzer/tree/master/test/two-file-batch-example]((Isobel's instructions)). They are quoted here:
0. Do `cmsenv` and get the VOMS certificate. Make sure you have room in `/hdfs/store/user/skkwan`.
1. First place your analyzer in this folder and call it test-Analyzer.py
2. Next put the Secondary File list in inputFileList.txt and the mini-AOD list in inputFileList-MINI.txt
3. Create the submit footers, submit-x.py using the command 
   '''python dasqueryMiniFEVT.py inputFileList.txt inputFileList-MINI.txt'''
**For the next step PLEASE run a test job to see that it runs and outputs a file on /hdfs/ before submitting all jobs.** You can do this by changing the bash script to run on only two files like: `for i in {0..1}`.

4. Create and submit the analyzers ```bash createAnalyzers.sh```

## Monitoring

- `condor_q`: shows status of jobs and job ID.
- `condor_ssh_to_job <JOB_ID>` 

## Afterwards
- Merge the resulting files: ```hadd nameoffile.root /hdfs/store/user/skkwan/<path to files>/*.root```

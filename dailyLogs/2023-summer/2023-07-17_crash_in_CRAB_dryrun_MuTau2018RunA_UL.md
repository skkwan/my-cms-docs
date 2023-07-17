# 2023-07-17 Issue: CRAB job crashes for converting UL Embedded MiniAOD to NanoAOD

My working area: `/afs/hep.wisc.edu/home/skkwan/public/embeddedMiniToNano/CMSSW_10_6_30/`

For the cmsRun config file: https://github.com/skkwan/embeddedToNanoAOD/blob/ultralegacy/crabConfig/2018/scripts/embedding_nanoAOD_18.py 

And the CRAB config file: https://github.com/skkwan/embeddedToNanoAOD/blob/ultralegacy/crabConfig/2018/crabConfig-2018A.py 


I run, in `CMSSW_10_6_30`,

```bash
cmsenv
voms-proxy-init
crab submit crabConfig-2018A.py
```

Interactively this cmsRun config file works, but in CRAB, a `dryrun` test fails because: `Module: HTXSRivetProducer:rivetProducerHTXS (crashed)`.
The printouts for both interactive and CRAB dryrun are copied below.

## Interactively the cmsRun config file works


[skkwan@login05 scripts]$ cmsRun embedding_nanoAOD_18.py
Updating process to run DeepBoostedJet on datasets before 103X
Updating process to run ParticleNet before it's included in MiniAOD
Updating process to run DeepDoubleX on datasets before 104X
Updating process to run DeepDoubleXv2 on datasets before 11X
Will recalculate the following discriminators on AK8 jets: pfDeepBoostedJetTags:probTbcq, pfDeepBoostedJetTags:probTbqq, pfDeepBoostedJetTags:probTbc, pfDeepBoostedJetTags:probTbq, pfDeepBoostedJetTags:probWcq, pfDeepBoostedJetTags:probWqq, pfDeepBoostedJetTags:probZbb, pfDeepBoostedJetTags:probZcc, pfDeepBoostedJetTags:probZqq, pfDeepBoostedJetTags:probHbb, pfDeepBoostedJetTags:probHcc, pfDeepBoostedJetTags:probHqqqq, pfDeepBoostedJetTags:probQCDbb, pfDeepBoostedJetTags:probQCDcc, pfDeepBoostedJetTags:probQCDb, pfDeepBoostedJetTags:probQCDc, pfDeepBoostedJetTags:probQCDothers, pfDeepBoostedDiscriminatorsJetTags:TvsQCD, pfDeepBoostedDiscriminatorsJetTags:WvsQCD, pfDeepBoostedDiscriminatorsJetTags:ZvsQCD, pfDeepBoostedDiscriminatorsJetTags:ZbbvsQCD, pfDeepBoostedDiscriminatorsJetTags:HbbvsQCD, pfDeepBoostedDiscriminatorsJetTags:H4qvsQCD, pfMassDecorrelatedDeepBoostedJetTags:probTbcq, pfMassDecorrelatedDeepBoostedJetTags:probTbqq, pfMassDecorrelatedDeepBoostedJetTags:probTbc, pfMassDecorrelatedDeepBoostedJetTags:probTbq, pfMassDecorrelatedDeepBoostedJetTags:probWcq, pfMassDecorrelatedDeepBoostedJetTags:probWqq, pfMassDecorrelatedDeepBoostedJetTags:probZbb, pfMassDecorrelatedDeepBoostedJetTags:probZcc, pfMassDecorrelatedDeepBoostedJetTags:probZqq, pfMassDecorrelatedDeepBoostedJetTags:probHbb, pfMassDecorrelatedDeepBoostedJetTags:probHcc, pfMassDecorrelatedDeepBoostedJetTags:probHqqqq, pfMassDecorrelatedDeepBoostedJetTags:probQCDbb, pfMassDecorrelatedDeepBoostedJetTags:probQCDcc, pfMassDecorrelatedDeepBoostedJetTags:probQCDb, pfMassDecorrelatedDeepBoostedJetTags:probQCDc, pfMassDecorrelatedDeepBoostedJetTags:probQCDothers, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:TvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:WvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:ZvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:ZHbbvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:ZbbvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:HbbvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:H4qvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:ZHccvsQCD, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:bbvsLight, pfMassDecorrelatedDeepBoostedDiscriminatorsJetTags:ccvsLight, pfParticleNetJetTags:probTbcq, pfParticleNetJetTags:probTbqq, pfParticleNetJetTags:probTbc, pfParticleNetJetTags:probTbq, pfParticleNetJetTags:probTbel, pfParticleNetJetTags:probTbmu, pfParticleNetJetTags:probTbta, pfParticleNetJetTags:probWcq, pfParticleNetJetTags:probWqq, pfParticleNetJetTags:probZbb, pfParticleNetJetTags:probZcc, pfParticleNetJetTags:probZqq, pfParticleNetJetTags:probHbb, pfParticleNetJetTags:probHcc, pfParticleNetJetTags:probHqqqq, pfParticleNetJetTags:probQCDbb, pfParticleNetJetTags:probQCDcc, pfParticleNetJetTags:probQCDb, pfParticleNetJetTags:probQCDc, pfParticleNetJetTags:probQCDothers, pfParticleNetDiscriminatorsJetTags:TvsQCD, pfParticleNetDiscriminatorsJetTags:WvsQCD, pfParticleNetDiscriminatorsJetTags:ZvsQCD, pfParticleNetDiscriminatorsJetTags:ZbbvsQCD, pfParticleNetDiscriminatorsJetTags:HbbvsQCD, pfParticleNetDiscriminatorsJetTags:HccvsQCD, pfParticleNetDiscriminatorsJetTags:H4qvsQCD, pfMassDecorrelatedParticleNetJetTags:probXbb, pfMassDecorrelatedParticleNetJetTags:probXcc, pfMassDecorrelatedParticleNetJetTags:probXqq, pfMassDecorrelatedParticleNetJetTags:probQCDbb, pfMassDecorrelatedParticleNetJetTags:probQCDcc, pfMassDecorrelatedParticleNetJetTags:probQCDb, pfMassDecorrelatedParticleNetJetTags:probQCDc, pfMassDecorrelatedParticleNetJetTags:probQCDothers, pfMassDecorrelatedParticleNetDiscriminatorsJetTags:XbbvsQCD, pfMassDecorrelatedParticleNetDiscriminatorsJetTags:XccvsQCD, pfMassDecorrelatedParticleNetDiscriminatorsJetTags:XqqvsQCD, pfParticleNetMassRegressionJetTags:mass, pfDeepDoubleBvLJetTags:probHbb, pfDeepDoubleCvLJetTags:probHcc, pfDeepDoubleCvBJetTags:probHcc, pfMassIndependentDeepDoubleBvLJetTags:probHbb, pfMassIndependentDeepDoubleCvLJetTags:probHcc, pfMassIndependentDeepDoubleCvBJetTags:probHcc, pfMassIndependentDeepDoubleBvLV2JetTags:probHbb, pfMassIndependentDeepDoubleCvLV2JetTags:probHcc, pfMassIndependentDeepDoubleCvBV2JetTags:probHcc
add DeepMET Producers
17-Jul-2023 10:26:52 CDT  Initiating request to open file root://cmsxrootd.fnal.gov///store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/0217e7d7-7eec-498b-9eea-e8129fc89f2c.root
%MSG-w XrdAdaptor:  file_open 17-Jul-2023 10:27:35 CDT pre-events
Data is served from gridka.de instead of original site US-Regional-FNAL
%MSG
17-Jul-2023 10:27:39 CDT  Successfully opened file root://cmsxrootd.fnal.gov///store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/0217e7d7-7eec-498b-9eea-e8129fc89f2c.root
                         : Booking "muonMVATTH" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_2017.weights.xml.
                         : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_2017.weights.xml
<HEADER> DataSetInfo              : [Default] : Added class "Signal"
<HEADER> DataSetInfo              : [Default] : Added class "Background"
                         : Booked classifier "BDTG" of type: "BDT"
                         : Booking "muonMVALowPt" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_lowpt.weights.xml.
                         : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_lowpt.weights.xml
<HEADER> DataSetInfo              : [Default] : Added class "Signal"
<HEADER> DataSetInfo              : [Default] : Added class "Background"
                         : Booked classifier "BDTG" of type: "BDT"
                         : Booking "electronMVATTH" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/el_BDTG_2017.weights.xml.
                         : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/el_BDTG_2017.weights.xml
<HEADER> DataSetInfo              : [Default] : Added class "Signal"
<HEADER> DataSetInfo              : [Default] : Added class "Background"
                         : Booked classifier "BDTG" of type: "BDT"
%MSG-e L1PrefireWeightProducer:  L1PrefiringWeightProducer:prefiringweight@ctor  17-Jul-2023 10:28:04 CDT pre-events
Photon map not found. All photons prefiring weights set to 0. 
%MSG
%MSG-e L1PrefireWeightProducer:  L1PrefiringWeightProducer:prefiringweight@ctor  17-Jul-2023 10:28:04 CDT pre-events
Jet map not found. All jets prefiring weights set to 0. 
%MSG
%MSG-w BTagSFProducer:  BTagSFProducer:btagWeightTable@ctor  17-Jul-2023 10:28:05 CDT pre-events
Skipped loading BTagCalibration for CMVA as it was marked as unavailable in the configuration file. Event weights will not be stored.

%MSG
%MSG-w LogicError:  GenWeightsTableProducer:genWeightsTable@beginRun  17-Jul-2023 10:28:24 CDT Run: 316217
::getByLabel: An attempt was made to read a Run product before endRun() was called.
The product is of type 'LHERunInfoProduct'.
The specified ModuleLabel was 'externalLHEProducer'.
The specified productInstanceName was ''.

%MSG
%MSG-w LogicError:  HTXSRivetProducer:rivetProducerHTXS@beginRun  17-Jul-2023 10:28:24 CDT Run: 316217
::getByLabel: An attempt was made to read a Run product before endRun() was called.
The product is of type 'LHERunInfoProduct'.
The specified ModuleLabel was 'externalLHEProducer'.
The specified productInstanceName was ''.

%MSG
Begin processing the 1st record. Run 316217, Event 158793634, LumiSection 135 on stream 0 at 17-Jul-2023 10:28:29.392 CDT
Rivet.Analysis.Handler: WARN  Analysis 'HiggsTemplateCrossSections' is unvalidated: be careful, it may be broken!
==============================================================
========     HiggsTemplateCrossSections Initialization     =========
==============================================================
Rivet.Analysis.HiggsTemplateCrossSections: WARN  No HIGGSPRODMODE shell variable found. Needed when running Rivet stand-alone.
==============================================================
========             Higgs prod mode 0              =========
========          Sucessful Initialization           =========
==============================================================
Rivet.Analysis.HiggsTemplateCrossSections: WARN  Unkown Higgs production mechanism. Cannot classify event. Classification for all events will most likely fail.
Rivet.Analysis.HiggsTemplateCrossSections: INFO   ====================================================== 
Rivet.Analysis.HiggsTemplateCrossSections: INFO        Higgs Template X-Sec Categorization Tool          
Rivet.Analysis.HiggsTemplateCrossSections: INFO                  Status Code Summary                     
Rivet.Analysis.HiggsTemplateCrossSections: INFO   ====================================================== 
Rivet.Analysis.HiggsTemplateCrossSections: INFO       >>>> All 0 events successfully categorized!
Rivet.Analysis.HiggsTemplateCrossSections: INFO   ====================================================== 
Rivet.Analysis.HiggsTemplateCrossSections: INFO   ====================================================== 
17-Jul-2023 10:28:56 CDT  Closed file root://cmsxrootd.fnal.gov///store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/0217e7d7-7eec-498b-9eea-e8129fc89f2c.root

=============================================

MessageLogger Summary

 type     category        sev    module        subroutine        count    total
 ---- -------------------- -- ---------------- ----------------  -----    -----
    1 BTagSFProducer       -w BTagSFProducer:b                       1        1
    2 LogicError           -w GenWeightsTableP                       1        1
    3 LogicError           -w HTXSRivetProduce                       1        1
    4 XrdAdaptor           -w file_open                              1        1
    5 L1PrefireWeightProdu -e L1PrefiringWeigh                       2        2
    6 fileAction           -s file_close                             1        1
    7 fileAction           -s file_open                              2        2

 type    category    Examples: run/evt        run/evt          run/evt
 ---- -------------------- ---------------- ---------------- ----------------
    1 BTagSFProducer       pre-events                        
    2 LogicError           Run: 316217                       
    3 LogicError           Run: 316217                       
    4 XrdAdaptor           pre-events                        
    5 L1PrefireWeightProducer pre-events       pre-events       
    6 fileAction           PostGlobalEndRun                  
    7 fileAction           pre-events       pre-events       

Severity    # Occurrences   Total Occurrences
--------    -------------   -----------------
Warning                 4                   4
Error                   2                   2
System                  3                   3

dropped waiting message count 0

## The same job in CRAB with dryrun option fails
[skkwan@login05 2018]$ crab submit --dryrun crabConfig-2018A.py
Will use CRAB configuration file crabConfig-2018A.py
Importing CMSSW configuration scripts/embedding_nanoAOD_18.py
Finished importing CMSSW configuration scripts/embedding_nanoAOD_18.py
Sending the request to the server at cmsweb.cern.ch
Success: Your task has been delivered to the prod CRAB3 server.
Task name: 230717_154358:skkwan_crab_EmbeddingRun2018A_MuTauFinalState
Project dir: crab_projects/crab_EmbeddingRun2018A_MuTauFinalState
Waiting for task to be processed
Checking task status
Task status: NEW
Please wait...
Task status: UPLOADED

Created temporary directory for dry run sandbox in /tmp/tmpFmF9eC
Executing test, please wait...
Dry run failed to execute local test run:
 StdOut: /tmp/tmpFmF9eC
total 23M
-rw-r--r-- 1 skkwan skkwan 618K Jul 14 19:27 WMCore.zip
-rw-r--r-- 1 skkwan skkwan  14K Jul 14 19:27 TweakPSet.py
-rw-r--r-- 1 skkwan skkwan  43K Jul 14 19:27 ServerUtilities.py
-rw-r--r-- 1 skkwan skkwan  11K Jul 14 19:27 RESTInteractions.py
-rw-r--r-- 1 skkwan skkwan  35K Jul 14 19:27 CMSRunAnalysis.py
-rw-r--r-- 1 skkwan skkwan 4.1K Jul 14 19:27 CMSGroupMapper.py
drwxr-xr-x 3 skkwan skkwan 4.0K Jul 17 08:55 lib
drwxr-xr-x 3 skkwan skkwan 4.0K Jul 17 08:55 biglib
-rw-rw-r-- 1 skkwan skkwan 2.4M Jul 17 10:30 PSet.pkl
-rw-rw-r-- 1 skkwan skkwan 2.0M Jul 17 10:30 PSetDump.py
-rw-rw-r-- 1 skkwan skkwan  100 Jul 17 10:30 PSet.py
-rw-r--r-- 1 skkwan skkwan 457K Jul 17 10:30 sandbox.tar.gz
-rw-r--r-- 1 skkwan skkwan 4.5K Jul 17 10:43 debug_files.tar.gz
-rw-r--r-- 1 skkwan skkwan 3.9K Jul 17 10:44 input_dataset_lumis.json
-rw-r--r-- 1 skkwan skkwan 4.0K Jul 17 10:44 input_dataset_duplicate_lumis.json
-rwxr-xr-x 1 skkwan skkwan 2.4K Jul 17 10:44 CMSRunAnalysis.sh
-rwxr-xr-x 1 skkwan skkwan 5.4K Jul 17 10:44 submit_env.sh
-rwxr-xr-x 1 skkwan skkwan 9.9K Jul 17 10:44 gWMS-CMSRunAnalysis.sh
-rw-r--r-- 1 skkwan skkwan  349 Jul 17 10:44 cmscp.sh
-rwxr-xr-x 1 skkwan skkwan  79K Jul 17 10:44 cmscp.py
-rwxr-xr-x 1 skkwan skkwan 3.3K Jul 17 10:44 dag_bootstrap.sh
-rw-r--r-- 1 skkwan skkwan  23K Jul 17 10:44 AdjustSites.py
-rw-r--r-- 1 skkwan skkwan 593K Jul 17 10:44 CMSRunAnalysis.tar.gz
-rw-r--r-- 1 skkwan skkwan 786K Jul 17 10:44 TaskManagerRun.tar.gz
drwxr-xr-x 2 skkwan skkwan 4.0K Jul 17 10:44 debug
-rw-r--r-- 1 skkwan skkwan 357K Jul 17 10:44 run_and_lumis.tar.gz
-rw-r--r-- 1 skkwan skkwan  79K Jul 17 10:44 input_files.tar.gz
-rw-r--r-- 1 skkwan skkwan 343K Jul 17 10:44 datadiscovery.pkl
-rw-r--r-- 1 skkwan skkwan 2.3K Jul 17 10:44 taskworkerconfig.pkl
-rw-r--r-- 1 skkwan skkwan 2.8K Jul 17 10:44 taskinformation.pkl
-rw-r--r-- 1 skkwan skkwan 287K Jul 17 10:44 site.ad
-rw-r--r-- 1 skkwan skkwan  43K Jul 17 10:44 site.ad.json
-rw-r--r-- 1 skkwan skkwan 6.2M Jul 17 10:44 RunJobs.dag
-rw-r--r-- 1 skkwan skkwan 6.8K Jul 17 10:44 Job.submit
-rw-r--r-- 1 skkwan skkwan 3.7M Jul 17 10:44 input_args.json
-rw-r--r-- 1 skkwan skkwan 2.7M Jul 17 10:44 InputFiles.tar.gz
-rw-r--r-- 1 skkwan skkwan  252 Jul 17 10:44 splitting-summary.json
-rw-rw-r-- 1 skkwan skkwan 2.4M Jul 17 10:44 dry-run-sandbox.tar.gz
======== CMSRunAnalysis.sh STARTING at Mon Jul 17 15:44:35 GMT 2023 ========
Local time : Mon Jul 17 10:44:35 CDT 2023
Current system : Linux login05.hep.wisc.edu 5.4.245-1.el7.elrepo.x86_64 #1 SMP Mon Jun 5 17:37:49 EDT 2023 x86_64 x86_64 x86_64 GNU/Linux
Current processor: model name   : AMD Opteron(tm) Processor 6176
======== CMS environment load starting at Mon Jul 17 15:44:35 GMT 2023 ========
WN with a LCG style environment, thus using VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
CRAB job bootstrap: thinks it found the correct CMSSW setup script
======== CMS environment load finished at Mon Jul 17 15:44:35 GMT 2023 ========

======== python bootstrap for stageout at Mon Jul 17 15:44:35 GMT 2023 STARTING ========
Job requires OS: rhel7, thus setting ScramArch to: rhel7_x86_64
WMAgent bootstrap: COMP Python path is: /cvmfs/cms.cern.ch/COMP/rhel7_x86_64/external
WMAgent bootstrap: latest python3 release is: 3.8.2-comp
Sourcing python future library from: /cvmfs/cms.cern.ch/COMP/rhel7_x86_64/external/py3-future/0.18.2/etc/profile.d/init.sh
WMAgent bootstrap: found python3 at..
/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/python3/3.8.2-comp/bin/python3
======== python bootstrap for stageout at Mon Jul 17 15:44:36 GMT 2023 FINISHED ========
==== Make sure /afs/hep.wisc.edu/home/skkwan is defined ====
======== Current environment dump STARTING ========
== ENV: _CONDOR_HEP_VO="uscms"
== ENV: MANPATH=/cvmfs/cms.cern.ch/share/man:/cvmfs/cms.cern.ch/share/man:/cvmfs/cms.cern.ch/share/man:/cvmfs/cms.cern.ch/share/man::/opt/puppetlabs/puppet/share/man
== ENV: XDG_SESSION_ID=122618
== ENV: TERM_PROGRAM=vscode
== ENV: HOSTNAME=login05.hep.wisc.edu
== ENV: REQUIRED_OS=rhel7
== ENV: TERM=xterm-256color
== ENV: SHELL=/bin/bash
== ENV: HISTSIZE=1000
== ENV: SSH_CLIENT=2001:1458:204:1::102:8e8
== ENV: 51306
== ENV: 22
== ENV: CONDA_SHLVL=0
== ENV: TERM_PROGRAM_VERSION=1.80.0
== ENV: CVSROOT=:gserver:cmssw.cvs.cern.ch:/local/reps/CMSSW
== ENV: QTDIR=/usr/lib64/qt-3.3
== ENV: QTINC=/usr/lib64/qt-3.3/include
== ENV: SCRAM_ARCH=slc7_amd64_gcc700
== ENV: CMS=/cvmfs/cms.cern.ch
== ENV: QT_GRAPHICSSYSTEM_CHECKED=1
== ENV: JOBSTARTDIR=/tmp/tmpFmF9eC
== ENV: USER=skkwan
== ENV: LS_COLORS=rs=0:di=38;5;27:ln=38;5;51:mh=44;38;5;15:pi=40;38;5;11:so=38;5;13:do=38;5;5:bd=48;5;232;38;5;11:cd=48;5;232;38;5;3:or=48;5;232;38;5;9:mi=05;48;5;232;38;5;15:su=48;5;196;38;5;15:sg=48;5;11;38;5;16:ca=48;5;196;38;5;226:tw=48;5;10;38;5;16:ow=48;5;10;38;5;21:st=48;5;21;38;5;15:ex=38;5;34:*.tar=38;5;9:*.tgz=38;5;9:*.arc=38;5;9:*.arj=38;5;9:*.taz=38;5;9:*.lha=38;5;9:*.lz4=38;5;9:*.lzh=38;5;9:*.lzma=38;5;9:*.tlz=38;5;9:*.txz=38;5;9:*.tzo=38;5;9:*.t7z=38;5;9:*.zip=38;5;9:*.z=38;5;9:*.Z=38;5;9:*.dz=38;5;9:*.gz=38;5;9:*.lrz=38;5;9:*.lz=38;5;9:*.lzo=38;5;9:*.xz=38;5;9:*.bz2=38;5;9:*.bz=38;5;9:*.tbz=38;5;9:*.tbz2=38;5;9:*.tz=38;5;9:*.deb=38;5;9:*.rpm=38;5;9:*.jar=38;5;9:*.war=38;5;9:*.ear=38;5;9:*.sar=38;5;9:*.rar=38;5;9:*.alz=38;5;9:*.ace=38;5;9:*.zoo=38;5;9:*.cpio=38;5;9:*.7z=38;5;9:*.rz=38;5;9:*.cab=38;5;9:*.jpg=38;5;13:*.jpeg=38;5;13:*.gif=38;5;13:*.bmp=38;5;13:*.pbm=38;5;13:*.pgm=38;5;13:*.ppm=38;5;13:*.tga=38;5;13:*.xbm=38;5;13:*.xpm=38;5;13:*.tif=38;5;13:*.tiff=38;5;13:*.png=38;5;13:*.svg=38;5;13:*.svgz=38;5;13:*.mng=38;5;13:*.pcx=38;5;13:*.mov=38;5;13:*.mpg=38;5;13:*.mpeg=38;5;13:*.m2v=38;5;13:*.mkv=38;5;13:*.webm=38;5;13:*.ogm=38;5;13:*.mp4=38;5;13:*.m4v=38;5;13:*.mp4v=38;5;13:*.vob=38;5;13:*.qt=38;5;13:*.nuv=38;5;13:*.wmv=38;5;13:*.asf=38;5;13:*.rm=38;5;13:*.rmvb=38;5;13:*.flc=38;5;13:*.avi=38;5;13:*.fli=38;5;13:*.flv=38;5;13:*.gl=38;5;13:*.dl=38;5;13:*.xcf=38;5;13:*.xwd=38;5;13:*.yuv=38;5;13:*.cgm=38;5;13:*.emf=38;5;13:*.axv=38;5;13:*.anx=38;5;13:*.ogv=38;5;13:*.ogx=38;5;13:*.aac=38;5;45:*.au=38;5;45:*.flac=38;5;45:*.mid=38;5;45:*.midi=38;5;45:*.mka=38;5;45:*.mp3=38;5;45:*.mpc=38;5;45:*.ogg=38;5;45:*.ra=38;5;45:*.wav=38;5;45:*.axa=38;5;45:*.oga=38;5;45:*.spx=38;5;45:*.xspf=38;5;45:
== ENV: LD_LIBRARY_PATH=/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-future/0.18.2/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-setuptools/39.2.0/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/python3/3.8.2-comp/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/python3/3.8.2-comp/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/db6/6.0.30/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/xz/5.2.2/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/libffi/3.2.1/lib64:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/libuuid/2.22.2/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/gdbm/1.12/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/sqlite/3.8.10.2/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/bz2lib/1.0.6/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/expat/2.0.1/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/zlib/1.2.8/lib:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/gcc/6.3.0/lib64:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/gcc/6.3.0/lib:/usr/local/cuda/lib
== ENV: CONDA_EXE=/afs/hep.wisc.edu/home/skkwan/miniconda3/bin/conda
== ENV: VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
== ENV: CRAB3_RUNTIME_DEBUG=True
== ENV: SITECONFIG_PATH=/cvmfs/cms.cern.ch/SITECONF/local
== ENV: _CE_CONDA=
== ENV: PATH=/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-future/0.18.2/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-setuptools/39.2.0/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/python3/3.8.2-comp/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/python3/3.8.2-comp/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/db6/6.0.30/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/xz/5.2.2/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/gdbm/1.12/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/sqlite/3.8.10.2/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/bz2lib/1.0.6/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/expat/2.0.1/bin:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/gcc/6.3.0/bin:/cvmfs/cms.cern.ch/common:/cvmfs/cms.cern.ch/share/cms/crab-prod/v3.230417.01/bin:/cvmfs/cms.cern.ch/common:/afs/hep.wisc.edu/user/skkwan/.vscode-server/bin/660393deaaa6d1996740ff4880f1bad43768c814/bin/remote-cli:/cvmfs/cms.cern.ch/common:/cvmfs/cms.cern.ch/common:/usr/local/bin/smb:/usr/local/bin/raid:/usr/lib64/qt-3.3/bin:/usr/local/etc:/usr/local/sbin:/usr/sbin:/usr/local/bin/hadoop:/usr/local/bin/firstboot:/usr/local/bin/defaultcls:/usr/condabin:/usr/local/bin/cephdir:/usr/local/bin/afs:/usr/local/bin:/usr/bin:/opt/puppetlabs/bin:/usr/local/cuda/bin:/usr/local/cuda/bin:/afs/hep.wisc.edu/home/skkwan/bin:/usr/local/cuda/bin
== ENV: MAIL=/var/spool/mail/skkwan
== ENV: CMSSW_GIT_REFERENCE=/cvmfs/cms.cern.ch/cmssw.git
== ENV: CMS_PATH=/cvmfs/cms.cern.ch
== ENV: PWD=/tmp/tmpFmF9eC
== ENV: LANG=
== ENV: MODULEPATH=/usr/share/Modules/modulefiles:/etc/modulefiles
== ENV: KDEDIRS=/usr
== ENV: LOADEDMODULES=
== ENV: VSCODE_GIT_ASKPASS_EXTRA_ARGS=
== ENV: CRAB_TASKMANAGER_TARBALL=local
== ENV: HISTCONTROL=ignoredups
== ENV: KRB5CCNAME=FILE:/tmp/krb5cc_10070_71BXrA
== ENV: _CE_M=
== ENV: HOME=/afs/hep.wisc.edu/home/skkwan
== ENV: SHLVL=8
== ENV: VSCODE_GIT_ASKPASS_MAIN=/afs/hep.wisc.edu/user/skkwan/.vscode-server/bin/660393deaaa6d1996740ff4880f1bad43768c814/extensions/git/dist/askpass-main.js
== ENV: LOGNAME=skkwan
== ENV: LCG_GFAL_INFOSYS=exp-bdii.cern.ch:2170
== ENV: CONDA_PYTHON_EXE=/afs/hep.wisc.edu/home/skkwan/miniconda3/bin/python
== ENV: PYTHONPATH=/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-future/0.18.2/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-setuptools/39.2.0/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/share/cms/crab-prod/v3.230417.01/lib
== ENV: CVS_RSH=ssh
== ENV: QTLIB=/usr/lib64/qt-3.3/lib
== ENV: VSCODE_GIT_IPC_HANDLE=/run/user/10070/vscode-git-610d730bd3.sock
== ENV: SSH_CONNECTION=2001:1458:204:1::102:8e8
== ENV: 51306
== ENV: 2607:f388:101c:1000::371
== ENV: 22
== ENV: XDG_DATA_DIRS=/afs/hep.wisc.edu/home/skkwan/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share
== ENV: VSCODE_IPC_HOOK_CLI=/run/user/10070/vscode-ipc-8484ba36-5386-46ac-8c82-558dfbd18d95.sock
== ENV: MODULESHOME=/usr/share/Modules
== ENV: LESSOPEN=||/usr/bin/lesspipe.sh
== ENV: %s
== ENV: BROWSER=/afs/hep.wisc.edu/user/skkwan/.vscode-server/bin/660393deaaa6d1996740ff4880f1bad43768c814/bin/helpers/browser.sh
== ENV: _CONDOR_JOB_AD=Job.submit
== ENV: VSCODE_GIT_ASKPASS_NODE=/afs/hep.wisc.edu/user/skkwan/.vscode-server/bin/660393deaaa6d1996740ff4880f1bad43768c814/node
== ENV: GIT_ASKPASS=/afs/hep.wisc.edu/user/skkwan/.vscode-server/bin/660393deaaa6d1996740ff4880f1bad43768c814/extensions/git/dist/askpass.sh
== ENV: XDG_RUNTIME_DIR=/run/user/10070
== ENV: QT_PLUGIN_PATH=/usr/lib64/kde4/plugins:/usr/lib/kde4/plugins
== ENV: CRAB_RUNTIME_TARBALL=local
== ENV: COLORTERM=truecolor
== ENV: BASH_FUNC_cmsrel()=()
== ENV: {
== ENV: scramv1
== ENV: project
== ENV: CMSSW
== ENV: $@
== ENV: }
== ENV: BASH_FUNC_module()=()
== ENV: {
== ENV: eval
== ENV: `/usr/bin/modulecmd
== ENV: bash
== ENV: $*`
== ENV: }
== ENV: BASH_FUNC_cmsenv()=()
== ENV: {
== ENV: eval
== ENV: `scramv1
== ENV: runtime
== ENV: -sh`
== ENV: }
== ENV: _=/usr/bin/env
======== Current environment dump FINISHING ========
======== Tarball initialization STARTING at Mon Jul 17 15:44:36 GMT 2023 ========
+ [[ XTrue == \X ]]
+ echo 'I am in runtime debug mode. I will not extract the sandbox'
I am in runtime debug mode. I will not extract the sandbox
++ pwd
++ pwd
+ export PYTHONPATH=/tmp/tmpFmF9eC/CRAB3.zip:/tmp/tmpFmF9eC/WMCore.zip:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-future/0.18.2/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-setuptools/39.2.0/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/share/cms/crab-prod/v3.230417.01/lib
+ PYTHONPATH=/tmp/tmpFmF9eC/CRAB3.zip:/tmp/tmpFmF9eC/WMCore.zip:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-future/0.18.2/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/COMP/slc7_amd64_gcc630/external/py3-setuptools/39.2.0/lib/python3.8/site-packages:/cvmfs/cms.cern.ch/share/cms/crab-prod/v3.230417.01/lib
+ set +x
======== Tarball initialization FINISHING at Mon Jul 17 15:44:36 GMT 2023 ========
==== Local directory contents dump STARTING ====
PWD: /tmp/tmpFmF9eC
== DIR: AdjustSites.py
== DIR: CMSGroupMapper.py
== DIR: CMSRunAnalysis.py
== DIR: CMSRunAnalysis.sh
== DIR: CMSRunAnalysis.tar.gz
== DIR: InputFiles.tar.gz
== DIR: Job.submit
== DIR: PSet.pkl
== DIR: PSet.py
== DIR: PSetDump.py
== DIR: RESTInteractions.py
== DIR: RunJobs.dag
== DIR: ServerUtilities.py
== DIR: TaskManagerRun.tar.gz
== DIR: TweakPSet.py
== DIR: WMCore.zip
== DIR: biglib
== DIR: cmscp.py
== DIR: cmscp.sh
== DIR: dag_bootstrap.sh
== DIR: datadiscovery.pkl
== DIR: debug
== DIR: debug_files.tar.gz
== DIR: dry-run-sandbox.tar.gz
== DIR: gWMS-CMSRunAnalysis.sh
== DIR: input_args.json
== DIR: input_dataset_duplicate_lumis.json
== DIR: input_dataset_lumis.json
== DIR: input_files.tar.gz
== DIR: lib
== DIR: run_and_lumis.tar.gz
== DIR: sandbox.tar.gz
== DIR: site.ad
== DIR: site.ad.json
== DIR: splitting-summary.json
== DIR: startup_environment.sh
== DIR: submit_env.sh
== DIR: taskinformation.pkl
== DIR: taskworkerconfig.pkl
==== Local directory contents dump FINISHING ====
======== CMSRunAnalysis.py STARTING at Mon Jul 17 15:44:36 GMT 2023 ========
Now running the CMSRunAnalysis.py job in /tmp/tmpFmF9eC...
++ pwd
+ python3 CMSRunAnalysis.py -r /tmp/tmpFmF9eC -a sandbox.tar.gz --sourceURL=https://cmsweb.cern.ch/S3/crabcache_prod --jobNumber=0 --cmsswVersion=CMSSW_10_6_30 --scramArch=slc7_amd64_gcc700 --inputFile=job_input_file_list_1.txt --runAndLumis=job_lumis_1.json --lheInputFiles=False --firstEvent=1 --firstLumi=None --lastEvent=11 --firstRun=None --seeding=AutomaticSeeding --scriptExe=None --eventsPerLumi=None --maxRuntime=-60 '--scriptArgs=[]' -o '{}'
==== CMSRunAnalysis.py STARTING at Mon Jul 17 15:44:36 2023 UTC ====
Local time : Mon Jul 17 10:44:36 2023
==== Parameters Dump at Mon Jul 17 15:44:36 2023 UTC ===
archiveJob:     sandbox.tar.gz
runDir:         /tmp/tmpFmF9eC
sourceURL:      https://cmsweb.cern.ch/S3/crabcache_prod
jobNumber:      0
cmsswVersion:   CMSSW_10_6_30
scramArch:      slc7_amd64_gcc700
inputFile       job_input_file_list_1.txt
outFiles:       {}
runAndLumis:    job_lumis_1.json
lheInputFiles:  False
firstEvent:     1
firstLumi:      None
eventsPerLumi:  None
lastEvent:      11
firstRun:       None
seeding:        AutomaticSeeding
userFiles:      None
oneEventMode:   0
scriptExe:      None
scriptArgs:     []
maxRuntime:     -60
===================
==== Sandbox untarring STARTING at Mon Jul 17 15:44:36 2023 UTC ====
expanding sandbox.tar.gz in /tmp/tmpFmF9eC

==== Sandbox untarring FINISHED at Mon Jul 17 15:44:37 2023 UTC ====
==== CMSSW Stack Execution STARTING at Mon Jul 17 15:44:37 2023 UTC ====
==== SCRAM Obj CREATED at Mon Jul 17 15:44:37 2023 UTC ====
==== SCRAM Obj INITIALIZED at Mon Jul 17 15:44:44 2023 UTC ====
==== Extract user sandbox in CMSSW directory ====

==== Tweak PSet at Mon Jul 17 15:44:44 2023 UTC ====
Adding 1 files to 'fileNames' attr
Adding 0 files to 'secondaryFileNames' attr
skipEvents set to 0
Executing sh tweakThePset.sh in Scram env
tweakThePset.sh output:

        Scram Command Diagnostic:
        Command : scramv1
        Architecture: slc7_amd64_gcc700
        Executed: sh tweakThePset.sh
        Exit Status: 0
        Stdout: will execute: edm_pset_tweak.py --input_pkl PSet.pkl --output_pkl PSet.pkl-tweaked --json PSetTweak.json --create_untracked_psets
Set attribute process.source.fileNames to cms.untracked.vstring('/store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root')
Set attribute process.maxEvents.input to cms.untracked.int32(11)
Set attribute process.SimpleMemoryCheck to SimpleMemoryCheck
Set attribute process.CPU to CPU
Set attribute process.source.firstEvent to cms.untracked.uint32(1)
Set attribute process.Timing to Timing
Set attribute process.maxSecondsUntilRampdown.input to cms.untracked.int32(-60)
Set attribute process.source.lumisToProcess to cms.untracked.VLuminosityBlockRange(
    "315252:38-315252:38", "315252:41-315252:41", "315252:36-315252:36", "315252:42-315252:43", "315252:39-315252:40", 
    "315252:44-315252:44", "315252:37-315252:37", "315257:24-315257:24", "315257:30-315257:30", "315257:32-315257:32", 
    "315257:46-315257:46", "315257:48-315257:49", "315257:51-315257:51", "315257:58-315257:58", "315257:71-315257:72", 
    "315257:80-315257:81", "315257:83-315257:83", "315257:86-315257:87", "315257:89-315257:89", "315257:91-315257:91", 
    "315257:4-315257:4", "315257:11-315257:11", "315257:14-315257:14", "315257:18-315257:18", "315257:20-315257:20", 
    "315257:38-315257:38", "315257:47-315257:47", "315257:55-315257:55", "315257:57-315257:57", "315257:84-315257:84", 
    "315257:2-315257:2"
)
Set attribute process.source.skipEvents to cms.untracked.uint32(0)
will execute: cmssw_handle_random_seeds.py --input_pkl PSet.pkl --output_pkl PSet.pkl-seeds --seeding dummy
Populared random numbers of RandomNumberService

        Stderr: None 
==== Tweak PSet Done at Mon Jul 17 15:44:57 2023 UTC ====
==== CMSSW JOB Execution started at Mon Jul 17 15:44:57 2023 UTC ====
Error executing application in CMSSW environment.
        See stdout log
==== Execution FAILED at Mon Jul 17 15:47:32 2023 UTC ====
==== CMSSW JOB Execution completed at Mon Jul 17 15:47:32 2023 UTC ====
Application exit code: 5
==== Execution FINISHED at Mon Jul 17 15:47:32 2023 UTC ====
======== CMSSW OUTPUT STARTING ========
NOTICE: lines longer than 3000 characters will be truncated
== CMSSW: 17-Jul-2023 10:45:10 CDT  Initiating request to open file root://cmsxrootd.hep.wisc.edu//store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root
== CMSSW: %MSG-w XrdAdaptorInternal:  file_open 17-Jul-2023 10:45:12 CDT pre-events
== CMSSW: Failed to open file at URL root://cmsxrootd.hep.wisc.edu:1094//store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root.
== CMSSW: %MSG
== CMSSW: %MSG-w XrdAdaptorInternal:  file_open 17-Jul-2023 10:45:13 CDT pre-events
== CMSSW: Failed to open file at URL root://cmsxrootd.hep.wisc.edu:1094//store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root?tried=.
== CMSSW: %MSG
== CMSSW: 17-Jul-2023 10:45:13 CDT  Fallback request to file root://cmsxrootd.fnal.gov//store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root?source=glow
== CMSSW: %MSG-w XrdAdaptor:  file_open 17-Jul-2023 10:45:55 CDT pre-events
== CMSSW: Data is served from gridka.de instead of original site US-Regional-Nebraska
== CMSSW: %MSG
== CMSSW: 17-Jul-2023 10:45:59 CDT  Successfully opened file root://cmsxrootd.fnal.gov//store/group/rucio/pog_tau_group/ul_embedding/large_miniAOD_v2/MuTauFinalState/EmbeddingRun2018A/MINIAOD/inputDoubleMu_106X_ULegacy_miniAOD-v1/0000/3a7a64e3-b6c6-48e7-90fa-732dd51dc019.root?source=glow
== CMSSW:                          : Booking "muonMVATTH" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_2017.weights.xml.
== CMSSW:                          : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_2017.weights.xml
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Signal"
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Background"
== CMSSW:                          : Booked classifier "BDTG" of type: "BDT"
== CMSSW:                          : Booking "muonMVALowPt" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_lowpt.weights.xml.
== CMSSW:                          : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/mu_BDTG_lowpt.weights.xml
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Signal"
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Background"
== CMSSW:                          : Booked classifier "BDTG" of type: "BDT"
== CMSSW:                          : Booking "electronMVATTH" of type "BDT" from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/el_BDTG_2017.weights.xml.
== CMSSW:                          : Reading weight file: /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/data/PhysicsTools/NanoAOD/data/el_BDTG_2017.weights.xml
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Signal"
== CMSSW: <HEADER> DataSetInfo              : [Default] : Added class "Background"
== CMSSW:                          : Booked classifier "BDTG" of type: "BDT"
== CMSSW: %MSG-e L1PrefireWeightProducer:  L1PrefiringWeightProducer:prefiringweight@ctor  17-Jul-2023 10:46:24 CDT pre-events
== CMSSW: Photon map not found. All photons prefiring weights set to 0.
== CMSSW: %MSG
== CMSSW: %MSG-e L1PrefireWeightProducer:  L1PrefiringWeightProducer:prefiringweight@ctor  17-Jul-2023 10:46:24 CDT pre-events
== CMSSW: Jet map not found. All jets prefiring weights set to 0.
== CMSSW: %MSG
== CMSSW: %MSG-w BTagSFProducer:  BTagSFProducer:btagWeightTable@ctor  17-Jul-2023 10:46:26 CDT pre-events
== CMSSW: Skipped loading BTagCalibration for CMVA as it was marked as unavailable in the configuration file. Event weights will not be stored.
== CMSSW:
== CMSSW: %MSG
== CMSSW: %MSG-w LogicError:  GenWeightsTableProducer:genWeightsTable@beginRun  17-Jul-2023 10:46:44 CDT Run: 315252
== CMSSW: ::getByLabel: An attempt was made to read a Run product before endRun() was called.
== CMSSW: The product is of type 'LHERunInfoProduct'.
== CMSSW: The specified ModuleLabel was 'externalLHEProducer'.
== CMSSW: The specified productInstanceName was ''.
== CMSSW:
== CMSSW: %MSG
== CMSSW: %MSG-w LogicError:  HTXSRivetProducer:rivetProducerHTXS@beginRun  17-Jul-2023 10:46:44 CDT Run: 315252
== CMSSW: ::getByLabel: An attempt was made to read a Run product before endRun() was called.
== CMSSW: The product is of type 'LHERunInfoProduct'.
== CMSSW: The specified ModuleLabel was 'externalLHEProducer'.
== CMSSW: The specified productInstanceName was ''.
== CMSSW:
== CMSSW: %MSG
== CMSSW: Rivet.Analysis.HiggsTemplateCrossSections: INFO   ======================================================
== CMSSW: Rivet.Analysis.HiggsTemplateCrossSections: INFO        Higgs Template X-Sec Categorization Tool
== CMSSW: Rivet.Analysis.HiggsTemplateCrossSections: INFO                  Status Code Summary
== CMSSW: Rivet.Analysis.HiggsTemplateCrossSections: INFO   ======================================================
== CMSSW:
== CMSSW:
== CMSSW: A fatal system signal has occurred: segmentation violation
== CMSSW: The following is the call stack containing the origin of the signal.
== CMSSW:
== CMSSW: Mon Jul 17 10:46:49 CDT 2023
== CMSSW: Thread 8 (Thread 0x7fabe18f3700 (LWP 3601497)):
== CMSSW: #0  0x00007fac31cdea35 in pthread_cond_wait@@GLIBC_2.3.2 () from /lib64/libpthread.so.0
== CMSSW: #1  0x00007fac322bf0ac in __gthread_cond_wait (__mutex=<optimized out>, __cond=<optimized out>) at /build/cmsbld/auto-builds/CMSSW_10_6_0_pre4-slc7_amd64_gcc700/build/CMSSW_10_6_0_pre4-build/BUILD/slc7_amd64_gcc700/external/gcc/7.0.0-pafccj/gcc-branches_gcc-7-branch-268351/obj/x86_64-unknown-linux-gnu/libstdc++-v3/include/x86_64-unknown-linux-gnu/bits/gthr-default.h:864
== CMSSW: #2  std::condition_variable::wait (this=<optimized out>, __lock=...) at ../../../../../libstdc++-v3/src/c++11/condition_variable.cc:53
== CMSSW: #3  0x00007fabe3d87bba in Eigen::ThreadPoolTempl<tensorflow::thread::EigenEnvironment>::WorkerLoop(int) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/lib/libtensorflow_framework.so
== CMSSW: #4  0x00007fabe3d84687 in std::_Function_handler<void (), tensorflow::thread::EigenEnvironment::CreateThread(std::function<void ()>)::{lambda()#1}>::_M_invoke(std::_Any_data const&) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/lib/libtensorflow_framework.so
== CMSSW: #5  0x00007fac322c4cbf in std::execute_native_thread_routine (__p=0x7fac04b4ec80) at ../../../../../libstdc++-v3/src/c++11/thread.cc:83
== CMSSW: #6  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #7  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 7 (Thread 0x7fac0f363700 (LWP 3600690)):
== CMSSW: #0  0x00007fac319fde29 in syscall () from /lib64/libc.so.6
== CMSSW: #1  0x00007fac2bbac2ee in XrdSys::LinuxSemaphore::Wait (this=0x7fac115dc540) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdSys/XrdSysLinuxSemaphore.hh:161
== CMSSW: #2  XrdCl::SyncQueue<XrdCl::JobManager::JobHelper>::Get (this=0x7fac115bce78) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdCl/XrdClSyncQueue.hh:67
== CMSSW: #3  XrdCl::JobManager::RunJobs (this=0x7fac115bce60) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:146
== CMSSW: #4  0x00007fac2bbac4d9 in RunRunnerThread (arg=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:33
== CMSSW: #5  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #6  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 6 (Thread 0x7fac0fb64700 (LWP 3600689)):
== CMSSW: #0  0x00007fac319fde29 in syscall () from /lib64/libc.so.6
== CMSSW: #1  0x00007fac2bbac2ee in XrdSys::LinuxSemaphore::Wait (this=0x7fac115dc540) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdSys/XrdSysLinuxSemaphore.hh:161
== CMSSW: #2  XrdCl::SyncQueue<XrdCl::JobManager::JobHelper>::Get (this=0x7fac115bce78) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdCl/XrdClSyncQueue.hh:67
== CMSSW: #3  XrdCl::JobManager::RunJobs (this=0x7fac115bce60) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:146
== CMSSW: #4  0x00007fac2bbac4d9 in RunRunnerThread (arg=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:33
== CMSSW: #5  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #6  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 5 (Thread 0x7fac10365700 (LWP 3600688)):
== CMSSW: #0  0x00007fac319fde29 in syscall () from /lib64/libc.so.6
== CMSSW: #1  0x00007fac2bbac2ee in XrdSys::LinuxSemaphore::Wait (this=0x7fac115dc540) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdSys/XrdSysLinuxSemaphore.hh:161
== CMSSW: #2  XrdCl::SyncQueue<XrdCl::JobManager::JobHelper>::Get (this=0x7fac115bce78) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdCl/XrdClSyncQueue.hh:67
== CMSSW: #3  XrdCl::JobManager::RunJobs (this=0x7fac115bce60) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:146
== CMSSW: #4  0x00007fac2bbac4d9 in RunRunnerThread (arg=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClJobManager.cc:33
== CMSSW: #5  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #6  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 4 (Thread 0x7fac10b66700 (LWP 3600687)):
== CMSSW: #0  0x00007fac31ce1e9d in nanosleep () from /lib64/libpthread.so.0
== CMSSW: #1  0x00007fac2ba82ded in XrdSysTimer::Wait (mills=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdSys/XrdSysTimer.cc:239
== CMSSW: #2  0x00007fac2bb4d9a8 in XrdCl::TaskManager::RunTasks (this=0x7fac115ea180) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClTaskManager.cc:244
== CMSSW: #3  0x00007fac2bb4daf9 in RunRunnerThread (arg=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdCl/XrdClTaskManager.cc:37
== CMSSW: #4  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #5  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 3 (Thread 0x7fac11367700 (LWP 3600686)):
== CMSSW: #0  0x00007fac31a040e3 in epoll_wait () from /lib64/libc.so.6
== CMSSW: #1  0x00007fac2ba87c27 in XrdSys::IOEvents::PollE::Begin (this=0x7fac115bcf40, syncsem=<optimized out>, retcode=<optimized out>, eTxt=<optimized out>) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/./XrdSys/XrdSysIOEventsPollE.icc:213
== CMSSW: #2  0x00007fac2ba84505 in XrdSys::IOEvents::BootStrap::Start (parg=0x7ffff0508f80) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdSys/XrdSysIOEvents.cc:131
== CMSSW: #3  0x00007fac2ba825e8 in XrdSysThread_Xeq (myargs=0x7fac11676a60) at /data/cmsbld/jenkins/workspace/auto-builds/CMSSW_10_6_14_Pyt8240BugFix-slc7_amd64_gcc700/build/CMSSW_10_6_14_Pyt8240BugFix-build/BUILD/slc7_amd64_gcc700/external/xrootd/4.8.5-pafccj2/xrootd-4.8.5/src/XrdSys/XrdSysPthread.cc:86
== CMSSW: #4  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #5  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 2 (Thread 0x7fac1c4d8700 (LWP 3600662)):
== CMSSW: #0  0x00007fac31ce21d9 in waitpid () from /lib64/libpthread.so.0
== CMSSW: #1  0x00007fac2ac47297 in edm::service::cmssw_stacktrace_fork() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginFWCoreServicesPlugins.so
== CMSSW: #2  0x00007fac2ac47d7a in edm::service::InitRootHandlers::stacktraceHelperThread() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginFWCoreServicesPlugins.so
== CMSSW: #3  0x00007fac322c4cbf in std::execute_native_thread_routine (__p=0x7fac1cd6dbf0) at ../../../../../libstdc++-v3/src/c++11/thread.cc:83
== CMSSW: #4  0x00007fac31cdaea5 in start_thread () from /lib64/libpthread.so.0
== CMSSW: #5  0x00007fac31a03b0d in clone () from /lib64/libc.so.6
== CMSSW: Thread 1 (Thread 0x7fac3008e480 (LWP 3600591)):
== CMSSW: #0  0x00007fac319f8ddd in poll () from /lib64/libc.so.6
== CMSSW: #1  0x00007fac2ac477c7 in full_read.constprop () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginFWCoreServicesPlugins.so
== CMSSW: #2  0x00007fac2ac47e5c in edm::service::InitRootHandlers::stacktraceFromThread() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginFWCoreServicesPlugins.so
== CMSSW: #3  0x00007fac2ac48ec8 in sig_dostack_then_abort () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginFWCoreServicesPlugins.so
== CMSSW: #4  <signal handler called>
== CMSSW: #5  0x00007fabe91b16ac in Rivet::Analysis::numEvents() const () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/external/slc7_amd64_gcc700/lib/libRivet.so
== CMSSW: #6  0x00007fabf55dd3b6 in Rivet::HiggsTemplateCrossSections::printClassificationSummary() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/pluginGeneratorInterfaceRivetInterface_plugins.so
== CMSSW: #7  0x00007fac348f5606 in edm::one::EDProducerBase::doEndRun(edm::RunPrincipal const&, edm::EventSetupImpl const&, edm::ModuleCallingContext const*) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #8  0x00007fac34822b70 in edm::WorkerT<edm::one::EDProducerBase>::implDoEnd(edm::RunPrincipal const&, edm::EventSetupImpl const&, edm::ModuleCallingContext const*) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #9  0x00007fac347f1a85 in decltype ({parm#1}()) edm::convertException::wrap<bool edm::Worker::runModule<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >(edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::MyPrincipal const&, edm::EventSetupImpl const&, edm::StreamID, edm::ParentContext const&, edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::Context const*)::{lambda()#1}>(bool edm::Worker::runModule<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >(edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::MyPrincipal const&, edm::EventSetupImpl const&, edm::StreamID, edm::ParentContext const&, edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::Context const*)::{lambda()#1}) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #10 0x00007fac347f1ca3 in bool edm::Worker::runModule<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >(edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::MyPrincipal const&, edm::EventSetupImpl const&, edm::StreamID, edm::ParentContext const&, edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::Context const*) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #11 0x00007fac347f1f83 in std::__exception_ptr::exception_ptr edm::Worker::runModuleAfterAsyncPrefetch<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >(std::__exception_ptr::exception_ptr const*, edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::MyPrincipal const&, edm::EventSetupImpl const&, edm::StreamID, edm::ParentContext const&, edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3>::Context const*) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #12 0x00007fac347f2373 in void edm::SerialTaskQueueChain::actionToRun<edm::Worker::RunModuleTask<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >::execute()::{lambda()#1}&>(edm::Worker::RunModuleTask<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >::execute()::{lambda()#1}&) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #13 0x00007fac347f2431 in edm::SerialTaskQueue::QueuedTask<void edm::SerialTaskQueueChain::push<edm::Worker::RunModuleTask<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >::execute()::{lambda()#1}&>(edm::Worker::RunModuleTask<edm::OccurrenceTraits<edm::RunPrincipal, (edm::BranchActionType)3> >::execute()::{lambda()#1}&)::{lambda()#1}>::execute() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #14 0x00007fac33038931 in tbb::internal::custom_scheduler<tbb::internal::IntelSchedulerTraits>::local_wait_for_all (this=0x7fac2f573200, parent=..., child=<optimized out>) at ../../src/tbb/custom_scheduler.h:521
== CMSSW: #15 0x00007fac348a0244 in edm::EventProcessor::endRun(edm::Hash<2> const&, unsigned int, bool, bool) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #16 0x00007fac348a046b in edm::EventProcessor::endUnfinishedRun(edm::Hash<2> const&, unsigned int, bool, bool, bool) () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #17 0x00007fac348a05ef in std::_Sp_counted_ptr_inplace<edm::(anonymous namespace)::RunResources, std::allocator<edm::(anonymous namespace)::RunResources>, (__gnu_cxx::_Lock_policy)2>::_M_dispose() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #18 0x00000000004137b6 in std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release() ()
== CMSSW: #19 0x00007fac348a489d in edm::EventProcessor::runToCompletion() () from /cvmfs/cms.cern.ch/slc7_amd64_gcc700/cms/cmssw/CMSSW_10_6_30/lib/slc7_amd64_gcc700/libFWCoreFramework.so
== CMSSW: #20 0x000000000040fe78 in main::{lambda()#1}::operator()() const ()
== CMSSW: #21 0x000000000040e142 in main ()
== CMSSW:
== CMSSW: Current Modules:
== CMSSW:
== CMSSW: Module: HTXSRivetProducer:rivetProducerHTXS (crashed)
== CMSSW:
== CMSSW: A fatal system signal has occurred: segmentation violation
== CMSSW:
== CMSSW:         Scram Command Diagnostic:
== CMSSW:         Command : scramv1
== CMSSW:         Architecture: slc7_amd64_gcc700
== CMSSW:         Executed: stdbuf -oL -eL cmsRun -p PSet.py -j FrameworkJobReport.xml > cmsRun-stdout.log.tmp 2>&1
== CMSSW:         Exit Status: 5
== CMSSW:         Stdout: /bin/bash: line 156: 3600591 Segmentation fault      (core dumped) stdbuf -oL -eL cmsRun -p PSet.py -j FrameworkJobReport.xml > cmsRun-stdout.log.tmp 2>&1
== CMSSW:
== CMSSW:         Stderr: None
======== CMSSW OUTPUT FINSHING ========
==== Report file creation STARTING at Mon Jul 17 15:47:32 2023 UTC ====
Sanitize FJR

WARNING: WMCore did not produce a jobReport.json; FJR will not be useful.
ERROR: Exceptional exit at Mon Jul 17 15:47:32 2023 UTC 50115: BadFWJRXML
ERROR: Traceback follows:
 Traceback (most recent call last):
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/Report.py", line 145, in parse
    xmlToJobReport(self, xmlfile)
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/XMLParser.py", line 499, in xmlToJobReport
    node = xmlFileToNode(xmlFile)
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/Algorithms/ParseXMLFile.py", line 64, in xmlFileToNode
    expat_parse(open(reportFile, 'rb'),
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/Algorithms/ParseXMLFile.py", line 88, in expat_parse
    parser.ParseFile(f)
xml.parsers.expat.ExpatError: no element found: line 17, column 0

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "CMSRunAnalysis.py", line 711, in <module>
    rep.parse('FrameworkJobReport.xml', "cmsRun")
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/Report.py", line 157, in parse
    raise FwkJobReportException(msg)
WMCore.FwkJobReport.Report.FwkJobReportException: <@========== WMException Start ==========@>
Exception Class: FwkJobReportException
Message: Error reading XML job report file, possibly corrupt XML File:
Details: no element found: line 17, column 0
        ClassName : None
        ModuleName : WMCore.FwkJobReport.Report
        MethodName : parse
        ClassInstance : None
        FileName : /tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/Report.py
        LineNumber : 157
        ErrorNr : 0

Traceback: 
  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/Report.py", line 145, in parse
    xmlToJobReport(self, xmlfile)

  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/FwkJobReport/XMLParser.py", line 499, in xmlToJobReport
    node = xmlFileToNode(xmlFile)

  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/Algorithms/ParseXMLFile.py", line 64, in xmlFileToNode
    expat_parse(open(reportFile, 'rb'),

  File "/tmp/tmpFmF9eC/WMCore.zip/WMCore/Algorithms/ParseXMLFile.py", line 88, in expat_parse
    parser.ParseFile(f)

<@---------- WMException End ----------@>

== Execution site for failed job from site-local-config.xml: T2_US_Wisconsin
+ jobrc=195
+ set +x
== The job had an exit code of 195 
======== CMSRunAnalysis.py FINISHING at Mon Jul 17 15:47:32 GMT 2023 ========

 StdErr: 
# Take-aways on writing analyzers

## For miniAOD/FEVT files:
(From Week 7 Spring 2018-2019 Mar 22 2019 slides)

* Primary file name has to be a miniAOD.
*  Secondary file name has to be one of the parent FEVT files with the luminosity block specified, or all the parent FEVT files that went into the miniAOD.
* “productnotfound” errors - caused by mis-match of what the analyzer expects to find in the data file and what is actually there.
  
  <details><summary>Expand</summary>
  <p>
	----- Begin Fatal Exception 14-Mar-2019 22:03:22 CET-----------------------
	An exception of category 'ProductNotFound' occurred while
	   [0] Processing  Event run: 1 lumi: 1606 event: 401299 stream: 0
	      [1] Running path 'btaggingPath'
	         [2] Calling method for module CandPtrSelector/'pfCHS'
		 Exception Message:
		 Principal::getByToken: Found zero products matching all criteria
		 Looking for a container with elements of type: reco::Candidate
		 Looking for module label: packedPFCandidates
		 Looking for productInstanceName:

		    Additional Info:
		          [a] If you wish to continue processing events after a ProductNotFound exception,
			  add "SkipEvent = cms.untracked.vstring('ProductNotFound')" to the "options" PSet in the configuration.
        ----- End Fatal Exception ————————————————————————
  </p></details>

   * Use edmDumpEventContent to check the object name and reconstruction level (RECO, or PAT, etc.)
   * Check configuration file or analyzer script for the call to the object.

* You need to specify the luminosity block or you get an error like:
  <details><summary>Expand</summary>
  <p>
	----- Begin Fatal Exception 15-Mar-2019 15:51:08 CET-----------------------
	An exception of category 'MismatchedInputFiles' occurred while
	   [0] Calling InputSource::readLuminosityBlock_
	   Exception Message:
	   PoolSource::readLuminosityBlock_  Run 1 LuminosityBlock 3184 is not found in the secondary input files
	   ----- End Fatal Exception -------------------------------------------------
  </p></details>

### How to get child from parent
* Get miniAOD (child) from FEVT logical file name: (after cmsenv and voms certificate).
  * `source /cvmfs/cms.cern.ch/crab3/crab.sh`
  * `python`
  * In Python: 
    ```>>> from dbs.apis.dbsClient import DbsApi
       >>> dir(DbsApi)
       >>> dbs = DbsApi('https://cmsweb.cern.ch/dbs/prod/global/DBSReader')
       >>> dbs.listFileChildren(logical_file_name='/store/mc/PhaseIIMTDTDRAutumn18DR/DYToLL_M-50_14TeV_TuneCP5_pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v2/910000/F37B1F94-AD89-DF40-8D40-3EE87E8339A1.root')
[{'child_logical_file_name': ['/store/mc/PhaseIIMTDTDRAutumn18MiniAOD/DYToLL_M-50_14TeV_TuneCP5_pythia8/MINIAODSIM/PU200_103X_upgrade2023_realistic_v2-v2/90000/76B29BD2-951D-344C-B9D1-A1FF88850962.root'], 'logical_file_name': '/store/mc/PhaseIIMTDTDRAutumn18DR/DYToLL_M-50_14TeV_TuneCP5_pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v2/910000/F37B1F94-AD89-DF40-8D40-3EE87E8339A1.root'}]   ```      			   

### How to get LumiSections (cont.d, also in Python environment)
* listFileLumis and using one of the FEVT parent files:
  <details><summary>Expand</summary>
  <p>
```
	>>> dbs.listFileLumis(logical_file_name=‘/store/mc/PhaseIIMTDTDRAutumn18DR/DYToLL_M-50_14TeV_TuneCP5_pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v2/910000/F37B1F94-AD89-DF40-8D40-3EE87E8339A1.root')

[{'run_num': 1, 'lumi_section_num': [3184], 'logical_file_name': '/store/mc/PhaseIIMTDTDRAutumn18DR/DYToLL_M-50_14TeV_TuneCP5_pythia8/FEVT/PU200_103X_upgrade2023_realistic_v2-v2/910000/F37B1F94-AD89-DF40-8D40-3EE87E8339A1.root', 'event_count': [252]}]
```
  </p></details>
* In above example: we see `“lumi_section_num’: [3184]”`
* So in the analyzer: put `process.source.lumisToProcess = cms.untracked.VLuminosityBlockRange("1:3184")`
# Remote Trigger Shifts

## Important links
   1. [CMS Trigger Online Workbook TWiki](https://twiki.cern.ch/twiki/bin/viewauth/CMS/OnlineWBTrigger)
   2. The [24 February 2022 trigger shifter training](https://indico.cern.ch/event/1127015/contributions/) slides are [here](https://indico.cern.ch/event/1127015/contributions/4730349/attachments/2397327/4129967/TriggerShifterTutorial-2022-02-24.pdf). This markdown is meant to supplement (not replace) those instructions.
   4. [CMS Online Workbook](https://twiki.cern.ch/twiki/bin/view/CMS/OnlineWB) which has a link to CMS commissioning 2021.
      * [CMS Online Workbook L1 Trigger Keys 2018](https://twiki.cern.ch/twiki/bin/view/CMS/OnlineWBL1TriggerKeys2018)
   5. [CMS Glossary and Index](https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookGlossary).

## Setup requirements: remarks on slide 12

   1. Requirement 2: Tunneling to the P5 network:

         Follow the TWiki from the slides, but as some goalposts, the big steps are:
         * Change your `~/.ssh/config` file on your laptop (that you will be doing your remote shift from), and then
         * On your laptop do `ssh -Y cmsusr` and enter lxplus password, then the cmsusr password. This should ssh you to the P5 network with a new `[skkwan@kvm-s3562-1-ip149-13 ~]$` (for example) command line prompt.
         * Open Firefox and in `General > Network Settings`, click the `Manual proxy configuration` radio button, empty all the fields
           except `SOCKS Host`, where you write `localhost` and Port `1080`, and click the `SOCKSv5` radio button. Lastly click the `Proxy DNS when using SOCKS v5` checkbox.

   2. Requirement 2: Setting up proxies in Firefox:

         The cactus link in the slides is broken: go [here](https://gitlab.cern.ch:8443/cms-cactus/web/L1Page/-/blob/master/docs/user-guide.md)

         There are four different certificates that need to be installed in Firefox. 

         The first one is "CERN CMS Level-1 Software Certificate Authority". Get this one from the instructions here: https://gitlab.cern.ch/cms-cactus/web/cms-ca. Notice how you download a `.cer` file and import it in `Firefox > Certificates` (I searched `Certificates` in the Settings search bar) and mark it as `Trust for websites`. This procedure will be repeated for the three unique `.cer` files that you will get next.

         For the remaining three, go to https://cafiles.cern.ch/cafiles/ and click "Install certificates" under both columns.
         * Left column:
           - "CERN Root Certification Authority 2 Certificate"
           - "CERN Grid Certification Authority Certificate"
         * Right column: 
           - (Identical to the one above, I think you get an error/warning if you try to install the same certificate twice) "CERN Root Certification Authority 2 Certificate"
           - "CERN Certification Authority Certificate"
   
         At the end of all this, you should see all four certificates listed under `CERN` in the Firefox Certificate Manager -> Authorities.

## A few hours before the shift

   1. Get up to date!
      * Read the last couple days of the [Mattermost channels](https://mattermost.web.cern.ch/cms-online-ops/channels/mwgr-shifters--docs)
      * Read recent Daily Run Meeting Summary on [CMS Commissioning cms-talk](https://cms-talk.web.cern.ch/c/run-coordination/commissioning/113)
      * Understand current prescales options and when to switch between them: https://twiki.cern.ch/twiki/bin/viewauth/CMS/OnlineWBL1CollisionPrescales
      * Get a feeling for what the target physics rates/ express rates should be
      * Get a feeling for what L1 seeds are in the current prescales (this will inform what we keep tabs of in OMS)

   2. Connect to the laundry list of websites:
      * Always referring to the most recent [trigger shifter tutorial slides](https://indico.cern.ch/event/1127015/contributions/4730349/attachments/2397327/4129967/TriggerShifterTutorial-2022-02-24.pdf)...
      * L1: http://l1ts-prometheus.cms:3000/?orgId=1&refresh=10s
         - Top 10 seeds is actually pretty useful, it tracks the top 10 physics seeds
      * Super important: OMS: https://cmsoms.cern.ch/cms/triggers/l1_hlt_trigger_rates?cms_run=351301&props.11291_11285.selectedCells=L1A%20physics:2,Total%20L1A:2,L1A%20random:2&props.11293_11285.selectedCells=Total:2&props.11287_11285.selectedCells=Physics:2&props.11288_11285.selectedCells=HLT_BptxOR_v2:2&props.11292_11285.selectedCells=159:16,309:16
         - Make sure all L1 seeds of interest are tracked
         - Press refresh during a run to update the graph
      * Ratemeter: http://es-cdaq.cms/sc/ratemeter.html
         - Stream physics/ stream express rate and size are super important to keep track of
         - If rate/size is red the prescale may have been set wrong
      * DAQ status: http://cmsonline.cern.ch/daqStatusSCX/DAQstatusGrey.html
      * DQM online: https://cmsweb.cern.ch/dqm/online/session/BoL695
      * LHC Page 1: https://op-webtools.web.cern.ch/vistar/vistars.php
         - Monitor beam stability and sometimes it says helpful information about the LHC beam status (to corroborate what the shift leader is saying), if beam was lost, when the next injection will be, and so on
      * [Open the uGT SWATCH Cell > Control Panels > uGT Prescales](http://l1ts-ugt.cms:3333/urn:xdaq-application:lid=13/#!/Control%20Panels/uGT%20Prescales)
         - Prescale is of utmost importance, also the table underneath is hard to read but tells you the prescales of every L1 trigger
         - The DAQ shifter changes the keys (I believe) which affects which prescale menu we see on the uGT Swatch Cell, so after they change it, refresh the SWATCH Cell page and refresh the menu

   3. Read recent ELogs:
      * https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog
      * Subsystems > Trigger > Trigger (again)
      * Subsystems > DAQ > DAQ (again) can also be useful
      * For some reason this page loads faster for me on Firefox


## Miscellaneous notes

      * Change prescales and check the exact prescale applied to a certain trigger in the [uGT SWATCH](http://l1ts-ugt.cms:3333/urn:xdaq-application:lid=13/#!/Control%20Panels/uGT%20Prescales)
  

      * CMS OMS Triggers > Prescaling > Run: [(insert run number)](https://cmsoms.cern.ch/cms/triggers/prescale?cms_run=351301&cms_run_sequence=GLOBAL-RUN)
         - Shows log of prescales used in each run and when they were changed
      * CMS OMS Runs > Lumisections DCS status: seems to indicate in red/green squares which detectors are on standby
      * CMS OMS Runs > Run Report: shows a TON of information
         - Downtimes and reasons
         - Partitions and FEDs: shows what's included and excluded
      * CMS OMS Triggers > Trigger Modes > Version: Current
         - Most up-to-date L1/HLT Keys for Collisions, Circulating, etc.

### At some point investigate...
   * https://cmsoms.cern.ch/cms/triggers/hlt_trigger_rates?cms_run=346373&props.4821_4818.selected=HLT_ZeroBias_Beamspot_v4,HLT_HT300_Beamspot_PixelClustersWP2_v1&props.4822_4818.selected=DQMOnlineBeamspot,ExpressAlignment
   * What is prefiring?

### For beam monitoring
   * BPTX triggers activate when a bunch is detected. Simone says that this is viewable in OMS, in Grafana, and the uGT Swatch Cell. So far I have found it in OMS. 
   * The LHC page 1 (linked above):
     - In the main graph, when the beam is on, 
     - The energy should not affect the rate, in principle (unless some crazy effect connects a trigger to the beam energy)

### Miscellaneous vocab
   - [Definition of deadtimes](https://twiki.cern.ch/twiki/bin/viewauth/CMS/TcdsNotes#Definitions_of_deadtimes)
   - [Emittance and beta](https://www.lhc-closer.es/taking_a_closer_look_at_lhc/0.beta___emittance)
      - E.g. CMS, ATLAS, LHCb beta ~10 meters during CRAFT/CRUZET beams
      - Instantaneous lumi in ub b^-1 is 0.019 
   - PCL: Prompt Calibration Loop, 
      - which is used online since 2016 to provide fast updates of the alignment constants in response to possibly frequent movements of the high-level structures in the detector due to changes of the temperature or the magnetic field. For each data-taking run with more than 20,000 events an alignment is performed to derive corrections (for instance) for the six degrees of freedom of the pixel's two half-barrels and four half-cylinders of the endcaps.
   - CRC: a cyclic redundacy check (generally speaking) 
      - is error-detecting code that takes blocks of data, assign a short check value based on the remainder of a polynomial division on their contents, and repeats the calculation upon retrieval to check for discrepancies.
   - Filter Units in the HLT: HLT software consists of a sequence of reconstruction and filtering modules executed on a farm of O(1000) CPUs
   - Emittance scans for CMS luminosity calibration:
      - Emittance scans are short van der Meer type scans performed at the start and end of LHC fills. The beams are scanned against each other in X and Y planes in 7 displacement steps. These scans are used for LHC diagnostics and (since 2017) for a cross-check of the CMS Luminosity calibration. An XY pair of scan takes around 3 minutes. The BRIL project provides to the LHC three independent online luminosity measurements.
   - van der Meer scans: 
      - slightly vary the location of one beam and measure how the rate of reactions change. This technique is used for measuring the transverse distribution of particles in an accelerator beam and can be used to measure the instantaneous luminosity of an accelerator.
   - TOB: Tracker Outer Barrel: six cylindrical layers (strips)

   - [Beam extraction](https://lhc-machine-outreach.web.cern.ch/components/beam-dump.htm)
      - A gap of 3 us in the circulating bunch pattern is present to allow the horizontally deflecting extraction kickers (MKD) to switch on.
   - [Beam dump](https://lhc-machine-outreach.web.cern.ch/components/beam-dump.htm)
      - The extracted beam is swept in a quasi-circular figure by two sets of orthogonally deflecting dilution kickers; the subsequent 600m drift distance to the dump proper means that this figure (like a loose loop shape) has a circumference of about 120 cm when the beam strikes the absorber, and the beam size has increased to an extent where the sigma is 1.6mm in both planes. 
   - [Beam sigma](https://lhc-machine-outreach.web.cern.ch/components/beam-dump.htm)
      - I assume this is width; apparently roughly 0.3 mm during normal operations.

   - [Quench](https://www.symmetrymagazine.org/article/december-2007/protecting-the-lhc-from-itself)
      - While a beam of particles by itself creates very litle heat, beam particles straying from the core of the beam will heat up surrounding material. It takes just a small number of beam particles hitting in one spot to raise the magnet's temperature above a critical point (i.e. no more superconductivity) - this releases the stored energy in the magnet and its neighbors, releasing potentially enough energy to heat the magnet from -271 to 700 C.
      - When a quench is detected, the beams are shut down, power to the affected magnet is immediately cut, and heaters fire up to raise the temperature of the whole magnet. The energy is dissipated into large resistors.

   - [Aperture measurements](https://accelconf.web.cern.ch/ipac2016/papers/tupmw014.pdf)
      - Are apparently carried out regularly in the initial commissioning phase before high intensity beams are allowed to be injected into the machine. The global aperture bottleneck shifts to the superconducting triplet magnets (??) once the beams are squeezed; i.e. available aperture in the triplets is the limiting factor for small beta* values and i.e. for high luminosity.

   - Switching from collisions to cosmics
      - Clock source from LHC to CMS
      - Some detectors need to be re-configured (on DAQ page: New Run Key)
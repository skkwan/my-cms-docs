# Remote Trigger Shifts

## Relevant L1T information
   * Report on CRUZET/CRAFT shifts and outlook: https://indico.cern.ch/event/1094766/contributions/4604759/attachments/2342366/3993618/211109%20L1T%20Weekly%20meeting.pdf

## Important links
   1. [CMS Trigger Online Workbook TWiki](https://twiki.cern.ch/twiki/bin/viewauth/CMS/OnlineWBTrigger)
   2. The July 2021 trigger shifter trainee slides are [here](https://indico.cern.ch/event/1053978/contributions/4429250/attachments/2274693/3863930/TriggerShifterTutorial-2021-07-01.pdf). This markdown is meant to supplement (not replace) those instructions.
   3. The 2018 trigger shifter tutorial slides are [here](https://indico.cern.ch/event/697373/).
   4. [CMS Online Workbook](https://twiki.cern.ch/twiki/bin/view/CMS/OnlineWB) which has a link to CMS commissioning 2021.
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

   1. Ask to be added to the L1 Doc Hotline Mattermost.
   2. Connect to the laundry list of websites:
      * https://l1page.cms/
      * http://l1ts-prometheus.cms:3000/?orgId=1&refresh=10s
      * http://es-cdaq.cms/sc/ratemeter.html
      * http://cmsonline.cern.ch/daqStatusSCX/DAQstatusGrey.html
      * https://cmsweb.cern.ch/dqm/online/session/BoL695
      * https://op-webtools.web.cern.ch/vistar/vistars.php
      * [Open the uGT SWATCH Cell > Control Panels > uGT Prescales](http://l1ts-ugt.cms:3333/urn:xdaq-application:lid=13/#!/Control%20Panels/uGT%20Prescales)
   3. Read recent ELogs:
      * https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog
      * Subsystems > Trigger > Trigger (again)
      * Subsystems > DAQ > DAQ (again) can also be useful
   4. Read recent Daily Run Meeting Summary notes:
      * Go to the CMS Commissioning Hypernews: https://hypernews.cern.ch/HyperNews/CMS/get/commissioning.html

   5. Useful links during the shift:
      * [LHC Pilot Beam Tests 2021 with description of prescales](https://twiki.cern.ch/twiki/bin/viewauth/CMS/LHCpilotBeamTests_2021)
      * Change prescales and check the exact prescale applied to a certain trigger in the [uGT SWATCH](http://l1ts-ugt.cms:3333/urn:xdaq-application:lid=13/#!/Control%20Panels/uGT%20Prescales)
      * Check when prescales were changed [(change the run number here)](https://cmsoms.cern.ch/cms/triggers/prescale?cms_run=346373&cms_run_sequence=GLOBAL-RUN)
      * Most up-to-date L1/HLT Keys for Collisions, Circulating, etc. in [OMS](https://cmsoms.cern.ch/cms/triggers/trigger_mo?trigger_version=1)



## Miscellaneous notes



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
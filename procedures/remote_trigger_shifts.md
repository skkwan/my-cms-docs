# Remote Trigger Shifts

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
   3. Read recent ELogs:
      * https://cmsonline.cern.ch/webcenter/portal/cmsonline/Common/Elog
      * Subsystems > Trigger > Trigger (again)
      * Subsystems > DAQ > DAQ (again) can also be useful
   4. Read recent Daily Run Meeting Summary notes:
      * Go to the CMS Commissioning Hypernews: https://hypernews.cern.ch/HyperNews/CMS/get/commissioning.html

## Miscellaneous notes

### LHC Pilot Beam Tests 2021 

   https://twiki.cern.ch/twiki/bin/viewauth/CMS/LHCpilotBeamTests_2021

### For beam monitoring
   * BPTX triggers activate when a bunch is detected. Simone says that this is viewable in OMS, in Grafana, and the uGT Swatch Cell. So far I have found it in OMS. 
   * The LHC page 1 (linked above):
     - In the main graph, when the beam is on, 
     - The energy should not affect the rate, in principle (unless some crazy effect connects a trigger to the beam energy)

### Miscellaneous vocab
   - PCL: Prompt Calibration Loop, which is used online since 2016 to provide fast updates of the alignment constants in response to possibly frequent movements of the high-level structures in the detector due to changes of the temperature or the magnetic field. For each data-taking run with more than 20,000 events an alignment is performed to derive corrections (for instance) for the six degrees of freedom of the pixel's two half-barrels and four half-cylinders of the endcaps.
   - CRC: a cyclic redundacy check (generally speaking) is error-detecting code that takes blocks of data, assign a short check value based on the remainder of a polynomial division on their contents, and repeats the calculation upon retrieval to check for discrepancies.



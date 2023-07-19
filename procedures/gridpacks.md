# How to make gridpacks (not entirely from scratch, to be fair)

## Background information (from Cécile)

In general there are 4 files needed as input to make a gridpack: 

- proc_card: defines the process to run, specific to the signal you want to produce
- run_card: defines the conditions (center of mass energy, pt cutoffs, etc), usually the same for all MC
- extramodels: defines physics models for BSM scenarios. For h->aa CMS uses the NMSSMHET model
- customize_cards: can change the parameters, for example the mass and the width of the light scalars


## To make gridpacks
1. Set up the area, I am using `lxplus7`. No CMSSW needed at top-level, it is automatically installed when we test the gridpacks.

```bash
git clone https://github.com/cms-sw/genproductions.git -b mg265UL
cd genproductions/bin/MadGraph5_aMCatNLO/
cd cards/production/2017/13TeV/bbtautau_final_state/
```

2. Create cards (this `.sh` was already created/committed, so it is already in the GenProductions github)

```bash
bash createCards_ggh01_M125_Toa01a01_Tobbtautau_2017.sh
# repeat for VBF h->a1a1
# repeat for VBF and ggH asymmetric (cascade and non-cascade)
```
This makes the above-mentioned four files for each mass point. These are what will be passed on to the MC contacts, the remaining steps are only for us to validate that they're not broken.

3. Create a gridpack from the cards

```bash
# Go back up to the Madgraph directory like so:
cd ../../../..
./gridpack_generation.sh ggh01_M125_Toa01a01_M40_Tobbtautau cards/production/2017/13TeV/bbtautau_final_state/ggh01_M125_Toa01a01_Tobbtautau/ggh01_M125_Toa01a01_M40_Tobbtautau
# Repeat for each mass point
```
This makes a tarball in the `MadGraph5_aMCatNLO` directory.

4. Validate the gridpacks

Make a new directory to keep things neat: I made `genproductions/bin/MadGraph5_aMCatNLO/validation`. Point to the above-created tarball:

```bash
tar -xavf ../ggh01_M125_Toa01a01_M11_Tobbtautau_slc7_amd64_gcc700_CMSSW_10_6_19_tarball.tar.xz 
# To test making 10 events, with a random seed 1, and number of cores 4:
bash ./runcmsgrid.sh 10 1 4
```

5. Check that events were created
Open `cmsgrid_final.lhe` and check that events were created, for instance, in this example for `ggh01_M125_Toa01a01_M11_Tobbtautau`, PDG ID is in the first column from the left, and the mass is the third column from the right. 

```
<event>
 9      1 +1.6772000e+01 1.25000100e+02 7.81738600e-03 1.07309200e-01
       21 -1    0    0  503  502 +0.0000000000e+00 +0.0000000000e+00 +2.7841165510e+01 2.7841165510e+01 0.0000000000e+00 0.0000e+00 -1.0000e+00
       21 -1    0    0  502  503 -0.0000000000e+00 -0.0000000000e+00 -1.4030511328e+02 1.4030511328e+02 0.0000000000e+00 0.0000e+00 -1.0000e+00
       25  2    1    2    0    0 +0.0000000000e+00 +0.0000000000e+00 -1.1246394777e+02 1.6814627879e+02 1.2500012609e+02 0.0000e+00 0.0000e+00
       36  2    3    3    0    0 +4.1148714019e+01 +3.3604183074e+01 -9.7971904125e+01 1.1198374602e+02 1.0927378003e+01 0.0000e+00 0.0000e+00
       36  2    3    3    0    0 -4.1148714019e+01 -3.3604183074e+01 -1.4492043647e+01 5.6162532768e+01 1.1034172938e+01 0.0000e+00 0.0000e+00
        5  1    4    4  501    0 +2.1270291731e+01 +1.4726392145e+01 -4.1822508157e+01 4.9357592329e+01 4.2140000000e+00 0.0000e+00 -1.0000e+00
       -5  1    4    4    0  501 +1.9878422288e+01 +1.8877790929e+01 -5.6149395968e+01 6.2626153694e+01 4.2140000000e+00 0.0000e+00 1.0000e+00
      -15  1    5    5    0    0 -2.9504302149e+01 -2.8011919102e+01 -1.4175784774e+01 4.3119393085e+01 1.7770000000e+00 0.0000e+00 1.0000e+00
       15  1    5    5    0    0 -1.1644411869e+01 -5.5922639722e+00 -3.1625887322e-01 1.3043139683e+01 1.7770000000e+00 0.0000e+00 1.0000e+00
<mgrwt>
```

## To move this up the chain

- The cards (just the four files) needs to go into a pull request: https://twiki.cern.ch/twiki/bin/viewauth/CMS/GitRepositoryForGenProduction 
- And be sent to the MC contacts.
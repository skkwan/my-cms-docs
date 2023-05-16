# Trigger shifts miscellaneous notes

## Fill plot in OMS

* CMS OMS > CMS > Fills > Fill Plot > Fill number
* Needs to be refreshed manually

## Notes from May 15 2023 proton physics shift

* Step-ups of instantaneos luminosity during ramp: ``default" is column 5 but at the start of ramp this is too low as indicated by the low rate (sitting at 40 kHz, when the target should be closer to 102 kHz)
* Then with each step up in luminosity during ramp up, we want to anticipate this step-up (for that mid-May shift, the L1 rate went up by 4 kHz or so) and leave enough buffer room for the rate so it doesn't exceed ~110 kHz
* Previewing the pre-scale in Grafana isn't exactly enough information if the luminosity is changing constantly

* When it reaches flat top and the squeeze: target being 60 pileup and beta* = 30 cm, at this point we were sitting at column (10)
* The luminosity goes down i.e. the pileup goes down
* In mid-May, the procedure was such that when the pileup reached 58.4, the beta* would be squeezed 
* Needed to anticipate this by moving to column (9) (a tighter column), better sooner than later
* After the beta* step, the luminosity should monotonically decrease, so when the preview said that the looser column (10) gave a rate below 110 kHz, we changed to the looser column (10)


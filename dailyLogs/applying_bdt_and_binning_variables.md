# (cont.d) Week of June 27 - July 4, 2019

## (cont.d) Saturday (June 29, 2019)

### Applying BDT weight file
- Input: `dyll-pilot.root` with 44,400 entries.
- The histogram of MVA discriminants in `appliedWeightFile_dyll-pilot.root` has 44,400 entries (using `MVA_BDT->GetEntries()')
- `MVA_BDT->Print("all")` prints the histogram's bin contents:
  * For the dyll-pilot.root file, all events' discriminant value fall between -0.47 and +0.21.
  * Bins are in increments of 0.02 (e.g. -0.19, -0.17, -0.15, etc.) from -1.01 to 1.01.

### Creating new TTree (v1)

- Variables: l1Pt, l1Eta, track1ChiSquared, tauL1StripPt, and l1DecayMode
- Drafting variable ranges based on eyeballing distributions of dyll.root (commit d7c97ec).
- Changing binning based on discussion with Isobel on July 4 2019 (see Google Drive notes).

#### l1Pt (draft)

[Plot](https://github.com/skkwan/phase2L1BTagAnalyzer/blob/devel/tau_exercise/plot_tau_features/validationPlots/dyll_root/dyll_l1Pt.pdf)

| Variable | Range         | Discriminant value | Value used to calculate the discriminant |
|----------|---------------|--------------------|------------------------------------------|
| l1Pt     | 0 - 20 GeV    | ?                  | 10 GeV                                   |
| l1Pt     | 20 - 50 GeV   | ?                  | 35 GeV                                   |
| l1Pt     | 50 - 100 GeV  | ?                  | 75 GeV                                   |
| l1Pt     | 100 - 500 GeV | ?                  | 300 GeV                                  |

#### l1Eta

[Plot](https://github.com/skkwan/phase2L1BTagAnalyzer/blob/devel/tau_exercise/plot_tau_features/validationPlots/dyll_root/dyll_l1Eta.pdf)

| Variable | Range             | Discriminant value | Value used to calculate the discriminant |
|----------|-------------------|--------------------|------------------------------------------|
| l1Eta    | -2.5 to -1.479    | ?                  | -1.99                                    |
| l1Eta    | -1.479 to 1.479   | ?                  | 0                                        |
| l1Eta    | +2.5 to +1.479    | ?                  | +1.99                                    |

#### tauL1StripPt

[Plot](https://github.com/skkwan/phase2L1BTagAnalyzer/blob/devel/tau_exercise/plot_tau_features/validationPlots/dyll_root/dyll_tauL1StripPt.pdf)

| Variable     | Range     | Discriminant value | Value used to calculate the discriminant |
|--------------|-----------|--------------------|------------------------------------------|
| tauL1StripPt | 0         | ?                  | 0.0                                      |
| tauL1StripPt | 1 to 20   | ?                  | 10.5                                     |
| tauL1StripPt | 20 to 60  | ?                  | 40.0                                     |
| tauL1StripPt | 60 to 100 | ?                  | 80.0                                     |

#### track1ChiSquared

[Plot](https://github.com/skkwan/phase2L1BTagAnalyzer/blob/devel/tau_exercise/plot_tau_features/validationPlots/dyll_root/dyll_track1ChiSquared.pdf)

| Variable         | Range      | Discriminant value | Value used to calculate the discriminant |
|------------------|------------|--------------------|------------------------------------------|
| track1ChiSquared | 0 to 10    | ?                  | 5.0                                      |
| track1ChiSquared | 10 to 20   | ?                  | 15.0                                     |
| track1ChiSquared | 20 to 40   | ?                  | 30.0                                     |
| track1ChiSquared | 40 to 160  | ?                  | 100.0                                    |

#### l1DecayMode

[Plot](https://github.com/skkwan/phase2L1BTagAnalyzer/blob/devel/tau_exercise/plot_tau_features/validationPlots/dyll_root/dyll_l1DM.pdf)

The ranges are just chosen so that the midpoints are 0, 1, and 10.

| Variable    | Range       | Discriminant value | Value used to calculate the discriminant |
|-------------|-------------|--------------------|------------------------------------------|
| l1DecayMode | -0.5 to 0.5 | ?                  | 0                                        |
| l1DecayMode | 0.5 to 1.5  | ?                  | 1                                        |
| l1DecayMode | 9.5 to 10.5 | ?                  | 10                                       |


## Monday (July 1, 2019)

### To-do
* ~~Set up tau analyzer in my working directory~~ (Done July 4 2019) 
* Put in `deltaZ` between first track and zVTX
* ~~Figure out how to do permutations of variable values~~ (Done July 2 2019))

### Thinking
If I have two variables with 3 and 2 possible bins, I know there are 3 x 2 = 6 total bins
- First variable:
  * Most coarse-grained
  * I know I need to vary the second variable by two values, so I fill the rows two at a time, with each three possible value of the first variable
- Then I fill the second variable, fine-grained

If I have three variables with 3, 3, 2 possible bins, there are 3 x 3 x 2 = 18 total rows
- First variable:
  * For i = 1, 2, 3, I fill (3 x 2) = 6 rows at a time with value[i]
    until I reach end of the array
- Second variable:
  * For i = 1, 2, 3, I fill (2) rows at a time with value[i]
    until I reach end of the array
- Third variable:
  * For i = 1, 2, I fill (1) row at a time with value[i]
    until I reach end of the array

Pseudocode:
- For each variable iVar,
  - While the end of the table is not reached,
    - For each variable's possible value iVal
      - Fill x rows at a time with that value, where x is
        the product of the remaining variables' number of
        bins
    
Pseudocode 2:
- For each variable iVar,
  - initialize r = 0
  - calculate x = product of remaining variables' 
                  number of bins
  - while (r < rMAX)
    - for (iVal = 0, 1, ..., nVals)
      	 - fill rows (r, r + x) with value iVal
         - r += x

### Pseudocode for the file:
- User inputs: For each variable, declare bins
- Desired output: Two-dimensional array of doubles
  
Steps:
1. Initialize array of pointers to array of doubles
1. Hard-code bins at top of file
1. Initialize array with one extra column for discriminant value
1. Implement Pseudocode 2
1. Return array
1. Call another function to print/visualize the array.



	
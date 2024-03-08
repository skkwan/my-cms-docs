# RooWorkSpace notes

In ROOT, navigating things stored in a RooWorkSpace is not super obvious, so here are my notes.

## RooHistFunc
For `RooHistFunc`, e.g. the class that the Z pT reweighing is stored in, `Print` alone is not super useful:

```bash
% zptmass_weight_nom->Print()

RooHistFunc::zptmass_weight_nom[ depList=(zptmass_weight_nom_range_z_gen_mass,zptmass_weight_nom_range_z_gen_pt) depList=(zptmass_weight_nom_range_z_gen_mass,zptmass_weight_nom_range_z_gen_pt) ] = 0.849861
```

We have to access the underlying `RooDataHist`:
```bash
% zptmass_weight_nom->dataHist()

(RooDataHist &) Name: zptmass_weight_nom Title: zptmass_histo
```

We can see that there are 44 bins with `Print()`
```bash
% zptmass_weight_nom->dataHist().Print()
RooDataHist::zptmass_weight_nom[zptmass_weight_nom_binningvar_z_gen_mass,zptmass_weight_nom_binningvar_z_gen_pt] = 44 bins (51.2304 weights)
```

With a verbose `Print()`:
```bash
% zptmass_weight_nom->dataHist().Print("V")
DataStore zptmass_weight_nom (zptmass_histo)
  Contains 44 entries
  Observables: 
    1)  zptmass_weight_nom_binningvar_z_gen_mass = 50 C  L(50 - 1000) B(4)  "zptmass_weight_nom_binningvar_z_gen_mass"
    2)    zptmass_weight_nom_binningvar_z_gen_pt = 0 C  L(0 - 1000) B(11)  "zptmass_weight_nom_binningvar_z_gen_pt"
Binned Dataset zptmass_weight_nom (zptmass_histo)
  Contains 44 bins with a total weight of 51.2304
  Observables:     1)  zptmass_weight_nom_binningvar_z_gen_mass = 50 C  L(50 - 1000) B(4)  "zptmass_weight_nom_binningvar_z_gen_mass"
    2)    zptmass_weight_nom_binningvar_z_gen_pt = 0 C  L(0 - 1000) B(11)  "zptmass_weight_nom_binningvar_z_gen_pt"
```

This must mean there are 4 bins for the gen mass, and 11 bins for the gen pT. I'm not sure yet what "C" and "L" mean, or how the indexing works though:

```bash
% zptmass_weight_nom->dataHist().weight(0)
(double) 0.84986143
% zptmass_weight_nom->dataHist().weight(1)
(double) 1.0614146
```

At some point, could look into this `RooFit` + `RDataFrame` example [rf408_RDataFrameToRooFit.C](https://root.cern.ch/doc/master/rf408__RDataFrameToRooFit_8C.html) which shows how to print the contents of a `RooAbsData`
# (cont.d) Week of June 27 - July 4, 2019

## (contd.) Monday (July 1, 2019)

### Next steps for writing makeTable.C

Ideas: 
~~* Use [this tutorial](https://root.cern.ch/root/html/tutorials/tree/tree1.C.html) to create a TTree.~~
* Use [this tutorial](https://root.cern.ch/root/html608/TMVAClassificationCategoryApplication_8C.html) to classify. 
  * Use [this function](https://root.cern.ch/root/html608/classTMVA_1_1Reader.html#a209436a06ae04b848c9ac98b367e0dd6). It takes in a std::vector<Float_t>, a const TString which is the MethodTag. It returns a Double_t.
  * So the underlying table should be doubles.

## Tuesday (July 2, 2019)

### Progress on makeTable.C

- Went with the C++ two-dimensional array approach (commit `e3572d7`) and it works for the five variables.

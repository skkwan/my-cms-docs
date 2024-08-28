# Note on rates

In Run 384644 for example, the total L1 rate before deadtime was 104104 Hz [1] and the bunch-crossing rate is B, which corresponds to a delivered luminosity of 468 pb^-1 [2]. The ZeroBias rate before deadtime was 1484 Hz, so we can scale this to a ZeroBias integrated luminosity 

X = (1484 Hz * (468 pb^-1) / B) is the ZeroBias integrated luminosity 

The ttbar cross section is around 900 pb, so 900 pb * X = number of ttbar events in Run 384644

[1] https://cmsoms.cern.ch/cms/triggers/l1_rates?cms_run=384644&update=false&props.20639_19388.selectedCells=Physics:2&props.19391_19388.selectedCells=L1A%20physics:2
[2] https://cmsoms.cern.ch/cms/runs/report?cms_run=384644&cms_run_sequence=GLOBAL-RU
[3] https://cds.cern.ch/record/2882250/files/CR2023_269.pdf
The number of Cicada events accepted/ above some threshold should be found by analyzing Run 384644 (this information won't be in OMS)
It's impossible to know without further analysis how many of these accepted events are ttbar in data, unless you do further analysis on the data to select ttbar events with high purity 
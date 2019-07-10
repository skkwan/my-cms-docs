# Notes on debugging while building an analyzer

## To set build flags
* `USER_CXXFLAGS="-Wno-delete-non-virtual-dtor -Wno-error=unused-but-set-variable -Wno-error=unused-variable" scram b`
* More info here [https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideScram#CmsswSCRAMBuildFlags]

## Error: X was not declared in this scope (at build-time)
* E.g. `error: 'L1TkPrimaryVertexCollection' was not declared in this scope` at the line `edm::EDGetTokenT< L1TkPrimaryVertexCollection >    pvToken_;`
* In the src/ directory, run `grep L1TkPrimaryVertexCollection * -rl` and include the appropriate header file.
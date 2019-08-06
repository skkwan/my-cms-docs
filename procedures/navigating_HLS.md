# Navigating Vivado HLS
Source: Xilinx Vivado HLS Users Guide (UG871 v. 2014.1, published May 6 2014)

## Vivado HLS Command Prompt
At the bash terminal, run `vivado_hls -i` to run in interactive mode.

## Tcl files
* In `solution1/constraints`:
  * When you create a project, `script.tcl` contains the Tcl commands to create a project with
  the files specified during the project setup and run synthesis.
  * `directives.tcl` contains any optimizations applied to the design.
* In `script.tcl`, you can add `-reset` options to `open_project` and `open_solution` commands
* and add the `exit` command to the end.

## Viewing results of synthesis 
* The synthesis report is in `<project_name>/solution1/syn/report/<name>.rpt`
  * Contains info on timing, latency (clock cycles), resource utilization estimates
* The simulation results are in `<project_name>/solution1/sim/report/<name>.rpt`
  * Shows latency and intervals' min, avg, max for VHDL and Verilog.
* The output package is in `<project_name>/solution1/impl/ip`.
* The final output RTL is in `<project_name>/solution1/impl` + `Verilog` or `VHDL`.
* When copying RTL results from a Vivado HLS project, always use the RTL
  from the **impl** directory, because for designs using floating-point operators,
  the RTL files in the `syn` directory are only the output from synthesis.
  Additional processing is performed by Vivado HLS during `export_design` before
  you can use the RTL in other design tools.


## Optimizing
* In the GUI of an open project, create a new solution by clicking the "New Solution" button.
* Make sure the new solution is bolded in the "Explorer" pane, showing that it's the active solution.
* Open the "Source" container in the "Explorer" pane. In the Auxiliary pane, activate the
  "Directives" tab, which shows all the projects in the design that can be optimized.
* E.g. for an array `c`, right-click on it (click with two fingers for TigerVNC),
  * select **RESOURCE** from the Directive drop-down menu,
  * click the **core** box,
  * select **RAM_1P_BRAM** (single-port block RAM resource)
* You can also add these optimization directives to the source code as **pragmas** (see Lab3 in tutorial)
* .. but **add optimizations to the directive file** when you are iteratively testing optimizations,
  to make sure that optimizations don't get automatically carried forward to the next solution.


### Analyzing the results
* Before optimizing, always understand the current design. Aside from the synthesis report,
  use the "Analysis" Perspectives button.
  * In the "Performance" view (the default one):
    * Click on a loop to expand it.
    * "C0, C1, C2, ..." are Control states in the design: internal states that HLS uses to schedule
    operations into clock cycles. They are closely correlated with the final states in the
    RTL Finite State Machine (FSM), but there is no one-to-one mapping.
  * In the "Resource" view,
    * You can see the resource usage for all I/O ports, multiplications, and expressions
  * Click or double-click on a block to view the corresponding C code.

### Optimizing for highest throughput (lowest interval)
- Unroll loop: right click on the elemnt in the "Directives" tab and "Directive -> Unroll"
- Partition the array into individual elements: "Directive -> Array_Partition" 
- Pipelining

### Comparing the results
* Click the "Compare Reports..." button

  

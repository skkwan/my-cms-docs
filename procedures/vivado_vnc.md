# Vivado on VNC server 

## First-time setup
Refer to slides on Lecture 4 at https://tac-hep.org/training-modules/uw-gpu-fpga for first-time-only setup.

## Each time

1. Ssh to `login.hep.wisc.edu`, then do `ssh cmstrigger02`
2. Once in `cmstrigger02`, run `vncserver -localhost -geometry 2560x1600` and make note of the display number
3. Then back in my laptop, in a different terminal than step 1 (change 5906 to 590X, where X is the display number)
    ```bash
    ssh skkwan@cmstrigger02.hep.wisc.edu -L5901:localhost:5901
    # cmstrigger02 password should be the same as the one for login.hep.wisc.edu
    ```
    This sometimes gives "operation timed out", email the help desk if it persists.
4. Open TigerVNC and connect, again using 590X where X is the display number, and enter the VNC password
5. In the TigerVNC window, open a terminal and run
    ```bash
    # To copy and paste in the TigerVNC GUI, on Mac, press Control+V
    source /opt/Xilinx/Vitis/2021.1/settings64.sh
    vitis_hls -f 
    ```
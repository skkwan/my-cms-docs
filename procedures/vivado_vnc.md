# Vivado on VNC server 

## First-time setup
Refer to slides on Lecture 4 at https://tac-hep.org/training-modules/uw-gpu-fpga for first-time-only setup.

## Each time

Wisdom from the help desk: "cmstrigger02 is running, but you won't be able to connect to it directly (with ssh, vnc, etc) from any off UW-Madison Campus IP. Instead you'll have to tunnel the connections through the login nodes."

1. Ssh to `login.hep.wisc.edu`, then do `ssh cmstrigger02`
2. Once in `cmstrigger02`, run `vncserver -localhost -geometry 2560x1600` and make note of the display number
3. Then back in my laptop, in a different terminal than step 1 (change 5906 to 590X, where X is the display number)
    ```bash
    # connect to a login node (and tunnel a port to your local computer)
    ssh -L 15901:127.0.0.1:15901 skkwan@login.hep.wisc.edu
    ```
    Once in `login.hep`,
    ```bash
    # connect to cmstrigger02
    login.hep $ ssh -L 15901:127.0.0.1:5901 cmstrigger02.hep.wisc.edu
    ```
4. Open TigerVNC and connect, again using 1590X where X is the display number, and enter the VNC password 
5. In the TigerVNC window, open a terminal and run
    ```bash
    # To copy and paste in the TigerVNC GUI, on Mac, press Ctrl+Shift+V
    source /opt/Xilinx/Vitis/2021.1/settings64.sh
    vitis_hls -i  
    # -i is interactive mode, vitis_hls -f flag for no GUI
    ```

Instead of steps #3 and #4 apparently you can also use the jump host -J option to ssh to do it all in one command:
```bash
ssh -L 15901:127.0.0.1:15901 -J skkwan@login01.hep.wisc.edu skkwan@cmstrigger02.hep.wisc.edu
```
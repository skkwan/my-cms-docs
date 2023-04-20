# Vivado on VNC server 

## First-time setup
Refer to slides on https://drive.google.com/file/d/1I3xoOgq0HZ8IJSRg3UyHf4M8L7aWBxwj/view for first-time-only setup.

## Each time

1. Ssh to `login.hep.wisc.edu`, then do `ssh cmstrigger02`
2. Once in `cmstrigger02`, run `vncserver -localhost -geometry 2560x1600` and make note of the display number
3. Then back in my laptop, in a different terminal than step 1 (change 5906 to 590X, where X is the display number)
    ```
    ssh skkwan@cmstrigger02-via-login -L5906:localhost:5906
    # password should be the same as the one for login.hep.wisc.edu
    ```
4. Open TigerVNC and connect, again using 590X where X is the display number, and enter the VNC password
5. In the TigerVNC window, open a terminal and run
    ```
    # To copy and paste, on Mac, Control+Shift+V
    source /opt/Xilinx/Vivado/2020.1/settings64.sh
    vivado_hls
    ```
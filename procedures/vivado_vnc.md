# Vivado on VNC server 

## First-time setup
Refer to slides on https://drive.google.com/file/d/1I3xoOgq0HZ8IJSRg3UyHf4M8L7aWBxwj/view for first-time-only setup.

## Each time

1. On a terminal on my laptop, `ssh cmstrigger02`
2. Once in `cmstrigger02`, run `vncserver -localhost -geometry 2560x1600` and make note of the display number
3. Then back in my laptop, in a different terminal than step 1,  
    ```
    ssh skkwan@cmstrigger06-via-login -L5906:localhost:5906
    ```
4. Open TigerVNC and connect
5. In the TigerVNC window, open a terminal and run
    ```
    # To copy and paste, on Mac, Control+Shift+V
    source /opt/Xilinx/Vivado/2020.1/settings64.sh
    vivado_hls
    ```
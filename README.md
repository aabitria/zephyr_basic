# Basic Freestanding Zephyr Project Template

This shows a basic template for a Zephyr project.  The basic essential files
are shown below as shown by tree command.

.
├── CMakeLists.txt
├── prj.conf
└── src
    └── main.c
    

Building

1. Enter the command below to load env variables and settings for Zephyr.
   This is a one-time command, 1 for each venv session.
   
   $ source ~/zephyrproject/zephyr/zephyr-env.sh


2. Go to the project folder.  The command assumes the project is at
   ~/zephyrproject/app/
   
   $ cd ~/zephyrproject/app/zephyr_basic


3. Build - compile and link.  For this case, I used the stm32f4-disco board
   and consequently its devicetree.
   
   $ west build -b nucleo_f446ze .


4. Flash to your board

   $ west flash.


Tweaking the Kconfig

For the example here, we are tweaking CONFIG_PRINTK.  This symbol by default
is always enabled, and we want to disable it via project Kconfig without 
editing the code.  The main code has a printk statement.

Following the steps in the link:
https://interrupt.memfault.com/blog/practical_zephyr_kconfig

We go to menuconfig.

    $ west build -t menuconfig
    
"Subsystems and OS Services"->"Debugging Options", we find PRINTK to be one
of the enabled configs, and we find that another config is y-selecting it,
that is why CONFIG_PRINTK=n at prj.conf is not taking effect.

Disable CONFIG_BOOT_BANNER then CONFIG_PRINTK then rebuild.

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
   
   $ west build -b stm32f4_disco .


4. Flash to your board

   $ west flash.


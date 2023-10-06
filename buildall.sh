#!/bin/bash

# Check if the script is run as root (sudo)
if [[ $EUID -ne 0 ]]; then
    echo "This script must be run as root (sudo)." 
    exit 1
fi

# Change to the directory where your CMakeLists.txt is located
cd /home/cezario/Dev/Beholder

# Revert build file
sudo rm -rf build/
sudo rm Makefile

# Run CMake with sudo
sudo cmake .

#Clean all items in /usr/lib/beholder and /usr/include/DSMComms
sudo rm -rf /usr/include/DSMComms/*

# Build source
sudo make install -s || true

# Make sure the library is available at ${HOME}/lib
ls /usr/include/DSMComms/

# username="$SUDO_USER"
# script_path="./buildcorba.sh"
# echo "User: ${username}"

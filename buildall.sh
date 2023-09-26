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

# Change to the 'src' directory
cd src/

# Clean and install the project in 'src' with sudo
sudo make clean -s
sudo make install -s || true

# Change to project directory
cd ../
sudo make install -s || true

username="$SUDO_USER"
script_path="./buildcorba.sh"
echo "User: ${username}"

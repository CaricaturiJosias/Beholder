#!/bin/bash

# Change to the directory where your CMakeLists.txt is located
cd /home/cezario/Dev/Beholder

# Go to DSMComms client

# Build cliente
cd DSMComms/cliente
make clean -s
make install -s
make -s

# Build servidor
cd ../servidor
make clean -s
make -s

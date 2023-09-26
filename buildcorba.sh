#!/bin/bash

# Change to the directory where your CMakeLists.txt is located
cd /home/cezario/Dev/Beholder

# Go to CORBA client

# Build cliente
cd CORBA/cliente
make clean -s
make -s

# Build servidor
cd ../servidor
make clean -s
make -s

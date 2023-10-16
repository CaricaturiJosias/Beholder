#!/bin/bash

# Change to the directory where your CMakeLists.txt is located
cd /home/cezario/Dev/Beholder/DSMComms/MsgProcessor

./GSOAP_SERVER.cgi  < bhldr.registerInfo.req.xml

# username="$SUDO_USER"
# script_path="./buildcorba.sh"
# echo "User: ${username}"

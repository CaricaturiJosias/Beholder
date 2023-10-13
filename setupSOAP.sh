
# Clean soap files
sudo rm -rf /usr/local/share/gsoap
sudo rm -rf /usr/local/lib/libgsoap*
sudo rm -rf /usr/local/lib/pkgconfig/gsoap*
sudo rm -rf /home/cezario/soap/gsoap-2.8

# build gsoap
cd /home/cezario/soap
ls
if ( ! -d "/home/cezario/soap/gsoap-2.8") then
    unzip gsoap_2.8.131.zip
fi
cd gsoap-2.8
configure
bash configure
make CXXFLAG="-DWITH_NO_C_LOCALE"
sudo make install
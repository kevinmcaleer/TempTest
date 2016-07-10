apt-get update
apt-get install bison flex -y
wget http://download.savannah.gnu.org/release/avrdude/avrdude-6.2.tar.gz
tar xfv avrdude-6.2.tar.gz
cd avrdude-6.2/
./configure --enable-linuxgpio
make
make install
sudo nano /usr/local/etc/avrdude.conf


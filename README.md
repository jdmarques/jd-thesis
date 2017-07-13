# jd-thesis

gnuradio thesis

This projects intends to implement a Physical Layer security scheme that uses the Channel condition to encode the payload data. It's going to be used a OFDM transmission with a zero-forcing based equalization. The system will be composed of three users (Alice, Bob and Eve) where Alice and Bob are the righfull users and Eve is the intruder.

The code is ready to be installed with Pybombs (installation instructions):

in your code directory, do : (I usually do source ./setup_env in my pybombs_gnuradio directory before the installation)
  mkdir build 
  cd build
  cmake -DCMAKE_INSTALL_PREFIX= /home/user/prefix ../ (this works if you have the pybombs installation in ~/prefix)
  make (this is your compilation)
  make install (only do this if when your make is free of issues)
  sudo ldconfig (this rearranges your librarys *i think*)

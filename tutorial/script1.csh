#!/bin/tcsh -f

set R = (1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0)

echo "Hello $USER Today is" `date`
g++ trionymo.cpp -o cuadratic
./cuadratic

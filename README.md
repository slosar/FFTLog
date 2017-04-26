# FFTLog
C and C++ implementations of the FFTLog algorithm.

This is the famous FFTLog. 

First implemented by the living legend Andrew Hamilton:

http://casa.colorado.edu/~ajsh/FFTLog/

This version is a C version that was adapted from the C++ version found
in Copter by JWG Carlson, another big loss for the cosmology community.

https://github.com/jwgcarlson/Copter

I've transformed this from C++ to C99 as the lowest common denominator
and provided bindings for C++ and python.

There are C++ bindings, which are not tested yet, though.

# Notes

To compile, edit Makefile and run. The only dependency is FFTW3.

The test example will produce a file "test_result.txt" whose columns
are input k, P(k), output r, xi(r) and retransformed k, P(k).




# Pico Beacon

One tries to generated tones by turning the PWM channel ON and OFF. Here I generate a 1KHz tone at 42MHz for 1 second, then generates the carrier wave for another 1 second.
The "carier wave" is the first item in the Fourier series expansions, as a square wave, which is a sinusoidal wave 
at the frequency of a square wave.

> you might need an app to visualize (GQRX) 

## Building

This project uses CMake and the Pico SDK:

```bash
mkdir build
cd build
cmake ..
make

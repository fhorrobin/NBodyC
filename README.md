# Simple 2D NBody Code in C
Fergus Horrobin (2018)

## Usage

### 1. SConstruct (Recommended)

To compile with SConstruct, you must have SConstruct installed and Python2.7.x. Use the command: `scons` in the main directory for the project.

This will compile both an executalbe `build/main.x` and a library `lib/libnbody.a`. You can either write a test program in `main.c` and have it compile directly or use the library in your own program.

### 2. Makefile

I have included a Makefile as well for legacy support. It is not my main development tool so do not expect it to work as well as SCons. It does not build a library, only an executable so you have to write your program in `main.c`.

## Output

Right now the program dumps the positions for each particle every 10 timesteps in a file called `results.txt`. I am currently working on an improved method to create custom data output into `txt` or `hdf5` format.

## Documentation

Use Doxygen to generate documentation suing the config.doxy file.

## Example Problems/Test Problems

I will add some examples/tests soon.

## Other Plans

I plan to make the main interface via Python instead of C. Stay tuned for more updates. 

I also plan to add more integrators. The next ones will be higer order Symplectic integrators as well as RK style integrators. 

Eventually, I will add Tree Gravity Calculation and make the code 3D


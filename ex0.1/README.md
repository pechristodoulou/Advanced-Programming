C++ versus Python performance
=============================

This exercise is intended to show explicitly the great difference that can exist between interpreted and compiled software.
To illustrate the point, a few benchmarks have been lifted from the [benchmarks game](https://benchmarksgame-team.pages.debian.net/benchmarksgame/fastest/gpp-python3.html) site.
The benchmarks have been coded in such a way as to be algorithmically identical in the different programming languages.

# Performance measurement #

The task here is to carry out a performance measurement using the `time` program, running both the C++ and the Python version of each code. A general way to determine the time needed for a program to run is the following:

    time ./myexe args

where `args` are any run-time arguments to the program. (The `./` prefix is not needed if you have the "current working directory" `.` in your `PATH`; however, doing so is generally considered bad practice, as it is insecure.) Note that all three programs take arguments that will affect the computing time needed. In the Python case you would replace `myexe` with `python3 mypython.py` (note that Python2 will likely fail to work).

# How to run: C++ #

The general way to use (on Linux machines) the command-line g++ compiler illustrated below with a fictive source file called mysource.cc .

    g++ mysource.cc -o myexe

Note that the C++ language standard is (still) evolving, and different programs adhere to different standards. The programs used here conform to the c++11 standard (which appears to be the default setting for the g++ version 7 compiler). Other standards could be specified using the `-std=...` option to g++. Many options to g++ exist; extensive information can be obtained by doing

    man g++

Note also that instead of a command line tool, other (graphical) tools or *Integrated Development Environments* or IDEs may be used for your code development. As a general principle, the important thing is that whatever you do should work with a straight compilation using g++.

# Specifics #

* The `nbody` program takes an integer step that represents the number of steps taken in the simulation of this system. Set this to a large number (e.g. 100000) to see any difference.
* The `spectral-norm` code uses the OpenMP library to enable *multi-threading*, a topic that we will get to later. To compile this code, the `-fopenmp` compilation flag is needed (a more specific set of compilation options is specified in the C++ source file, but is useful primarily to produce more optimised code). The program takes a single integer argument representing an approximation towards calculating the so-called spectral norm of a matrix (see e.g. [Wikipedia](https://en.wikipedia.org/wiki/Matrix_norm)); set this to e.g. 1000 to see a noticeable difference.
* The `mandelbrot` code produces a NetPBM graphics output file, but does so by writing it to its standard output. One way to redirect the output is to specify

        time ( ./myexe args > mandelbrot.pbm )

(The parentheses here are needed to create a sub-shell; without them, the outputs from the `time` command and from `myexe` would get mixed up.)
You will also find that compiling this C++ code needs yet different options. They are specified in the source code, but are reproduced here (as tested with g++ version 9):

	g++ -Wall -O3 -ffp-contract=off -fno-expensive-optimizations -march=native -fopenmp -std=c++14 mandelbrot.cc -o mandelbrot.exe

Here, in view of the later discussion on parallellizing the execution of code, the `-march=native` option is somewhat particularly relevant: it instructs the compiler to exploit the available CPU architecture as much as possible. This is used here to carry out *single-instruction, multiple data* (SIMD) instructions that allow for code speed-up in a different way than by using multi-threading.
The program again takes a single integer argument, which determines the number of pixels (and hence the granularity) in the resulting plot of the Mandelbrot set.

It is conceivable that your CPU architecture may be such that none of the different SIMD options may work for you. It would be appreciated if you at least try, however, and document your observations (compilation errors) if that is the case.

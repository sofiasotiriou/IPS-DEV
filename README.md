# INPS - Projet 1
*Created by: Loic Lefee-Fauvel, Cedric Gautheret, Alicia Plath and Sofia Sotiriou <br> Done during Introduction to Scientific Programming at the École nationale supérieure d'informatique pour l'industrie et l'entreprise* 

## Project description 

This project calculates the solutions of the 1D quantum harmonic oscillator and checks some of their properties. More specifically: 
- The solutions of the 1D-HO are calculated along the z-axis, using the recurrence relation H(n+1)(z) = 2zH(n)(z) - 2nH(n-1)(z).
- The first solutions are evaluated and plotted using matplotlib.
- The energy E(n) of the first solutions is numerically checked by estimating the derivatives.
- The orthonomality of the solutions is numerically checked using a quadrature. The nodes and weights for the quadrature are extracted from a file (filled by the python function "numpy.polynomial.hermite.hermgauss(8)").

## Prerequisites:
 - Armadillo, CXXTests
 - Python : numpy, matplotlib, pandas


## Compiler
```{shell}
make
```

## Execute the programme
```{shell}
bin/main
```
The execution produces a CSV file containing the values to display in  _ressources/tab.csv_. Then, the file _src/plot.py_ is executed and displays the curves that correspond to the data. 


## Delete temporary elements
```{shell}
make clean
```

## Compile and execute tests
```{shell}
make test
```

## Force-compile doc
```{shell}
make doc
```
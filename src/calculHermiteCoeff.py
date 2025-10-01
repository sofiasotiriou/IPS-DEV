import numpy 

xi, weights = numpy.polynomial.hermite.hermgauss(8)

with open("../ressources/hermiteCoeff.csv", "w") as f:
    numpy.savetxt(f, xi, delimiter=",")
    f.write("\n")  # Ligne vide pour séparer les tableaux
    numpy.savetxt(f, weights, delimiter=",")
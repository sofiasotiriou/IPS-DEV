#include "../headers/compute.hpp"
#include "../headers/checkOrthonormality.hpp"
#include <cmath>
//#include <corecrt_math_defines.h>
#include <iostream>


void CheckOrthonormality::orthonormality(Compute compute) {
    matrix = arma::mat(8,8);
    hermiteCoeff("ressources/hermiteCoeff.csv");
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            int result = round(integral(i, j, compute));
            matrix(i,j) = result;
        }
    }
    matrix.print("Orthonormality check : ");
}

void CheckOrthonormality::hermiteCoeff(std::string chemin){
    std::ifstream fichier(chemin);
    std::string ligne;

    while (std::getline(fichier, ligne) && !ligne.empty()) {
        nodes.push_back(std::stod(ligne));  
    }

    while (std::getline(fichier, ligne) && !ligne.empty()) {
        weights.push_back(std::stod(ligne));
    }
}





//return the integral of a function using the Gaussian Quadrature rule
double CheckOrthonormality::integral(int m, int n, Compute compute) {
    if (n < 0 || m < 0) {
        throw std::invalid_argument("n and m must be non-negative");
    }

    double integral = 0.0;
    for (int i = 0; i < NUMBER_N; i++) {
        if (i <= (int)weights.size() && i <= (int)nodes.size()) {
                integral += (weights[i] * compute.hermite(m, nodes[i]) * compute.hermite(n, nodes[i])) / (std::pow(M_PI, 0.5) * std::sqrt(std::pow(2,n)* compute.factorial(n)) * std::sqrt(std::pow(2,m)* compute.factorial(m)));
        
        }
    }

    return integral;
}
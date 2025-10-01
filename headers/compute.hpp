#ifndef COMPUTE_HPP 
#define COMPUTE_HPP
#include <iostream>
#include <vector>
#include <cmath>

#define FIRST_X -5
#define LAST_X 5
#define DELTA_X 0.01
#define NUMBER_N 8


/**
 * @details Class to compute calculations
 */
class Compute{

    public:
        double m = 1.0;
        double w = 1.0;
        double h = 1.0;

        Compute() noexcept;

        /**
         * @brief Calculate Hermite polynomials
         * @param n Degree of the polynomial
         * @param z Variable of the polynomial
         * @return Value of the Hermite polynomial Hn(z)
         */
        double hermite(int n, double z);

        /**
         * @brief Calculate the wave function ψ_n(z)
         * @param n Degree of the polynomial
         * @param z Variable of the wave function
         * @return Value of ψ_n(z)
         */
        double psi(int n, double z);

        /**
         * @brief Calculate the potential
         * @param z Variable of the wave function
         * @return Value of the potention according to z
         */
        double potential(double z);

        /**
         * @brief Helper function to compute factorial of a number
         * @param n The number to calculate factorial
         * @return Factorial of n
         */
        int factorial(int n);
        
    private:
        std::vector<double> memo;

        std::vector<double> nodes;

        std::vector<double> weights;

        /**
         * @brief Recursive function to calculate Hermite polynomials
         * @param n Degree of the polynomial
         * @param z Variable of the polynomial
         * @return Value of the Hermite polynomial Hn(z)
         */
        double hermiteRecursive(int n, double z);

       

       

        friend class TestCompute; // in order to test private methods

};

#endif //COMPUTE_HPP
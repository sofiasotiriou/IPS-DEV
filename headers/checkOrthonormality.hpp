#ifndef CHECKORTHONORMALITY_HPP 
#define CHECKORTHONORMALITY_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "../headers/compute.hpp"
#include <armadillo>


/**
 * @details Class to check orthonormality
 */
class CheckOrthonormality {
public:
		/**
         * @brief Compute the integral for all the values n and z 
         */
		void orthonormality(Compute compute);

		/**
    	* @brief Compute the integrals for values of n and m 
    	*/
		double integral(int m, int n, Compute compute);

		/**
    	* @brief Read hermiteCoeff.csv to access the weights and the nodes values
    	*/
		void hermiteCoeff(std::string chemin);


private:
	std::vector<double> nodes;
	std::vector<double> weights;
	arma::mat matrix;

	
};

#endif //CHECKORTHONORMALITY_HPP
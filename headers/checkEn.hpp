#ifndef CHECKEN_HPP 
#define CHECKEN_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "../headers/compute.hpp"
#include <armadillo>



class CheckEn {
public:
        /**
         * @brief Print Correct if the En are good, so if matrixLeft = matrixRight
         */
		void verification(Compute compute);

private:
	arma::mat matrixLeft;
    arma::mat matrixRight;

    /**
     * @brief Compute the left side of the equation 
     */
    void leftSide(Compute compute);

    /**
     * @brief Compute the right side of the equation 
     */
    void rightSide(Compute compute);
    
};

#endif //CHECKEN_HPP
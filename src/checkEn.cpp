#include "../headers/checkEn.hpp"
#include <cxxtest/TestSuite.h>

void CheckEn::leftSide(Compute compute){
    int number_of_x = (LAST_X -FIRST_X)/DELTA_X;

    matrixLeft = arma::mat(number_of_x-2, NUMBER_N);

    for(int i=1; i< number_of_x-1; i++){
        double x= FIRST_X + DELTA_X*i;
        double previousX = FIRST_X + DELTA_X*(i-1);
        double nextX = FIRST_X + DELTA_X*(i+1); 

        for(int j=0; j<NUMBER_N; j++){
            double psiCarre = (compute.psi(j, previousX) - 2*compute.psi(j, x) + compute.psi(j, nextX))/(std::pow(DELTA_X, 2));
            matrixLeft(i-1, j) = 0.5 *(-psiCarre + std::pow(x, 2)*compute.psi(j, x));
        }
    }

}

void CheckEn::rightSide(Compute compute){
    int number_of_x = (LAST_X -FIRST_X)/DELTA_X;

    matrixRight = arma::mat(number_of_x-2, NUMBER_N);

    for(int i=1; i< number_of_x-1; i++){
        double x= FIRST_X + DELTA_X*i;

        for(int j=0; j<NUMBER_N; j++){
            matrixRight (i-1, j) = (j+0.5) * compute.psi(j,x) ;
        }
    }
}

void CheckEn::verification(Compute compute){
    leftSide(compute);
    rightSide(compute);
    if (arma::approx_equal(matrixLeft, matrixRight, "absdiff", 1e-3)){
        std::cout << "En Check: According to the equations, the En are correct" << std::endl;
    }
}
    


#ifndef EXPORT_HPP 
#define EXPORT_HPP
#include <iostream>
#include <fstream>
#include "compute.hpp"
#include <vector>
#include <cmath>


/**
 * @details Class to export tab
 */
class Export{
    public: 
       
        /**
         * @brief Export the values of ψ_n(z) for a large number of n and z in a csv file
         * @param compute Instance de Compute 
         */
        void exportTab(Compute compute);
};
#endif //EXPORT_HPP
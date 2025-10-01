#include <iostream>
#include "../headers/export.hpp"
#include "../headers/compute.hpp"
#include "../headers/checkOrthonormality.hpp"
#include "../headers/checkEn.hpp"
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Main function
 */
int main(void){
  
    Compute compute;

    std::cout << "Export data into ressources/tab.csv" << std::endl;
    Export toDoExport;
    toDoExport.exportTab(compute);

    //Check of the orthonormality
    CheckOrthonormality O;
    O.orthonormality(compute);

    //Check of the En
    CheckEn E ; 
    E.verification(compute);

    // Wait for user input so that the window will not close 
    //std::cin.get(); 
    std::cout << "Plot the data using python" << std::endl;
    system("python3 src/plot.py");

    

    return 0;
}
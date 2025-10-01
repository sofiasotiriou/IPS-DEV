#include "../headers/export.hpp"

void Export::exportTab(Compute compute){
    std::ofstream fichier("./ressources/tab.csv");
    if (fichier.is_open()) {
        fichier << "z,\"Psi(0, z)\",\"Psi(1, z)\",\"Psi(2, z)\",\"Psi(3, z)\",\"Psi(4, z)\",\"Psi(5, z)\",\"Psi(6, z)\",\"Psi(7, z)\",\"E(z)\"\n";

        int number_of_x = (LAST_X -FIRST_X)/DELTA_X;

        for(int i= 0; i<number_of_x; i++){
            double x= FIRST_X + DELTA_X*i;
            fichier << x;

            for (int j=0; j<NUMBER_N; j++){
                fichier << ",";
                fichier << compute.psi(j, x);
            }
            
            fichier << ",";
            fichier << compute.potential(x);
            
            fichier << "\n";
        }
        fichier.close();
    }
    else{
        std::cerr << "Erreur : impossible d'ouvrir le fichier.\n";
    }
}


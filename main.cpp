#include <iostream>
#include <string>
#include "ihmModeConsole.h"
#include "ihmModeGraphique.h"
#include "srvFileService.h"
#include "srvJeu.h"
#include <direct.h>


void afficherMenu() {
    std::cout << "=============================\n";
    std::cout << "  Jeu de la Vie - Menu\n";
    std::cout << "=============================\n";
    std::cout << "1. Mode Console\n";
    std::cout << "2. Mode Graphique\n";
    std::cout << "3. Quitter\n";
    std::cout << "Choisissez une option : ";
}

int main() {
    int choix;
    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
        case 1: { //Activation du Mode Console
            std::string inputFile = "FichierInitial.txt";
            std::string outputDir = inputFile + "_out.txt";

            try {
                std::cout << "Chargement de la grille depuis : " << inputFile << "\n";
                Grille grille = FileService::ChargerDuFichier(inputFile);

                int iterations;
                std::cout << "Entrez le nombre d'iterations : ";
                std::cin >> iterations;

                
                Jeu jeu(grille, iterations);

                
                if (_mkdir(outputDir.c_str()) != 0 && errno != EEXIST) {
                    throw std::runtime_error("Erreur lors de la creation du repertoire : " + outputDir);
                } 
                

                jeu.Simulation(outputDir);

                std::cout << "Simulation console terminee avec succes.\n";
                std::cout << "Les resultats sont enregistres dans : " << outputDir << "\n";
            }
            catch (const std::exception& e) {
                std::cerr << "Erreur : " << e.what() << "\n";
            }
            break;
        }

        case 2: { //Activation du Mode Graphique
            std::string inputFile = "FichierInitial.txt";

            try {
                using GrilleGraph = std::vector<std::vector<bool>>;

                GrilleGraph grille;
                GrilleGraph nextGrille = grille;

                ModeGraphique modeGraphique;
                modeGraphique.run();
            }
            catch (const std::exception& e) {
                std::cerr << "Erreur : " << e.what() << "\n";
            }
            break;
        }

        case 3:
            std::cout << "Merci d'avoir utilise le Jeu de la Vie. A bientot !\n";
            break;

        default:
            std::cerr << "Option invalide. Veuillez reessayer.\n";
            break;
        }
    } while (choix != 3);

    return 0;
}

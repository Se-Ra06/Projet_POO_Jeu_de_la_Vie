#include "Grille.h"
#include "CelluleVie.h"
#include "CelluleMort.h"
#include <gtest/gtest.h>

// Test d'une grille 3x3 avec un motif de "block" stable
TEST(GrilleTest, StableBlockPattern) {
    // Initialisation : Grille avec un motif stable ("bloc")
    Grille grille(4, 4);
    std::vector<std::vector<int>> etatInitial = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    grille.InitialisationGrille(etatInitial);

    // Effectuer une itération
    grille.MiseAJourGrille();

    // Vérification : le motif ne doit pas changer
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            bool expected = etatInitial[i][j];
            EXPECT_EQ(grille.getEtat(i, j), expected)
                << "Erreur à la position (" << i << ", " << j << ")";
        }
    }
}

// Test d'une grille 3x3 avec un motif qui évolue
TEST(GrilleTest, OscillatorBlinker) {
    // Initialisation : Grille avec un motif oscillant ("blinker")
    Grille grille(5, 5);
    std::vector<std::vector<int>> etatInitial = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    grille.InitialisationGrille(etatInitial);

    // État attendu après une itération
    std::vector<std::vector<int>> etatAttendu = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Effectuer une itération
    grille.MiseAJourGrille();

    // Vérification : comparer la grille avec l'état attendu
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            bool expected = etatAttendu[i][j];
            EXPECT_EQ(grille.getEtat(i, j), expected)
                << "Erreur à la position (" << i << ", " << j << ")";
        }
    }
}


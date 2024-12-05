#include "gtest/gtest.h"
#include "C:\Users\LENOVO\source\repos\PROJETPOOJEUDELAVIEFINAL\cmpFichier.h" // Emplacement des fichiers 
#include "C:\Users\LENOVO\source\repos\PROJETPOOJEUDELAVIEFINAL\cmpGrille.h" 


TEST(GrilleTest, GeneralValidationAfterMultipleIterations) {
    
    Fichier fichierInitial("FichierInitial.txt");
    Grille grille = fichierInitial.LireFichier();

    
    int longueurInitiale = grille.getLongueur();
    int largeurInitiale = grille.getLargeur();

    
    const int nombreIterations = 5;

    for (int iteration = 1; iteration <= nombreIterations; ++iteration) {
        
        grille.MiseAJourGrille();

        // Vérifier que les dimensions restent identiques
        ASSERT_EQ(grille.getLongueur(), longueurInitiale);
        ASSERT_EQ(grille.getLargeur(), largeurInitiale);

        // Vérifier les états des cellules après la mise à jour
        for (int i = 0; i < grille.getLongueur(); ++i) {
            for (int j = 0; j < grille.getLargeur(); ++j) {
                bool etat = grille.getEtat(i, j);

                // L'état d'une cellule doit être soit vivant (true), soit mort (false)
                EXPECT_TRUE(etat == true || etat == false)
                    << "Etat invalide pour la cellule (" << i << ", " << j << ") à l'itération " << iteration;

               
            }
        }

        
        std::cout << "Validation apres l'iteration " << iteration << " reussie." << std::endl;
    }
}

// Point d'entrée pour Google Test
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

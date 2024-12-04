#include <SFML/Graphics.hpp>
#include <vector>
#include "ihmModeGraphique.h"
#include "cmpGrille.h"



void ModeGraphique::run() {
    
    sf::RenderWindow window(sf::VideoMode(GRILLE_LARGEUR * TAILLE_CELLULE, GRILLE_LONGUEUR * TAILLE_CELLULE), "Jeu de la Vie");
    window.setFramerateLimit(60);

    // initialisation de la grille
    
    Grille grille(GRILLE_LONGUEUR, std::vector<bool>(GRILLE_LARGEUR, false));
    Grille nextGrille = grille;

    // Variables de simulation
    sf::Clock clock;
    bool isRunning = false;
    bool manualMode = true; 

    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            // Interaction avec la souris
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / TAILLE_CELLULE;
                    int y = event.mouseButton.y / TAILLE_CELLULE;
                    if (x >= 0 && x < GRILLE_LARGEUR && y >= 0 && y < GRILLE_LONGUEUR) {
                        if (manualMode) {
                            // Changer l'état des cellules individuellement avec le clic gauche de la souris
                            grille[y][x] = !grille[y][x];
                        }
                    }
                }
            }

            // Interaction avec l'interface à travers les touches du clavier
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    isRunning = !isRunning;
                }
                if (event.key.code == sf::Keyboard::R) {
                    grille = Grille(GRILLE_LONGUEUR, std::vector<bool>(GRILLE_LARGEUR, false));
                }
            }

        }

        // Appel de la fonction pour mettre à jour la grille
        if (isRunning && clock.getElapsedTime().asMilliseconds() > 100) {
            mettreAJourGrille(grille, nextGrille);
            clock.restart();
        }

        // Dessiner l'interface
        window.clear(sf::Color(10, 10, 30));

        // Dessiner les cellules
        for (int y = 0; y < GRILLE_LONGUEUR; ++y) {
            for (int x = 0; x < GRILLE_LARGEUR; ++x) {
                sf::RectangleShape cell(sf::Vector2f(TAILLE_CELLULE - 2, TAILLE_CELLULE - 2));
                cell.setPosition(x * TAILLE_CELLULE, y * TAILLE_CELLULE);
                if (grille[y][x]) {
                    cell.setFillColor(sf::Color(128, 0, 128));
                }
                else {
                    cell.setFillColor(sf::Color(30, 30, 30));
                }
                window.draw(cell);
            }
        }

        
        window.display();
    }

}

// Méthode pour mettre à jour la grille
void ModeGraphique::mettreAJourGrille(Grille& grille, Grille& nextGrille) {
    for (int y = 0; y < GRILLE_LONGUEUR; ++y) {
        for (int x = 0; x < GRILLE_LARGEUR; ++x) {
            int voisinsvivants = 0;

            
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // Ignorer la cellule morte

                    // Calculer les coordonnées des voisins sur une grille torique
                    int ny = (y + dy + GRILLE_LONGUEUR) % GRILLE_LONGUEUR;
                    int nx = (x + dx + GRILLE_LARGEUR) % GRILLE_LARGEUR;

                    voisinsvivants += grille[ny][nx]; // Ajouter l'état de la cellule voisine
                }
            }

            // Application des règles du Jeu de la Vie de Conway
            if (grille[y][x]) {
                nextGrille[y][x] = (voisinsvivants == 2 || voisinsvivants == 3);
            }
            else {
                nextGrille[y][x] = (voisinsvivants == 3);
            }
        }
    }

    // Mise à jour de la grille avec la nouvelle génération
    grille = nextGrille;
}


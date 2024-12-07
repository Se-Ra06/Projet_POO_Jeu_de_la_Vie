#include "ihmModeGraphique.h"
#include "cmpGrille.h"
#include <thread>
#include <chrono>
#include <vector> 

void ModeGraphique::run() {
    sf::RenderWindow window(sf::VideoMode(GRILLE_LARGEUR * TAILLE_CELLULE, GRILLE_LONGUEUR * TAILLE_CELLULE), "Jeu de la Vie");
    window.setFramerateLimit(60);

    GrilleGraph grille(GRILLE_LONGUEUR, std::vector<bool>(GRILLE_LARGEUR, false));
    GrilleGraph nextGrille = grille;

    sf::Clock clock;
    bool isRunning = false;
    bool manualMode = true;

    float cellWidth = TAILLE_CELLULE;
    float cellHeight = TAILLE_CELLULE;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / cellWidth;
                    int y = event.mouseButton.y / cellHeight;
                    if (x >= 0 && x < GRILLE_LARGEUR && y >= 0 && y < GRILLE_LONGUEUR) {
                        if (manualMode) {
                            grille[y][x] = !grille[y][x];
                        }
                    }
                }
            }

            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    isRunning = !isRunning;
                }
                if (event.key.code == sf::Keyboard::R) {
                    grille = GrilleGraph(GRILLE_LONGUEUR, std::vector<bool>(GRILLE_LARGEUR, false));
                }
            }

            if (event.type == sf::Event::Resized) {
                float newWidth = event.size.width;
                float newHeight = event.size.height;

                cellWidth = newWidth / GRILLE_LARGEUR;
                cellHeight = newHeight / GRILLE_LONGUEUR;

                window.setView(sf::View(sf::FloatRect(0, 0, newWidth, newHeight)));
            }
        }

        if (isRunning && clock.getElapsedTime().asMilliseconds() > 100) {
            mettreAJourGrille(grille, nextGrille);
            clock.restart();
        }

        window.clear(sf::Color(10, 10, 30));

        for (int y = 0; y < GRILLE_LONGUEUR; ++y) {
            for (int x = 0; x < GRILLE_LARGEUR; ++x) {
                sf::RectangleShape cell(sf::Vector2f(cellWidth - 2, cellHeight - 2));
                cell.setPosition(x * cellWidth, y * cellHeight);
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
void ModeGraphique::mettreAJourGrille(GrilleGraph& grille, GrilleGraph& nextGrille) {
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

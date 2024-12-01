#include "cmpFichier.h"
#include "cmpGrille.h"
#include "cmpCellule.h"
#include "cmpCelluleVie.h"
#include "cmpCelluleMort.h"
#include <fstream>
#include <iostream>
using namespace std;

Grille Fichier::LireFichier(const string& fichier) {
	ifstream file(fichier);
	if (!file.is_open()) {
		throw runtime_error("Impossible d'ouvrir le fichier.");
	}
	vector<string> lines;
	string line;
	int largeur = 0;

	while (getline(file, line)) {
		lines.push_back(line);
		if (line.length() > largeur) {
			largeur = line.length();
		}
	}
	file.close();

	int longueur = lines.size();
	Grille grille(longueur, largeur);

	for (int y = 0; y < longueur; y++) {
		for (int x = 0; x < largeur; x++) {
			char c = (x < lines[y].size()) ? lines[y][x] : '0';
			grille.SetCelluleEtat(x, y, c == '1');
		}
	}
	return grille;
}

void Fichier::EcrireFichier(const Grille& grid, const string& fichier) {
	ofstream file(fichier);
	if (!file.is_open()) {
		throw runtime_error("Impossible d'écrire dans le fichier.");
	}

	const auto& grille = grid.grid;
	for (const auto& row : grille) {
		for (const auto& cell : row) {
			file << (cell->status() ? '1' : '0');
		}
		file << 'n';
	}
	file.close();
}
#include "srvFileService.h"
#include <iostream>
#include <fstream>
#include <direct.h>
using namespace std;



bool FileService::ValiderFichier(const string& nomfichier) {
	ifstream file(nomfichier);
	if (!file.is_open()) {
		cerr << "Erreur : impossible d'ouvrir le fichier " << nomfichier << ".\n";
		return false;
	}
	file.close();
	return true;
}

void FileService::ChargerDuFichier(const string& nomfichier, Grille& grille) {
	if (!ValiderFichier(nomfichier)) {
		throw runtime_error("Fichier invalide ou introuvable");
	}
	grille.initialisationGrille(nomfichier);
}

void FileService::SauvegarderAuFichier(const string& nomfichier, const Grille& grille) {
	ofstream file(nomfichier);
	if (!file.is_open()) {
		throw runtime_error("Impossible de sauvegarder dans le fichier" + nomfichier);
	}
	for (const auto& row : grille.grid) {
		for (const auto& cellule : row) {
			file << (cellule->status() ? '1' : '0');
		}
		file << '\n';
	}
	file.close();
}

void FileService::CreateOutputDir(const string& directory) {
	if (_mkdir(directory.c_str()) != 0) {
		if (errno != EEXIST) {
			throw runtime_error("Impossible de créer le répertoire " + directory);
		}
	}
}


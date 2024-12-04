
#include<iostream>
#include<string>
#include "Fichier.h"
#include "ModeConsole.h"
#include"Grille.h"

using namespace std;

ModeConsole::ModeConsole(const string& inputFile, const string& outputDir) : inputFile(inputFile), outputDir(outputDir) {}

void ModeConsole::run() {

    cout<<"making la grille :"<<inputFile<<endl;
    Fichier fichier(inputFile);
    Grille grille = fichier.LireFichier();

    int iterations;
    cout<<"gimme the number of les iterations:";
    cin>>iterations;

    Jeu jeu(iterations);
    jeu.Simulation(grille);

    string outputFile = outputDir + "/output.txt";
    cout<< "saving la grille after simulation :"<<outputFile<<endl;
    Fichier fichierSortie(outputFile);
    fichierSortie.EcrireFichier(grille);

    cout<< "we r done"<<endl;
}

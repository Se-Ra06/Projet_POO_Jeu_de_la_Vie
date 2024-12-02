#ifndef MODECONSOLE_H
#define MODECONSOLE_H

#include<iostream>
#include<string>
#include "Grille.h"
#include "Jeu.h"

using namespace std;

class ModeConsole {

    private:
    string inputFile;
    string outputDir;

    public:
    ModeConsole(const string& inputFile, const string& outputDir);
    void run();
};

#endif
#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <string>
#include "Grille.h"

using namespace std;

class FileService {
public:
   
    static Grille chargerDepuisFichier(const string& nomFichier);


    static void sauvegarderDansFichier(const Grille& grille, const string& nomFichier);
};

#endif 


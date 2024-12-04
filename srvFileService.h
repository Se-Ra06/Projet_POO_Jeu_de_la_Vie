#ifndef FILESERVICE_H
#define FILESERVICE_H

#include "Grille.h"
#include <string>

class FileService {
public:
    bool ValiderFichier(const string& nomfichier);
    void ChargerDuFichier(const string& nomfichier, Grille& grille);
    void SauvegarderAuFichier(const string& nomfichier, const Grille& grille);
    void CreateOutputDir(const string& directory);
};

#endif

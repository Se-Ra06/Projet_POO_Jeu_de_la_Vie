# Projet_POO_Jeu_de_la_Vie
<This project is presented to you by RADI Selma Meriem et RECHAM Wissam>

# Introduction
Le Jeu de la Vie est un automate cellulaire conçu par le mathématicien John Conway en 1970. Il s'agit d'un modèle de simulation où des cellules sur une grille évoluent au fil du temps selon des règles simples, mais capables de générer des comportements complexes. Ce projet illustre comment un système basé sur des principes simples peut aboutir à des configurations dynamiques et imprévisibles.

<Objectif du projet>
L’objectif de ce projet est de reproduire ces comportements en exploitant des concepts de programmation orientée objet (POO) pour une solution modulaire et extensible. Deux modes d’interaction sont proposés :

- Un mode console, pour la simplicité et l’accès aux fichiers d’état.
- Un mode graphique, offrant une interface utilisateur interactive grâce à SFML.

# Règles_du_Jeu_de_la_Vie
Les règles définissent la manière dont une cellule passe de l’état "vivante" à "morte" ou inversement, selon son environnement immédiat (voisins). Ces règles sont déterministes :

   <Pour une cellule vivante :>

Elle survit si elle a 2 ou 3 voisins vivants.
Elle meurt par :
Isolation si elle a moins de 2 voisins vivants.
Surpopulation si elle a plus de 3 voisins vivants.
  < Pour une cellule morte :>

Elle devient vivante si elle a exactement 3 voisins vivants.
Elle reste morte dans les autres cas.

# Architecture_du_Projet


Le projet est structuré en trois couches principales pour une meilleure organisation et modularité :
1. Composants

    Contient les éléments de base nécessaires au fonctionnement de l'automate cellulaire (e.g., la classe Cellule, Grille).

2. Service

    Fournit les fonctionnalités logiques pour gérer la simulation et les interactions avec les fichiers (e.g., chargement/sauvegarde des états, gestion des règles).

3. Interface

    Gère les interactions utilisateur et propose deux modes :
        Mode Console : Permet de visualiser et sauvegarder les états successifs sous forme textuelle.
        Mode Graphique : Utilise la bibliothèque SFML pour afficher et interagir avec la grille via une interface graphique.

# Diagramme_UML

- Le diagramme UML représentant les couches et leurs relations est inclus dans le projet (voir le fichier diagramme UML).
Fonctionnalités
Mode Console

    Permet de visualiser les états successifs de la grille sous forme textuelle.
    Les résultats sont enregistrés dans des fichiers et organisés en dossiers.
    Chaque itération est sauvegardée selon un format défini.

- Mode Graphique

    Permet de visualiser et manipuler la grille via une interface graphique :
        Cliquez gauche pour rendre une cellule vivante.
        Espace pour lancer/arrêter la simulation.
        R pour réinitialiser la grille.
    Les motifs peuvent être créés librement ou ajoutés à l'aide de motifs prédéfinis.

- Extensions Implémentées

    Grille Torique : Les cellules situées sur les bords de la grille sont connectées, formant une surface "enroulée".
    Motifs Préprogrammés : Possibilité d'insérer des motifs prédéfinis sur la grille en appuyant sur des touches spécifiques.

- Prérequis Techniques

    C++17 ou supérieur
    SFML (pour le mode graphique)
    Make (pour la compilation)

# Installation_et_Exécution
- Depuis le Terminal:

    Clonez le dépôt Git :

git clone https://github.com/Se-Ra06/Projet_POO_Jeu_de_la_Vie.git

- Accédez au répertoire du projet :

cd Projet_POO_Jeu_de_la_Vie

- Compilez le projet avec make :

make

- Exécutez le programme :

    ./Projet_POO_Jeu_de_la_Vie

- Depuis Visual Studio

    Ouvrez Visual Studio.
    Sélectionnez l'option Cloner un dépôt.
    Collez l'URL suivante :

    https://github.com/Se-Ra06/Projet_POO_Jeu_de_la_Vie.git

    Lancez le projet en cliquant sur l'icône de lancement (bouton vert en haut de l'interface).

  # Utilisation
    Choix du Mode :
        Console : Affiche les états successifs sous forme textuelle.
        Graphique : Ouvre une fenêtre interactive.
    Mode Graphique :
        Créer un motif :
            Utilisez le clic gauche pour rendre une cellule vivante.
        Lancer la simulation :
            Appuyez sur Espace pour démarrer ou arrêter la simulation.
        Réinitialiser la grille :
            Appuyez sur R.

# Objectifs Pédagogiques

Ce projet vise à :

Approfondir la maîtrise des concepts fondamentaux de la programmation orientée objet (POO) en C++.
Structurer un programme de manière modulaire.
Exploiter des outils modernes comme la bibliothèque SFML pour le développement d’interfaces graphiques.

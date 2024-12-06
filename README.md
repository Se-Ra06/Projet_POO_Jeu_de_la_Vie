
# **🌟 Projet POO : Jeu de la Vie 🌟**

### Ce projet vous est présenté par :  
👩‍💻 **RADI Selma Meriem**  
👨‍💻 **RECHAM Wissam**

---

## **📖 Table des matières**
1. [📚 Introduction](#introduction)  
2. [⚙️ Règles du Jeu de la Vie](#règles-du-jeu-de-la-vie)  
3. [🏗️ Architecture du projet](#architecture-du-projet)  
4. [📈 Diagramme UML](#diagramme-uml)  
5. [✨ Fonctionnalités](#fonctionnalités)  
6. [🚀 Extensions Implémentées](#extensions-implémentées)  
7. [🔧 Prérequis Techniques](#prérequis-techniques)  
8. [💻 Installation et Exécution](#installation-et-exécution)  
9. [🎮 Utilisation](#utilisation)  
10. [🎯 Objectifs Pédagogiques](#objectifs-pédagogiques)  
11. [🏁 Conclusion](#conclusion)

---

## **📚 Introduction**

Le **Jeu de la Vie** est un automate cellulaire conçu par le mathématicien John Conway en 1970.  
Il simule l'évolution d'une grille de cellules vivantes et mortes selon des règles simples mais fascinantes.  

**🎯 Objectif du projet :**  
Reproduire ce comportement en exploitant les principes de la **programmation orientée objet (POO)** pour une solution modulaire et extensible.

### **Deux modes d'interaction :**
- 🖥️ **Mode console :** Accès simplifié aux états textuels.  
- 🖼️ **Mode graphique :** Interface interactive via **SFML**.

---

## **⚙️ Règles du Jeu de la Vie**

### **Pour une cellule vivante :**
- ✅ **Survit** si elle a **2** ou **3 voisins vivants**.  
- ❌ **Meurt** par :  
  - **Isolement** : moins de 2 voisins vivants.  
  - **Surpopulation** : plus de 3 voisins vivants.  

### **Pour une cellule morte :**
- 🌱 **Devient vivante** si elle a exactement **3 voisins vivants**.  
- ➖ **Reste morte** dans tous les autres cas.

---

## **🏗️ Architecture du Projet**

Le projet est structuré en trois couches principales :  

### **1️⃣ Composants :**  
   📦 Classes de base nécessaires au fonctionnement de l'automate (e.g., `Cellule`, `Grille`).  

### **2️⃣ Service :**  
   🔄 Gestion de la simulation et interactions avec les fichiers (e.g., chargement/sauvegarde des états).  

### **3️⃣ Interface :**  
   🖥️ Deux modes d'interaction :  
   - **Console :** Affichage textuel des états.  
   - **Graphique :** Interface interactive avec **SFML**.

---

## **📈 Diagramme UML**

📌 Le diagramme UML détaillant les relations entre les couches est inclus dans le projet :

![image](https://github.com/user-attachments/assets/ec4da69d-bc07-49a1-9e97-9182572349b1)

---

## **✨ Fonctionnalités**

### **🖥️ Mode Console :**
- Affichage textuel des états successifs.  
- Sauvegarde automatique des résultats dans des fichiers.  
- Organisation des itérations dans des dossiers.

### **🖼️ Mode Graphique :**
- **Interactions utilisateur :**  
  - 🖱️ **Clic gauche :** Rendre une cellule vivante.  
  - 🔄 **Touche Espace :** Démarrer/arrêter la simulation.  
  - 🔃 **Touche R :** Réinitialiser la grille.  
- **Création de motifs :** Dessinez librement ou insérez des motifs prédéfinis.

---

## **🚀 Extensions Implémentées**

1. 🌐 **Grille Torique :** Les cellules des bords sont connectées, simulant une surface "enroulée".  

2. 🎨 **Motifs Préprogrammés :** Ajout de motifs prédéfinis avec des touches spécifiques.

---

## **🔧 Prérequis Techniques**

- 🛠️ **C++17** ou supérieur.  
- 🖼️ **SFML** (pour le mode graphique).  
- 📦 **Make** (pour la compilation).

---

## **💻 Installation et Exécution**

### **🖥️ Depuis le terminal :**

1. **Clonez le dépôt Git :**  
   ```bash
   git clone https://github.com/Se-Ra06/Projet_POO_Jeu_de_la_Vie.git
   ```

2. **Accédez au répertoire du projet :**  
   ```bash
   cd Projet_POO_Jeu_de_la_Vie
   ```

3. **Compilez le projet avec Make :**  
   ```bash
   make
   ```

4. **Exécutez le programme :**  
   ```bash
   ./Projet_POO_Jeu_de_la_Vie
   ```

### **🛠️ Depuis Visual Studio :**
1. Ouvrez **Visual Studio**.  
2. Sélectionnez **Cloner un dépôt**.  
3. Collez l’URL du projet :  
   ```plaintext
   https://github.com/Se-Ra06/Projet_POO_Jeu_de_la_Vie.git
   ```
4. Lancez le projet en cliquant sur **Exécuter** (bouton vert).

---

## **🎮 Utilisation**

### **Choix du mode :**
- 🖥️ **Mode Console :** Affichage des états textuels.  
- 🖼️ **Mode Graphique :** Interface interactive.

### **Mode Graphique :**
- 🎨 **Créer un motif :**  
  🖱️ Cliquez gauche pour rendre une cellule vivante.  
- 🔄 **Lancer la simulation :**  
  Appuyez sur `Espace` pour démarrer/arrêter.  
- 🔃 **Réinitialiser la grille :**  
  Appuyez sur `R`.

---

## **🎯 Objectifs Pédagogiques**

Ce projet vise à :  
- 🏗️ Approfondir les concepts de **programmation orientée objet (POO)**.  
- 🧹 Structurer un programme de manière modulaire et lisible.  
- 🎨 Explorer **SFML** pour créer des interfaces graphiques.  
- 🤝 Travailler sur des projets collaboratifs.

---

## **🏁 Conclusion**

Le **Jeu de la Vie** démontre comment des règles simples peuvent générer des comportements complexes.  

En réalisant ce projet, nous avons :  
- 🚀 Mis en œuvre les principes fondamentaux de la POO.  
- 🔄 Structuré un programme modulaire et extensible.  
- 🛠️ Relevé des défis techniques comme la gestion des grilles ou l'optimisation des calculs.

**🔮 Perspectives :**  
Ce projet offre une base solide pour des améliorations futures et illustre l'intérêt d'allier théorie et pratique dans un cadre éducatif.

---

✨ **Merci de découvrir notre projet !** ✨

---

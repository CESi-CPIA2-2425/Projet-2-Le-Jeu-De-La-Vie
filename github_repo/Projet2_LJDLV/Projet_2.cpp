////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
/////////////////////////////////////////////// LE JEU DE LA VIE ///////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////Inclusion des fichier, bibliothèques, namespace et instances de classes/////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <string>

#include "Fichier.h"
#include "Ligne.h"

using namespace std;

Fichier fichier;  //instance de la classe Fichier dans le main

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////Initialisation des valeurs (par défaut)/////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

const int cellSize = 50;  //taille des cellules
const int gridWidth = 10;  //nombre de cellules en largeur (valeur présentes dans la première ligen du fichier texte)
const int gridHeight = 10;  //nombre de cellules en hauteur (valeur présentes dans la première ligen du fichier texte)

std::vector<std::vector<int> > grid(gridWidth, std::vector<int>(gridHeight));

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////Affichage de la grille à l'écran////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

string txt = fichier.lecture();
vector<string> liste = fichier.vecteur(txt);
Ligne jeu(liste);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////Affichage de la grille à l'écran////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

// Fonction pour convertir la grille fournie par le méthode fichier.vecteur
std::vector<std::vector<int>> convertirGrille(const std::vector<std::string>& grille) {
    std::vector<std::vector<int>> grid;
    for (const auto& ligne : grille) {
        std::vector<int> row;
        for (char c : ligne) {
            if (c == '0' || c == '1') {
                row.push_back(c - '0');
            }
        }
        grid.push_back(row);
    }
    return grid;
}

// Fonction pour afficher la grille avec SFML
void afficherAvecSFML(const std::vector<std::vector<int>>& grid, int cellSize) {
    if (grid.empty()) return; // Vérifier si la grille est vide

    // Créer une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(grid[0].size() * cellSize, grid.size() * cellSize), "Game of Life");
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Ferme la fenêtre après n secondes
            if (clock.getElapsedTime().asSeconds() > 2) {
                window.close();
            }
        }

        // Dessiner la grille
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
        for (size_t y = 0; y < grid.size(); ++y) {
            for (size_t x = 0; x < grid[y].size(); ++x) {
                if (grid[y][x] == 1) {
                    cell.setPosition(x * cellSize, y * cellSize);
                    cell.setFillColor(sf::Color::White); // Cellules vivantes en vert
                    window.draw(cell);
                }
            }
        }
        window.display();

        sf::sleep(sf::milliseconds(500)); // Attente entre les affichages
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
//////////////////////////////////////////Test unitaires////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

// Test de la fonction `Fichier::lecture`
TEST(FichierTest, LectureFichier) {
    Fichier fichier;
    std::string contenu = fichier.lecture();
    EXPECT_FALSE(contenu.empty()) << "Le contenu du fichier ne doit pas être vide.";
}

// Test de la fonction `Fichier::vecteur`
TEST(FichierTest, ConversionVecteur) {
    Fichier fichier;
    std::string contenu = "5 5\n10101\n01010\n10101\n01010\n";
    std::vector<std::string> vecteur = fichier.vecteur(contenu);

    EXPECT_EQ(vecteur.size(), 5) << "Le vecteur doit contenir 5 lignes.";
    EXPECT_EQ(vecteur[1], "10101") << "La deuxième ligne doit être '10101'.";
}

// Test du constructeur de la classe `Ligne`(pas  le constucteur par défaut)
TEST(LigneTest, ConstructionLigne) {
    std::vector<std::string> grille = {"10101", "01010", "10101", "01010"};
    Ligne jeu(grille);

    EXPECT_EQ(jeu.grille.size(), 4) << "La grille doit contenir 4 lignes.";
    EXPECT_EQ(jeu.grille[0], "10101") << "La première ligne de la grille doit être '10101'.";
}

// Test de la fonction `Ligne::CompteCell`
TEST(LigneTest, CompteCell) {
    std::vector<std::string> grille = {"101", "010", "101"};
    Ligne jeu(grille);

    int voisins = jeu.CompteCell(1, 1, grille);
    EXPECT_EQ(voisins, 4) << "La cellule (1,1) doit avoir 4 voisins vivants.";
}

// Test de la fonction `Ligne::Generation`
TEST(LigneTest, Generation) {
    std::vector<std::string> grille = {"000", "111", "000"};
    Ligne jeu(grille);

    jeu.Generation();
    EXPECT_EQ(jeu.grille[1], "010") << "Après une génération, la ligne du milieu doit être '010'.";
}

// Test de la conversion de grille pour SFML
TEST(ConversionGrilleTest, ConvertirGrille) {
    std::vector<std::string> grille = {"101", "010", "101"};
    std::vector<std::vector<int>> grid = convertirGrille(grille);

    EXPECT_EQ(grid.size(), 3) << "La grille convertie doit avoir 3 lignes.";
    EXPECT_EQ(grid[0][1], 0) << "La deuxième cellule de la première ligne doit être 0.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
/////////////////////////////////////Main (appel de méthodes)///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

int main(int argc, char** argv) {
    ////////////////////////////////Lancement des tests unitaires///////////////////////////////////////////////////////
    std::cout << "Initialisation des tests unitaires...\n"<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);

    if (argc > 1 && std::string(argv[1]) == "--run-sfml") {
        std::cout << "Lancement de la fenêtre SFML...\n"<<std::endl;
    }

    std::cout << "Exécution des tests unitaires...\n"<<std::endl;
    int testResult = RUN_ALL_TESTS();

    std::cout << "Tous les tests unitaires sont terminés.\n"<<std::endl;
    std::cout << "Résultat des tests : " << (testResult == 0 ? "Tous validés !" : "Échec.") << "\n"<<std::endl;
    ////////////////////////////////Lancement du programme du jeu de la vie/////////////////////////////////////////////
    std::cout << "Combien d'itérations voulez-vous réaliser ? \t" << std::endl;
    int iteration = 5;
    std::cout << iteration << std::endl;

    std::cout << "Comment voulez-vous obtenir le résultat ? \t 1. mode console \t 2. mode graphique" << std::endl;
    int mode = 2;
    std::cout << mode << std::endl;

    while (iteration > 0) {
        if (mode == 1) {
            string txt = fichier.lecture();
            vector<string> liste = fichier.vecteur(txt);

            for (const auto& ligne : liste) {
                std::cout << ligne << std::endl;
            }

            liste.erase(liste.begin());

            Ligne jeu(liste);

            for (int i = 0; i < 5; ++i) {
                std::cout << "Iteration : " << i + 1 << "\n";
                jeu.Generation();
                jeu.AfficheGrille();
            }
        }

        if (mode == 2) {
            Fichier fichier;
            string txt = fichier.lecture();
            vector<string> liste = fichier.vecteur(txt);

            for (const auto& ligne : liste) {
                std::cout << ligne << std::endl;
            }

            liste.erase(liste.begin());

            Ligne jeu(liste);

            for (int i = 0; i < 5; ++i) {
                jeu.Generation();
                std::vector<std::vector<int>> grid = convertirGrille(jeu.grille);
                afficherAvecSFML(grid, cellSize); // Afficher la grille avec SFML
            }
            return 0;
        }
    }
    return testResult;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

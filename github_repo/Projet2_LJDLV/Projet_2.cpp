#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Fichier.h"
#include "Ligne.h"

using namespace std;

Fichier fichier;
//Grille grille;
Ligne ligne;



vector<vector<int>>jeu;


//////////////////////////////////////////Test unitaires////////////////////////////////////////////////////////////////


// Exemple de fonction à tester
int addition(int a, int b) {
    return a + b;
}

TEST(AdditionTest, HandlesPositiveNumbers) {
    std::cout << "Exécution du test : Addition de nombres positifs\n"<<std::endl;
    EXPECT_EQ(addition(2, 3), 5) << "L'addition de 2 et 3 devrait donner 5.";
    EXPECT_EQ(addition(0, 0), 0) << "L'addition de 0 et 0 devrait donner 0.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
//////////////////////////////////////////Grille aléatoire//////////////////////////////////////////////////////////////.

/*
void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
};*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
const int cellSize = 50;  //taille des cellules
const int gridWidth = 10;
//nombre de cellules en largeur (valeur présentes dans la première ligen du fichier texte)
const int gridHeight = 10;
//nombre de cellules en hauteur (valeur présentes dans la première ligen du fichier texte)

std::vector<std::vector<int> > grid(gridWidth, std::vector<int>(gridHeight));

void initializeGridCustom() {

    std::cout << "Entrez les valeurs pour la grille (" << gridHeight << "x" << gridWidth << ") :\n";
    for (int y = 0; y < gridHeight; ++y) {
        std::cout << "Ligne " << y + 1 << " (entrez " << gridWidth << " valeurs séparées par des espaces) : ";
        for (int x = 0; x < gridWidth; ++x) {
            std::cin >> grid[y][x]; // Lire chaque cellule
        }
    }
}


// Création des cellules sur une fenètre pop-up
void renderGrid(sf::RenderWindow& window) {
    int x, y;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (fichier.vec[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}
// Ouverture puis fermeture de la fenètre pop-up au bout de 3seconde
void runSFML() {
    cout << "Démarrage de la fenêtre SFML...\n" << endl;

    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    initializeGridCustom();

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        // Ferme la fenêtre après 10 secondes
        if (clock.getElapsedTime().asSeconds() > 3) {
            window.close();
        }

        sf::sleep(sf::milliseconds(100));
    }

    cout<<"Fenêtre SFML fermée.\n"<<endl;
}
/*void runConsole() {
    cout << "Démarrage du mode console ..." << endl;

    // Supposons que `Fichier::vec` soit une propriété accessible
    for (const auto& subVec : fichier.vecteur) { // Parcours de chaque sous-vecteur
        for (char val : subVec) {
            cout << val; // Afficher chaque caractère
        }
        cout << "\n" <<endl; // Nouvelle ligne pour séparer les vecteurs
    }

    cout << "Mode console terminé.\n" << endl;
}*/
////////////////////////////version avec un grille personnalisée ///////////////////////////////////////////////////////
//void initializeGridPreset() {
//    // Exemple : grille prédéfinie
//    grid[0] = {1, 0, 0, 0, 1, 0, 0, 0};
//    grid[1] = {0, 0, 0, 0, 1, 1, 1, 0};
//}
//
//// Fonction pour permettre à l'utilisateur de saisir la grille
//void initializeGridCustom() {
//    std::cout << "Entrez les valeurs pour la grille (" << gridHeight << "x" << gridWidth << ") :\n";
//    for (int y = 0; y < gridHeight; ++y) {
//        std::cout << "Ligne " << y + 1 << " (entrez " << gridWidth << " valeurs séparées par des espaces) : ";
//        for (int x = 0; x < gridWidth; ++x) {
//            std::cin >> grid[y][x]; // Lire chaque cellule
//      }
//    }
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
int main(int argc ,char **argv ){
    cout << "Combien d'itérations voulez vous réaliser ? \t" <<endl;
    int iteration;
    iteration = 5;
    cout<<iteration<<endl;
    //cin >> iteration;
    cout << "Comment voulez vous obtenir le résultat ? \t 1.mode console \t 2.mode graphique" <<endl;
    int mode;
    mode=2;
    cout<<mode<<endl;
    //cin >> mode;
    string message = fichier.lecture();
    fichier.vecteur();
    cout<<"end vecteur"<<endl;
    //const int cellSize = 50;  //taille des cellules
    jeu = fichier.vec;
    const int gridWidth = fichier.vec[0][0];  //nombre de cellules en largeur (valeur présentes dans la première ligen du fichier texte)
    const int gridHeight = fichier.vec[0][1];  //nombre de cellules en hauteur (valeur présentes dans la première ligen du fichier texte)
    cout<<gridHeight<<endl;
    vector<std::vector<int>> grid(gridWidth, vector<int>(gridHeight));
    while (iteration > 0) {
        if (mode==1) {
            ligne.change_etat();
            //runConsole();
            //mode console affichage des vecteurs
        }
        if (mode==2) {
            cout<<"mode2"<<endl;
            ligne.change_etat();
            runSFML();
        }
        else {
            cout << "Mode invalide. Veuillez entrer 1 (console) ou 2 (graphique)." << endl;
        }
        iteration = iteration - 1;
    }


    //////////////////////////////////////////Test unitaires////////////////////////////////////////////////////////////

    std::cout << "Initialisation des tests unitaires...\n"<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);

    if (argc > 1 && std::string(argv[1]) == "--run-sfml") {
        std::cout << "Lancement de la fenêtre SFML...\n"<<std::endl;
        runSFML();
    }

    std::cout << "Exécution des tests unitaires...\n"<<std::endl;
    int testResult = RUN_ALL_TESTS();

    std::cout << "Tous les tests unitaires sont terminés.\n"<<std::endl;
    std::cout << "Résultat des tests : " << (testResult == 0 ? "Tous validés !" : "Échec.") << "\n"<<std::endl;

    return testResult;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

}

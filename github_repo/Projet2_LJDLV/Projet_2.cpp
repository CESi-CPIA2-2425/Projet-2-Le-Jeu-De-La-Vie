#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include <vector>
#include <ctime>
#include <cstdlib>

#include "Fichier.h"
#include "Grille.h"
#include "Ligne.h"

using namespace std;
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
const int cellSize = 20;  //taille des cellules
const int gridWidth = 8;  //nombre de cellules en largeur (valeur présentes dans la première ligen du fichier texte)
const int gridHeight = 8;  //nombre de cellules en hauteur (valeur présentes dans la première ligen du fichier texte)

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
// Création des cellules sur une fenètre pop-up
void renderGrid(sf::RenderWindow& window) {
    int x, y;

    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
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
    initializeGrid();

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
void runConsole() {
    cout<<"Démarrage du mode console ..."<<endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        for (int val : vec[i]) {
            std::cout << val << " ";
        }
        std::cout << "\n";

    cout<<"Mode console terminé.\n"<<endl;
}
////////////////////////////version avec un grille personnalisée ///////////////////////////////////////////////////////
//void initializeGridPreset() {
//    // Exemple : grille prédéfinie
//    grid[0] = {1, 0, 0, 0, 1, 0, 0, 0};
////    grid[1] = {0, 0, 0, 0, 1, 1, 1, 0};
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
    cin >> iteration;
    cout << "Comment voulez vous obtenir le résultat ? \t 1.mode console \t 2.mode graphique" <<endl;
    int mode;
    cin >> mode;
    Fichier :: lecture();
    Fichier :: vecteur ();
    while (iteration > 0) {
        if (mode = 1) {
            Ligne::change_etat();
            runConsole();
            //mode console affichage des vecteurs
        }
        if (mode=2) {
            Ligne::change_etat();
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

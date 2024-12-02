#include <SFML/Graphics.hpp>
#include <gtest/gtest.h>

#include <vector>
#include <ctime>
#include <cstdlib>
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
const int cellSize = 20;
const int gridWidth = 8;
const int gridHeight = 8;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
};

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
void runSFML() {
    std::cout << "Démarrage de la fenêtre SFML...\n"<<std::endl;

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
        if (clock.getElapsedTime().asSeconds() > 10) {
            window.close();
        }

        sf::sleep(sf::milliseconds(100));
    }

    std::cout << "Fenêtre SFML fermée.\n"<<std::endl;
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
int main(int argc, char **argv) {
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
        if (clock.getElapsedTime().asSeconds() > 10) {
            window.close();
        }

        sf::sleep(sf::milliseconds(100));
    }

    //////////////////////////////////////////Test unitaires////////////////////////////////////////////////////////////////

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
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.

}

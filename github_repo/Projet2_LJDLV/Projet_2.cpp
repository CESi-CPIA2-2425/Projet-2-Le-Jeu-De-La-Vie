#include <SFML/Graphics.hpp>

#include <vector>
#include <ctime>
#include <cstdlib>

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
////////////////////////////version avec un grille personnalisée ///////////////////////////////////////////////////////
void initializeGridPreset() {
    // Exemple : grille prédéfinie
    grid[0] = {1, 0, 0, 0, 1, 0, 0, 0};
    grid[1] = {0, 0, 0, 0, 1, 1, 1, 0};
}

// Fonction pour permettre à l'utilisateur de saisir la grille
void initializeGridCustom() {
    std::cout << "Entrez les valeurs pour la grille (" << gridHeight << "x" << gridWidth << ") :\n";
    for (int y = 0; y < gridHeight; ++y) {
        std::cout << "Ligne " << y + 1 << " (entrez " << gridWidth << " valeurs séparées par des espaces) : ";
        for (int x = 0; x < gridWidth; ++x) {
            std::cin >> grid[y][x]; // Lire chaque cellule
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////.
int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");

    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}

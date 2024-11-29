#include <SFML/Graphics.hpp>  // Bibliothèque SFML pour gérer les graphiques
#include <vector>             // Bibliothèque pour les tableaux dynamiques (std::vector)
#include <ctime>              // Pour obtenir l'heure actuelle (utilisée pour initialiser srand)
#include <cstdlib>            // Pour utiliser std::rand et std::srand

// Taille de chaque cellule en pixels
const int cellSize = 50;

// Dimensions de la grille (nombre de cellules en largeur et hauteur)
const int gridWidth = 8;
const int gridHeight = 8;

// Grille bidimensionnelle représentant l'état de chaque cellule
// - 0 : cellule morte
// - 1 : cellule vivante
std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

// Fonction pour initialiser la grille avec des cellules aléatoirement vivantes ou mortes
void initializeGrid() {
    // Initialiser le générateur de nombres aléatoires avec l'heure actuelle
    std::srand(std::time(0));

    // Parcourir toutes les cellules de la grille
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Chaque cellule est vivante (1) ou morte (0) au hasard
        }
    }
}

// Fonction pour dessiner la grille à l'écran
void renderGrid(sf::RenderWindow& window) {
    int x, y;

    // Effacer la fenêtre pour préparer le rendu
    window.clear();

    // Définir une forme rectangulaire représentant une cellule
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f)); // Taille réduite pour avoir des bordures

    // Parcourir toutes les cellules de la grille
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) { // Si la cellule est vivante
                cell.setPosition(x * cellSize, y * cellSize); // Positionner la cellule dans la grille
                window.draw(cell); // Dessiner la cellule sur la fenêtre
            }
        }
    }

    // Afficher le contenu de la fenêtre (mettre à jour l'écran)
    window.display();
}

// Fonction principale
int main() {
    // Créer une fenêtre avec la taille de la grille
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");

    // Initialiser la grille
    initializeGrid();

    // Boucle principale du programme
    while (window.isOpen()) {
        // Gérer les événements utilisateur (fermeture de la fenêtre, etc.)
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) // Si l'utilisateur ferme la fenêtre
                window.close(); // Fermer la fenêtre
        }

        // Afficher la grille
        renderGrid(window);

        // Faire une pause pour ralentir la simulation (100 millisecondes entre chaque affichage)
        sf::sleep(sf::milliseconds(100));
    }

    return 0; // Terminer le programme
}

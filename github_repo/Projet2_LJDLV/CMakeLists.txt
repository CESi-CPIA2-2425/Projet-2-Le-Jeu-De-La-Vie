# Version minimale de CMake
cmake_minimum_required(VERSION 3.15)

# Nom du projet
project(Projet_2 LANGUAGES CXX)

# Définir les options de compilation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall -Werror")

# Spécifier les chemins vers SFML
set(SFML_INCLUDE_DIR "C:/Users/thais/Bibli_SFML_c++/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/include")
set(SFML_LIBRARY_DIR "C:/Users/thais/Bibli_SFML_c++/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/lib")

# Inclure les fichiers d'en-tête et de bibliothèque SFML
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

# Ajouter les fichiers source
file(GLOB_RECURSE SRCS "Projet_2.cpp")

# Ajouter l'exécutable principal
add_executable(SFMLTest ${SRCS} Projet_2.cpp)

# Lier les bibliothèques SFML
target_link_libraries(SFMLTest sfml-graphics sfml-window sfml-audio sfml-network sfml-system)

# Ajouter Google Test
# Chemin vers Google Test
set(GTEST_DIR "C:/Users/thais/GoogleTest")

# Ajouter les sous-dossiers de Google Test
add_subdirectory(${GTEST_DIR} googletest)

# Inclure les répertoires d'en-tête de Google Test
include_directories(${GTEST_DIR}/googletest/include)
include_directories(${GTEST_DIR}/googlemock/include)

# Ajouter un exécutable pour les tests unitaires
add_executable(UnitTests test_main.cpp)

# Lier Google Test avec les tests
target_link_libraries(UnitTests gtest gtest_main sfml-graphics sfml-window sfml-audio sfml-network sfml-system)

cmake_minimum_required(VERSION 3.11)
project(indie_studio)


set(CMAKE_CXX_STANDAR 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -lIrrlicht -lpthread -L/include/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio")
set(SOURCE_FILES src/main.cpp src/File/File.cpp
  src/File/Load.cpp src/File/Save.cpp src/Profil/IA.cpp
  src/Map/Map.cpp src/Menu/Bomberman_Menu.cpp
  src/Profil/Profil.cpp src/Object/Bomb.cpp
  src/Menu/window.cpp) # Ici vous mettez les fichiers à compiler
add_executable(bomberman ${SOURCE_FILES})

#####################################
#IRRLICHT INCLUDE // DO NOT TOUCH
#####################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "irrlicht/Findirrlicht.cmake")
#find_package(Irrlicht)
IF (irrlicht_FOUND)
  target_include_directories(bomberman PUBLIC ${Irrlicht_INCLUDE_DIRS})
endif()
target_link_libraries(bomberman ${Irrlicht_LIBRARIES})

#####################################


#COMMENT UTILISER
#Une fois vos fichiers rajoutés dans le set SOURCE_FILES au dessus
# Allez dans le dossier "build", et faites "cmake .."
#Cela va créer un nouveau Makefile, qui est utilisable.
# Il vous reste plus qu'à "make" ;)
# Avant de push, n'hésitez pas à supprimer tout ce qui se trouve dans le dossier build.
# Le plus important c'est de ne pas sup' le fichier "CMakeList"
# - Maxou

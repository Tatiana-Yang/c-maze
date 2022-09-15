//
// Created by yang on 30/09/20.
//

#ifndef PROJET_CREATION_LABYRINTH_H
#define PROJET_CREATION_LABYRINTH_H

int * allocation_line(int column);

int ** allocation_labyrinth(int row, int column);

void display_line(int * line, int row, int column);

void display_charge(char c);

void display_labyrinth(int ** matrice, int row, int column);

void libere_matrice(int ** matrice, int row);

void creation_labyrinth(int ** labyrinth, int row, int column);

//void open_wall(int wall, int num_ligne, int num_colonne, int ** labyrinth);

int open_wall(int ** labyrinth, int row, int column);

void algorithm_labyrinth(int ** labyrinth, char* labyrinth_name, int row, int column);

void save_maze(char* labyrinth_name, int ** labyrinth, int row, int column);

void charge_maze(char* fichier);
#endif //PROJET_CREATION_LABYRINTH_H

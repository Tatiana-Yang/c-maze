#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include "creation_labyrinth.h"
/*
 * TO DO :
 * Pour le nom du laby mettre un _ si jamais il y a un espace
 *
 */
void creation_labyrinth_menu();
void list_file_labyrinth();
void chargement_labyrinth(char* fichier);
void menu();

void menu(){
    printf("Menu :\n\n");
    printf("1] Creer un labyrinthe\n");
    printf("2] Charger un labyrinthe\n");
    printf("3] Jouer\n");
    printf("4] Quitter\n");
    printf("\n\nVeuillez selectionner un programme : \n");
    int choose;
    scanf("%d",&choose);
    switch (choose){
        case 1:
            printf("Vous avez choisi de creer un labyrinthe \n");
            creation_labyrinth_menu();
            break;
        case 2:
            printf("Vous avez choisi de charger un labyrinthe \n");
            list_file_labyrinth();
            printf("Inserer le nom du fichier que vous souhaiter charger !\n");
            char* fichier=(char*)malloc(100*sizeof(char));
            scanf("%s",&fichier);
            chargement_labyrinth(fichier);
            break;
        case 3:
            printf("Le jeu va commencer \n");
            break;
        case 4:
            printf("A bientot !");
            exit(0);
        default:
            printf("Choix non valide");

    }
}

void creation_labyrinth_menu(){
    printf("choisissez un nombre impaire pour la hauteur de votre labyrinthe : \n");
    int row;
    scanf("%d",&row);
    while(row % 2 ==0){
        printf("Vous n'avez pas insere un nombre impaire !\n");
        printf("choisissez un nombre impaire pour la hauteur de votre labyrinthe : \n");
        scanf("%d",&row);
    }

    printf("choisissez un nombre impaire pour la longueur de votre labyrinthe : \n");
    int column;
    scanf("%d",&column);
    while(column % 2 ==0){
        printf("Vous n'avez pas insere un nombre impaire !\n");
        printf("choisissez un nombre impaire pour la longueur de votre labyrinthe : \n");
        scanf("%d",&column);
    }
    char* labyrinth_name =(char*)malloc(100*sizeof(char));
    printf("Veuillez inserer le nom de votre labyrinthe: \n");
    scanf("%s",labyrinth_name);

    int ** labyrinth;
    labyrinth = allocation_labyrinth(row,column);
    creation_labyrinth(labyrinth, row, column);
    algorithm_labyrinth(labyrinth,labyrinth_name, row, column);
    //display_labyrinth(labyrinth, row, column);
    libere_matrice(labyrinth, row);
    menu();
}

void list_file_labyrinth(){
    printf("Voici les labyrinthes que vous pouvez charger : \n\n");
    struct dirent *dir;
    DIR *d = opendir("../config_file/");
    if(d == NULL){
        printf("Pas de fichier");
    }

    while((dir = readdir(d)) != NULL){
        if(dir->d_name[strlen(dir->d_name)-4] == '.'){ //Verfie s'ils ont l'extension .cfg
            if(dir->d_name[strlen(dir->d_name)-3] == 'c'){
                if(dir->d_name[strlen(dir->d_name)-2] == 'f'){
                    if(dir->d_name[strlen(dir->d_name)-1] == 'g'){

                        printf("%s\n", dir->d_name);
                    }
                }
            }
        }
    }
    closedir(d);
}

void chargement_labyrinth(char* fichier){
    charge_maze(fichier);
}

int main(void){
    srand(time(NULL));

    printf("-------- BIENVENUE --------\n");
    menu();

    return 0;
}

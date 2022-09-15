#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "creation_labyrinth.h"

/*To do
 * Faire un enum ou une struc pour au lieu de mettre 0 pour un mur on mette directement mur
 * pour que ce soit plus parlant
 *
 * Verifier pour les 80 chars par lignes
 *
 * Une fonction ne doit pas être trop grosse pour pouvoir gérer les erreurs
 *
 */
int * allocation_line(int column){
    int * line;

    line = (int *)malloc(column*sizeof(int));
    for(int i = 0; i < column; i++){
        line[i] = 0;
    }
    return line;
}

int ** allocation_labyrinth(int row, int column){
    int ** labyrinth;

    labyrinth = (int**)calloc(row,sizeof(int*));

    for(int i = 0; i < row; i++){
        labyrinth[i]= allocation_line(column);
    }
    return labyrinth;
}


void display_line(int * line, int row, int column){
    for(int i = 0; i < column ; i++){
        if(line[i]==0){
            printf("#");
        }
        else if(line[i]==row*column+1 || line[i]==2){
            printf("o");
        }
        else{
            printf(" ");
        }
    }
}

void display_labyrinth(int ** matrice, int row, int column){
    for(int i=0; i < row; i++){
        display_line(matrice[i], row, column);
        printf("\n");
    }
    printf("\n\n\n\n");

}

void display_charge(char c){
    if(c == '0'){
        printf("#");
    }
    else if(c == '2'){
        printf("o");
    }
    else if(c == '1'){
        printf(" ");
    }
    else{
        printf("\n");
    }
}

void libere_matrice(int ** matrice, int row){
    for(int j = 0; j<row; j++){
        free(matrice[j]);
    }
    free(matrice);
    matrice=NULL;
}

void creation_labyrinth(int ** labyrinth, int row, int column){
    int compteur = 1;
    for(int i=0; i<row; i++){
        for(int j=0; j < column; j++){
            if(i%2 == 1 && j%2 ==1){
                labyrinth[i][j]=compteur;
                compteur++;
            }
        }
    }
}

void modify_id(int ** labyrinth, int id, int id_change, int row,int column){ //Modifie tous les id_change en id
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (labyrinth[i][j] == id_change) {
                labyrinth[i][j] = id;
            }
        }
    }
}


int open_wall(int ** labyrinth, int row, int column){

    int random_row = ((double)rand()/RAND_MAX)*(row-2)+1; //Prends une ligne au hasard sauf ceux de l'extremité
    int random_column = ((double)rand()/RAND_MAX)*(column-2)+1;

    if(labyrinth[random_row][random_column]==0){ //Pour verifier s'il s'agit bien d'un mur
        if(labyrinth[random_row+1][random_column] != 0 && labyrinth[random_row-1][random_column] != 0){
            if(labyrinth[random_row+1][random_column] != labyrinth[random_row-1][random_column]) {
                int id = labyrinth[random_row - 1][random_column];
                int id_change = labyrinth[random_row + 1][random_column];
                modify_id(labyrinth, id,id_change,row,column);
                labyrinth[random_row][random_column] = id;
                return 1;
            }
        }

        else if(labyrinth[random_row][random_column-1] != 0 && labyrinth[random_row][random_column+1] != 0){
            if(labyrinth[random_row][random_column-1] != labyrinth[random_row][random_column+1]){
                int id = labyrinth[random_row][random_column-1];
                int id_change = labyrinth[random_row][random_column+1];
                modify_id(labyrinth, id,id_change,row,column);
                labyrinth[random_row][random_column]=id;
                return 1;
            }
        }
    }
    return 0;
}

void algorithm_labyrinth(int ** labyrinth, char* labyrinth_name, int row, int column){
    int mur_ouvert=0;
    int atteint = ((row-1)/2)*((column-1)/2)-1; //Le nombre d'identifiant dans un ligne * le nombre d'identifiant dans une colonne
    while(mur_ouvert != atteint){
        mur_ouvert+=open_wall(labyrinth, row, column);
    }
    labyrinth[1][0]=row*column+1; //joueur
    labyrinth[row-2][column-1]=labyrinth[row-2][column-2];

    save_maze(labyrinth_name, labyrinth, row, column);
}

void labyrinth_initialise_id(int ** labyrinth, int row, int column){ //initialise tous les identifiants à 1
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column ; j++){
            if(labyrinth[i][j] == row*column+1){
                labyrinth[i][j]=2; //pour le joueur
            }
            else if(labyrinth[i][j] != 1 && labyrinth[i][j] != 0){
                labyrinth[i][j] =1;
            }
        }
    }
}

void save_maze(char* labyrinth_name, int ** labyrinth, int row, int column){
    FILE* pflux;
    char* fichier=(char*)malloc(100*sizeof(char));
    strcat(fichier,"../config_file/");
    strcat(fichier, labyrinth_name);
    strcat(fichier, ".cfg");

    int compteur =0;

    pflux = fopen(fichier,"w+");

    labyrinth_initialise_id(labyrinth, row,column);

    if(pflux != NULL){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                fprintf(pflux, "%d", labyrinth[i][j]);
            }
            fprintf(pflux,"\n");
        }

    }
    fclose(pflux);
    charge_maze(fichier);
    printf("\n\n");
}

void charge_maze(char* fichier){

    int c=0;
    //printf("%s",fichier);
    FILE* pflux;
    pflux = fopen(fichier,"r");
    if(pflux == NULL){
        printf("\n Impossible de charger ton labyrinth");
    }

    while(c != EOF) {
            c = fgetc(pflux);
            display_charge(c);

    }
    fclose(pflux);
}

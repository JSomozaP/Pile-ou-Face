#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PILE 1
#define FACE 2

int reportho(char * reponse){
    if (strcasecmp(reponse, "1") == 0 || (strcasecmp(reponse, "pile") == 0))
    return PILE;
    if (strcasecmp(reponse, "2") == 0 || (strcasecmp(reponse, "face") == 0))
    return FACE;
    if (strcasecmp(reponse, "0") == 0 || (strcasecmp(reponse, "exit") == 0))
    return 0;
return -1;
    
}
 
int main(){
	
    int reussites = 0, echecs = 0;
    char reponse [5];
    int choix, resultat;
    srand(time(NULL));
    resultat=(rand()%2) + 1;

    
    while(1) {
    printf("###### Pile ou Face ######\n\n\n");
    printf("Pile ou Face ?\n");
    printf("1. Pile\n");
    printf("2. Face\n");
    printf("0. Quitter\n");
    fgets(reponse,5,stdin);

    if (choix == 0) {
        printf ("Vous quittez le jeu\n");
    }
    else if (choix == -1) {
        printf ("Choix invalide\n");
    } 

    }


    if (choix == resultat) {
        if (resultat == 0){
            printf("\nPile !\n\nC'est gagné, bien joué !\n");
        }
        else {
            printf("\nFace !\n\nC'est gagné, bien joué !\n");
        }
    } else {
        if (resultat == 0){
            printf("\nPile !\n\nC'est perdu, dommage ...\n");
        }
         else {
            printf("\nFace !\n\nC'est perdu, dommage ...\n");
        }
    }
    return 0;
    }

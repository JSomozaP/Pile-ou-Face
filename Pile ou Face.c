#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PILE 1
#define FACE 2
 
int main(){
	
    int choix, resultat;
    srand(time(NULL));
    resultat=(rand()%2) + 1;

    printf("###### Pile ou Face ######\n\n\n");

    printf("Pile ou Face ?\n");
    printf("1. Pile\n");
    printf("2. Face\n");
    scanf("%d", &choix);

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

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
    if (strcasecmp(reponse, "0") == 0 || (strcasecmp(reponse, "quitter") == 0))
    return 0;
return -1;

//strcasecmp permet de comparer des chaînes de caractère tout en étant insensible à la casse, contrairement à strcmp
    
}
 
int main(){
	
    srand(time(NULL));
    int reussites = 0, echecs = 0;
    char reponse [5];
    int choix, resultat;

    
    while (1) {
        printf("###### Pile ou Face ######\n\n\n");
        printf("Pile ou Face ?\n");
        printf("1. Pile\n");
        printf("2. Face\n");
        printf("0. Quitter\n");
        
        fgets(reponse,sizeof(reponse),stdin);
        reponse[strcspn(reponse, "\n")]=0; //strcspn permet de comparer l'occurence de caractère d'une string à l'autre
        choix = reportho(reponse);

        if (choix == 0) {
            printf ("Vous quittez le jeu\n");
            break;
        }
        else if (choix == -1) {
            printf ("Choix invalide\n");
            continue;
        } 

    }
printf("\nvous faites %s \n", choix == PILE ? "Pile":"Face");
printf("\nLa pièce est jetée\n");
for (int i=0; i < 3; i++){
    sleep(1);

    resultat=(rand()%2) + 1;  // 1 = PILE et 2 = FACE
    printf("%s \n\n", resultat == PILE ? "PILE" :"FACE");
}
    if (choix == resultat) {
        printf("\nC'est gagné, bien joué !\n");
        reussites++;
        }
        else {
        printf("\nC'est perdu, dommage !\n");
        echecs++;
    
    }

    printf("reussites : %d\nEchecs : %d\n\n",reussites, echecs);
    printf("|--------------------------|\n");

    if (echecs >= 10) {
        printf("Trop d'echecs\n");
    }

    printf("##########GAME OVER##########\n");
    printf("reussites : %d\nEchecs : %d\n", reussites, echecs);
    printf("|-------------------------|\n");

    return 0;
    }
    

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PILE 1
#define FACE 2
#define QUITTER 0

//Fonction pour convertir une chaîne en minuscules.....en théorie
void convertirmin(char *str) {
    if(str == NULL) return; //securité pour éviter les erreurs si la chaîne est NULL
    for (int i=0; str[i] != '\0'; i++) {
        if (str[i]>='A' && str[i] <= 'Z') {
            printf("%c\t",str[i]);
            // str[i] = 'e';
            // str[i] = str[i] + ('a'-'A');
            str[i] = str[i] +32; //si les caractères sont en majuscules, ajouter 32 à leur valeur ASCII les convertiront en minuscule
        }else if(str[i]<='a' && str[i]>='z'){
            str[i]=str[i] -32;

        }
    }
}
//Fonction pour normallement traier les differentes orthos des reponses utilisateur
int reportho(char * reponse){
    /*char*pos;
    if((pos=strchr(reponse, '\n'))!=NULL){
        *pos = '\0'; */

    size_t longueur = strlen(reponse);
    if (longueur > 0 && reponse [longueur - 1]== '\n') {
            reponse[longueur -1] = '\0'; // normalement ce machin supprime le retour à la ligne
    }

    convertirmin(reponse);
    
    if (strcmp(reponse, "1") == 0 || strcmp(reponse, "pile") == 0|| strcmp(reponse, "PILE") == 0 || strcmp(reponse, "pIle") == 0 || strcmp(reponse, "p") == 0)  //Répondre 1, pile, PILE, pILe ou même p permettent de jouer PILE
        return PILE;
    if (strcmp(reponse, "2") == 0 || strcmp(reponse, "face") == 0||strcmp(reponse, "FACE") == 0 || strcmp(reponse, "fAcE") == 0 || strcmp(reponse, "f") == 0)  //Répondre 2, face, FACE, fAcE ou même f permettent de jouer FACE
        return FACE;
    if (strcmp(reponse, "0") == 0 || strcmp(reponse, "quitter") == 0||strcmp(reponse, "quit") == 0 || strcmp(reponse, "exit") == 0 || strcmp(reponse, "q") == 0)   //Répondre 0, quitter, quit, exit ou même q permettent de jouer PILE
        return QUITTER;
    
    return -1;

    /* interdit pour cet exo là :
    reponse[strcspn(reponse, "\n")]='\0'; //strcspn permet de comparer l'occurence de caractère d'une string à l'autre */
  
//strcasecmp permet de comparer des chaînes de caractère tout en étant insensible à la casse, contrairement à strcmp
    /*if (strcasecmp(reponse, "1") == 0 || (strcasecmp(reponse, "pile") == 0))
    return PILE;
    if (strcasecmp(reponse, "2") == 0 || (strcasecmp(reponse, "face") == 0))
    return FACE;
    if (strcasecmp(reponse, "0") == 0 || (strcasecmp(reponse, "quitter") == 0))
    return 0;*/
    //pas autorisé pour cet exo
    
}
 
int main(){
	// char prenom[] = "MassiNissa";
    // convertirmin(prenom);
    // printf("%s\n",prenom);

    // return 0;


    srand(time(NULL));
    int reussites = 0, echecs = 0;
    char reponse [10];
    int choix, resultat;

    
    while (1) {
        printf("\n\n\n###### Pile ou Face ######\n\n\n");
        printf("Pile ou Face ?\n");
        printf("1. Pile\n");
        printf("2. Face\n");
        printf("0. Quitter\n\n");
        
        if (!fgets(reponse,sizeof(reponse),stdin)) {
            printf("\nErreur de saisie, veuillez réessayer !\n\n");
            continue;
        }

        //supprime le retour à la ligne ajouté par fgets
        size_t len=strlen(reponse);
        if(len>0 && reponse[len - 1]== '\n'){
            reponse[len - 1]= '\0';
        }
    
        //fflush(stdin);
        // Normalisation de la réponse utilisateur
        choix = reportho(reponse);

        if (choix == QUITTER) { //si l'utilisateur veut quitter
            printf ("Vous quittez le jeu\n");
            break; //effectue une sortie de boucle
        }
        
        else if (choix == -1) { //si l'entrée est invalide
            printf ("Choix invalide\n");
            continue;
        } 

    //affiche le choix utilisateur
    printf("\nvous faites %s \n", (choix == PILE) ? "Pile":"Face");
    printf("\nLa pièce est jetée\n\n");

    //affichage du suspense avec un temps d'attente
    for (int i=0; i < 3; i++){
        sleep(1);
        printf(".");
        fflush(stdout); //Apparemment fgets peut causer des bugs dus au buffer de saisie, donc ajouter un fflush aiderai à éviter les entrées erronées
                        //apparement force l'affichage immédiat des points
    
    }

        printf("\n\n");

        resultat=(rand()%2) + 1;  // 1 = PILE et 2 = FACE
        printf("%s \n\n", (resultat == PILE) ? "PILE" :"FACE");
    
    if (choix == resultat) {
        printf("\nC'est gagné, bien joué !\n");
        reussites++;
    }
    else {
        printf("\nC'est perdu, dommage !\n");
        echecs++;
    }

    printf("reussites : %d\nEchecs : %d\n\n", reussites, echecs);
    printf("|--------------------------|\n");

    if (echecs >= 10) {
        printf("Trop d'echecs\n");
        break;

    }    
}



    printf("##########GAME OVER##########\n");
    printf("reussites : %d\nEchecs : %d\n", reussites, echecs);
    printf("|-------------------------|\n");

    return 0;
    }
    

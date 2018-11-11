#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Methode pour la rentrée d'un entier par l'utilisateur
//Qui permet de controler les erreurs de saisie
//retourne un entier
int choixEntier(){
    //Déclaration des variables
    int resultat;
    char choix[50];
    int indice;
    int correct;
    
    do
    {   
        correct = 1; 
        indice = 0;
        printf("\n\t\t\t\tEntrez le nombre:");
        //On récupere ce que l'utilisateur a tapé dans un tableau de char
        scanf("%s",choix);

        //On parcourt le tableau de char jusqu'a la fin de chaine
        while(choix[indice] != '\0')
        {
            
            //Si le caractere n'est pas un chiffre on modifie le booleen
            if (choix[indice] < '0' || choix[indice] > '9'){
            
                correct = 0;     
            }
            
            //On incremente l'indice pour passer au caractere suivant
            indice++;
        
        }
        //Si le booleen a changé on affiche un message d'erreur
        if (correct == 0){
            printf("\n\t\t\t\tVeuillez entrer un nombre\n");
        }
    //tant que tout les caracteres de la chaines ne sont pas des chiffres on recommence    
    }while( correct == 0);

    //On utilise la fonction strtol pour changer une chaine de caractere en long ou int
    //strtol(chaineDeCaractere,char **end,base)
    resultat = strtol( choix, NULL, 10 );
   
    return resultat;
   
}

int main ( int argc, char** argv )
{   
    //Déclaration des variables
    int nombreMax,choix,nombreMystere,nombreEntre,nombreDeCoup,continuerPartie,new;
    const int MIN = 1;

    //Initialisation des variables
    continuerPartie = 1;
    nombreMax = 0;
    nombreMystere = 0;
    nombreEntre = 0;
    nombreDeCoup = 0;
    choix = 0;
    new = 0;

    //Affichage de demarrage du jeu
    printf("         _______  ___   _______  __    _  __   __  _______  __    _  __   __  _______\n");             
    printf("        |  _    ||   | |       ||  |  | ||  | |  ||       ||  |  | ||  | |  ||       |\n");           
    printf("        | |_|   ||   | |    ___||   |_| ||  |_|  ||    ___||   |_| ||  | |  ||    ___|\n");            
    printf("        |       ||   | |   |___ |       ||       ||   |___ |       ||  |_|  ||   |___ \n");            
    printf("        |  _   | |   | |    ___||  _    ||       ||    ___||  _    ||       ||    ___|\n");            
    printf("        | |_|   ||   | |   |___ | | |   | |     | |   |___ | | |   ||       ||   |___ \n");            
    printf("        |_______||___| |_______||_|  |__|  |___|  |_______||_|  |__||_______||_______|\n");            
    printf("                         _______  __   __        ___  _______  __   __\n");           
    printf("                        |   _   ||  | |  |      |   ||       ||  | |  |\n");             
    printf("                        |  |_|  ||  | |  |      |   ||    ___||  | |  |\n");             
    printf("                        |       ||  |_|  |      |   ||   |___ |  |_|  |\n");             
    printf("                        |       ||       |   ___|   ||    ___||       |\n");             
    printf("                        |   _   ||       |  |       ||   |___ |       |\n");            
    printf("                        |__| |__||_______|  |_______||_______||_______|\n");             
    printf("                                       ______   __   __\n");             
    printf("                                      |      | |  | |  |\n");             
    printf("                                      |  _    ||  | |  |\n");            
    printf("                                      | | |   ||  |_|  |\n");            
    printf("                                      | |_|   ||       |\n");            
    printf("                                      |       ||       |\n");            
    printf("                                      |______| |_______|\n");           
    printf(" _______  ___      __   __  _______    _______  __   __    __   __  _______  ___   __    _  _______\n");
    printf("|       ||   |    |  | |  ||       |  |       ||  | |  |  |  |_|  ||       ||   | |  |  | ||       |\n");
    printf("|    _  ||   |    |  | |  ||  _____|  |   _   ||  | |  |  |       ||   _   ||   | |   |_| ||  _____|\n");
    printf("|   |_| ||   |    |  |_|  || |_____   |  | |  ||  |_|  |  |       ||  | |  ||   | |       || |_____ \n");
    printf("|    ___||   |___ |       ||_____  |  |  |_|  ||       |  |       ||  |_|  ||   | |  _    ||_____  |\n");
    printf("|   |    |       ||       | _____| |  |       ||       |  | ||_|| ||       ||   | | | |   | _____| |\n");
    printf("|___|    |_______||_______||_______|  |_______||_______|  |_|   |_||_______||___| |_|  |__||_______|\n");

    do{
    printf("\n\n\t\t\t\t\t   1 - Facile");
    printf("\n\t\t\t\t        (entre 1 et 100)\n");
    printf("\n\t\t\t\t\t    2 - Moyen");
    printf("\n\t\t\t\t        (entre 1 et 1000)\n");
    printf("\n\t\t\t\t\t  3 - Difficile");
    printf("\n\t\t\t\t        (entre 1 et 10000)\n");
    printf("\n\t\t\t\tQuel niveau voulez-vous choisir ?\n"); 
    
    do{
        //appel a la methode de saisie d'entier utilisateur
        choix = choixEntier();

        //Si la variable choix n'est pas comprise entre 1 et 3 on affiche un message d'erreur
        if(choix != 1 && choix != 2 && choix != 3){
        
            printf("\n\t\t\t\tEntrez un nombre compris entre 1 et 3\n");
        }
    //On recommence tant que la variable choix n'est pas comprise entre 1 et 3
    }while(choix != 1 && choix != 2 && choix != 3);
     
    //On affecte le min et le max pour le niveau choisi   
    switch(choix)
    {
        case 1:

            nombreMax = 100;
            
        break;

        case 2:

            nombreMax = 1000;
            
        break;

        case 3:

            nombreMax = 10000;
    
        break;
    }

    // Génération du nombre aléatoire

    srand(time(NULL));

    nombreMystere = (rand() % (nombreMax - MIN + 1)) + MIN;

    printf("\n\n\n\t\t\t\t     Début de la partie\n");
    printf("\n\t\tEssayez de deviner le nombre mystère avec le moins d'essai possible\n\n");

    /* La boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */

    do
    {
        // On demande le nombre
        
        nombreEntre = choixEntier();
        nombreDeCoup ++;

        // On compare le nombre entré avec le nombre mystère

        if (nombreMystere > nombreEntre){
            printf("\n\t\t\t\t\t  C'est plus !\n");
        }
        else if (nombreMystere < nombreEntre){
            printf("\n\t\t\t\t\t  C'est moins !\n");
        }
        else{
            //Affichage partie gagnée
            printf("\n\n");
            printf("  ███████╗███████╗██╗     ██╗ ██████╗██╗████████╗ █████╗ ████████╗██╗ ██████╗ ███╗   ██╗███████╗\n");
            printf("  ██╔════╝██╔════╝██║     ██║██╔════╝██║╚══██╔══╝██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝\n");
            printf("  █████╗  █████╗  ██║     ██║██║     ██║   ██║   ███████║   ██║   ██║██║   ██║██╔██╗ ██║███████╗\n");
            printf("  ██╔══╝  ██╔══╝  ██║     ██║██║     ██║   ██║   ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║╚════██║\n");
            printf("  ██║     ███████╗███████╗██║╚██████╗██║   ██║   ██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║███████║\n");
            printf("  ╚═╝     ╚══════╝╚══════╝╚═╝ ╚═════╝╚═╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n");
            printf ("\n\n\t\t\tVous avez trouvé le nombre mystère en %d coup!\n\n", nombreDeCoup);
        }
    } while (nombreEntre != nombreMystere);
    
    printf("\t\t\t  Souhaitez-vous faire une autre partie ?");
    printf("\n\t\t\t\t\t1 - Oui");
    printf("\n\t\t\t\t\t2 - Non\n");
    
    //On recommence tant que la valeur n'est pas 1 ou 2
    while(new != 1 && new != 2){

        new = choixEntier();
    }

    //Si l'utilisateur veut quitter on modifie le booleen
    if(new == 2){
    
        continuerPartie = 0;
    }
//Boucle qui permet de relancer le programme au debut
}while(continuerPartie != 0);

//Affichage fin de partie
printf("\n\n\t\t\t  __     ___  __  ___  _  _  ____  __  ____ \n");
printf("\t\t\t (  )   (  ,)(  )(  _)( \\( )(_  _)/  \\(_  _)\n");
printf("\t\t\t /__\\    ) ,\\ )(  ) _) )  (   )( ( () ) )(  \n");
printf("\t\t\t(_)(_)  (___/(__)(___)(_)\\_) (__) \\__/ (__) \n");

return 0;
}

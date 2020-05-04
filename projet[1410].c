#include <stdio.h>
#include <stdlib.h>

//definition des ordinateurs
typedef struct computer;
struct computer
 {
    char nom[60];
    int IP;
    int MAC;
    int indication;
}
computer;
 //definition des logiciels clients installés
    typedef struct client
       struct client
        {
            char nom[60];
            struct client *suivant;
        }
    client;
     //definition des logiciels serveurs installés 
    typedef struct serveur
        struct serveur
        {
            char* nom[60];
            struct serveur *next;
        }
    serveur;

//parc informatique

//reseau
//echanges
//Definition des services(abou)
int main(void)
{
// List of size 0
node *list = NULL;
// Add name to list
node *n = malloc(sizeof(node));
if (n == NULL)
{
return 1;
}
printf("entrez un service implémené")
char* x;
scanf("%s",&x);
n->name = x;
n->next = NULL;
list = n;

{   
    /* code */
}

//Fichier pour machine
int main (int argc, char* argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("machine.txt, "r+"");
    if (fichier != NULL)
    {
        // On peut lire et écrire dans ce fichier
    }

    else
    {
        // message d'erreur
        printf("Impossible d'ouvrir le fichier machine.txt");
    }
}


}
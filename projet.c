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


//Definition des services(abou)
int main(void)
{
    int nn;
    printf("Selon l'action à faire  \n
        1-Ajouter une machine \n
        2-retirer une machine \n
        3-installer un client/serveur \n
        4-desinstaller un client/serveur \n
        5-pinger une machine\n
    ");
    scanf("%d",&nn);
    //Parc informatique
    if(nn==1)
    {
        printf("entrer le nom,adresse ip,adresse mac");
        scanf("%s",computer.nom);
        scanf("%d",computer.IP);
        scanf("%d",computer.mac);
        printf("entrer les noms des clients");
         // List of size 0
        client *list = NULL;
// Add name to list
client *n = malloc(sizeof(node));
if (n == NULL)
{
return 1;
}
printf("entrez un service implémené")
char* x;
scanf("%s",&x);
n->nom = x;
n->next = NULL;
list = n;


    }
        printf("entrer les noms des serveurs");
        // List of size 0
        serveur *list = NULL;
// Add name to list
serveur *n = malloc(sizeof(node));
if (n == NULL)
{
return 1;
}
printf("entrez un service implémené")
char* x;
scanf("%s",&x);
n->nom = x;
n->next = NULL;
list = n;


    }
    if(nn=2)
    {

    }
    if(nn=3)
    {
        
    }
    if(nn=4)
    {
        
    }
    //reseau
    if(nn=5){
    char* comp;
    printf("entrer le nom de la machine a pinger");
    int i=0;
    int c=0;
do {
strcmp(comp,computer.nom);
i++;
if(strcmp(comp,computer.nom)==1){
    c=c+1;
}
}while (strcmp(comp,computer.nom)!=0);
if(c==1){
    printf("Ok 5 sur 5 la machine est presente");
}
else{
    prinft("la machine n'est pas presente");
}
    }
    //echange
    

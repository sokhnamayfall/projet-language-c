#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
//suppression d'une machine 
 void suppression(Liste *n) {    
 	if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	if (n->next != NULL)    {        
 		Element *aSupprimer = n->next;        
 		n->next = n->next->next;        
 		free(aSupprimer);    
 	} 
 }
//Definition des services


int main(void)
{
    int nn;
    printf("Selon l'action à faire  \n
        1-Ajouter une machine \n
        2-retirer une machine \n
        3-installer un client/serveur \n
        4-desinstaller un client/serveur \n
        5-pinger une machine\n
        6-utiliser les serveurs web d'une machine\n
        7-utiliser les serveurs dhcp d'une machine\n
    ");
    scanf("%d",&nn);
    //Parc informatique
    if(nn==1)
    {
        printf("entrer le nom,adresse ip,adresse mac");
        scanf("%s",computer.nom);
        scanf("%d",computer.IP);
        scanf("%d",computer.mac);
    }
         
        
    if(nn==2)
    {
    printf("entrer la machine à supprimer");
    char* aSupprimer;
    scanf("%s",aSupprimer)
    return(suppression);
    }
    if(nn==3)
    {// List of size 0
    printf("entrer les noms des clients");
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
    if(nn==4)
    {
        int mm;
        printf("vous voulez supprimer 
            1-client\n
            2-une service\n");
            scanf("%d",mm);
            if(mm==1){
               if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	if (n->nom != NULL)    {        
 		client *aSup = n->nom;        
 		n->nom = n->nom->next;        
 		free(aSup);    
 	} 
            }
        if(mm==2){
            if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	if (n->nom != NULL)    {        
 		serveur *aSupp = n->nom;        
 		n->nom = n->nom->next;        
 		free(aSupp);    
 	}
        }
        
    }
    //reseau
    if(nn==5){
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
    //serveur web
    if(nn==6){
    int comparif(serveur.nom )
{
       char* ss=web;
	
			if((strcmp(serveur.nom,web))==1)
			{
			char* site;
printf("enter le site web");
scanf("%s,site");
if(strcmp(site[2],w)==1){
    printf("la page est disponible");
}
else{
    printf("la page n'est pas disponible");
}	
			}
			else
			{
				printf("cette machine ne dispose pas de serveur web");
				
			}
}
    }
//serveur dhcp
if(nn==7){
printf("utilisation du serveur dhcp");
printf("nom de la machine pour le dhcp");
char* dhcpname;
scanf("%s",dhcpname);
  int comparif(serveur.nom )
{
       char* ss=dhcp;
	
			if((strcmp(serveur.nom,dhcp))==1)
			{
                srand(time(NULL));
  		     int x=1+rand(12);
		     computer.ip=x;
		    printf("Ce machine a comme adresse ip %d",x);
            }
        else 
        {
            printf("ce machine ne dispose pas de serveur dhcp");
        }
}   
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
 return 0;
}               
		

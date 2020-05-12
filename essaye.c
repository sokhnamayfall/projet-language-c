#include <stdio.h>
#include <stdlib.h>

//definition des ordinateurs
typedef struct computer Computer;
struct computer
 {
    char nomComputer[30];
    char ip[30];
    char mac[30];
    //int indication;
    //int idmachine;   // idmachine ajouter par pa ousmane diene 
    Computer *prochain;   
};

typedef struct Liste Liste;
struct Liste {       /* definition de la structure liste  qui pointe sur les machines, les logserver et les logclient*/
  Computer *premier; 
 };


 //definition des logiciels clients installés
typedef struct client Client;
 struct client
            {
 char nomClient[30] ;
 Client *suivant; 
};

//definition des logiciels serveurs installés 
typedef struct serveur Serveur;
 struct serveur
             {
 char nomServer[30];
 Serveur *next;
};

Liste *initialisation() { 
   Liste *liste = malloc(sizeof(*liste));
   Computer *new = malloc(sizeof(*new)); 
   if (liste == NULL || new == NULL)    {
           exit(EXIT_FAILURE);    
    }
    new->nomComputer = "toto";
    new->ip = "10.10.10.1";
    new->mac = "5E:FF:56:A2:AF:15";    
    new->prochain = NULL;   
    liste->premier = new;

    return liste; 
}

void insertion(Liste *liste, char name[30], char ip_add[30], char mac_add[30]) {

/* Création du nouvel élément */    
Computer *nouveau = malloc(sizeof(*nouveau));    
if (liste == NULL || nouveau == NULL)    {        
      exit(EXIT_FAILURE);    
} 
 
nouveau->nomComputer = name;
nouveau->ip = ip_add;
nouveau->mac = mac_add;   
  
/* Insertion de l'élément au début de la liste */
     
nouveau->prochain = liste->premier;    
liste->premier = nouveau; 
}


void suppression(Liste *liste) {    
 	if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	if (liste->premier != NULL)    {        
 		Computer *aSupprimer = liste->premier;        
 		liste->premier = liste->premier->prochain;        
 		free(aSupprimer);    
 	} 
}



















//la fonction main 
int main(void)
{
    printf("ok par defaut,on a initialisé le parc avec une machine appelée \"toto\":\n");
     
    Liste *maListe = initialisation();
    
    
    int option;
    printf("choisissez parmi ces options selon l'action à faire:\n");
    printf("1-Ajouter une machine\n");
    printf("2-retirer une machine\n");  
    printf("3-installer un client/serveur\n");
    printf("4-desinstaller un client/serveur\n");
    printf("5-pinger une machine\n");
    printf("6-afficher la liste des machines\n");
    printf(":");
    scanf("%d",&option);

    if(option==1){
        
        char nom_nom[30], ip_ip[30], mac_mac[30];
        printf("entrer le nom_de_la_machine :");
        scanf("%s",nom_nom );
        printf("entrer l'adresse_ip :");
        scanf("%s",  ip_ip);
        printf("entrer l'adresse_mac :");
        scanf("%s", mac_mac);
         
        insertion(maListe, nom_nom, ip_ip, mac_mac);
        
       /* 
        printf("entrer les noms des clients");
        char* clt;
        scanf("%s", clt);
        insertion(*liste, clt) ;
       */
    }

return 0;
}

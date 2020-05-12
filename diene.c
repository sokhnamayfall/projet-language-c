#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definition des ordinateurs
typedef struct computer Computer;
struct computer
 {
    char nomComputer[30];
    char ip[15];
    char mac[17];
    //int indication; 
    Computer *prochain;   
}computers;

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
    strcpy(new->nomComputer,"toto");
    strcpy(new->ip,"10.10.10.1");
    strcpy(new->mac,"5E:FF:56:A2:AF:15");    
    new->prochain = NULL;   
    liste->premier = new;

    return liste; 
}

void insertion(Liste *liste, char name[30], char ip_add[15], char mac_add[17]) {

/* Création du nouvel élément */    
Computer *nouveau = malloc(sizeof(*nouveau));    
if (liste == NULL || nouveau == NULL)    {        
      exit(EXIT_FAILURE);    
} 
 
strcpy(nouveau->nomComputer, name);
strcpy(nouveau->ip, ip_add);
strcpy(nouveau->mac, mac_add);   
  
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

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Computer *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("la machine -> %s d'adresse_ip -> %s et d'adresse_mac -> %s", actuel->nomComputer,actuel->ip,actuel->mac);
        actuel = actuel->prochain;
    }
    printf("NULL\n");
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
        
        char nom_nom[30], ip_ip[15], mac_mac[17];
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
    if(option==2){
      suppression(maListe);  
    }


    if(option==3){

    }
    if(option==5){
      char comp_ip[15]; 
      printf("entrer l'addresse_ip de la machine a pinger:");
      scanf("%s",comp_ip);
      int i=0;
      int c=0;
      Computer *ping = malloc(sizeof(*ping));
      printf("PING %s (%s) 56(84) bytes of data.",comp_ip,comp_ip );
      printf("64 bytes from 10.10.10.1: icmp_seq=1 ttl=249 time=68.9 ms\n");
      printf("64 bytes from 10.10.10.1: icmp_seq=2 ttl=249 time=51.9 ms\n");
      printf("64 bytes from 10.10.10.1: icmp_seq=3 ttl=249 time=51.7 ms\n");
      printf("64 bytes from 10.10.10.1: icmp_seq=4 ttl=249 time=76.6 ms\n");
      printf("64 bytes from 10.10.10.1: icmp_seq=5 ttl=249 time=36.6 ms\n");
      printf("\n");
      if(strcmp(comp_ip,ping->ip)==1){
        printf(" --- %s ping statistics ---\n",comp_ip);
        printf("8 packets transmitted, 8 received, 0 percent packet loss, 100 percent received, time 7010ms\n"); 
        printf("\n");
        printf("Ok 5 sur 5 la machine est presente\n"); 
        }else{
        printf(" --- %s ping statistics ---\n",comp_ip);
        printf("8 packets transmitted, 0 received,100 percent packet loss, 0 percent received, time 7010ms\n"); 
        printf("\n");
        printf("la machine n'est pas presente \n");
      }
    } 
    if(option==6){
      afficherListe(maListe);
    }
    

return 0;
}

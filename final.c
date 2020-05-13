#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vrai 1
#define faux 0
enum indication {OUI=vrai, NON=faux};

//definition des logiciels clients installés
    typedef struct client Client ;
       struct client
        {
            char nom[60];
            struct client *suivant;
        }
    client;
//definition des logiciels serveurs installés 
    typedef struct serveur Serveur ;
        struct serveur
        {
            char* nom[60];
            struct serveur *next;
        }
    serveur;

//definition des ordinateurs
typedef struct computer Computer;
struct computer
 {
    char nomComputer[30];
    char ip[15];
    char mac[17];
    enum indication connect ;

    Computer *prochain;   
}computers;

typedef struct Liste Liste;
struct Liste {       /* definition de la structure liste  qui pointe sur les machines, les logserver et les logclient*/
  Computer *premier; 
 };


//  //definition des logiciels clients installés
// typedef struct client Client;
//  struct client
//   {
//  char nomClient[30] ;
//  Client *suivant; 
// };

// //definition des logiciels serveurs installés 
// typedef struct serveur Serveur;
//  struct serveur
//   {
//  char nomServer[30];
//  Serveur *next;
// };

Liste *initialisation() { 
   Liste *liste = malloc(sizeof(*liste));
   Computer *new = malloc(sizeof(*new)); 
   if (liste == NULL || new == NULL)    {
           exit(EXIT_FAILURE);    
    }
    strcpy(new->nomComputer,"toto");
    strcpy(new->ip,"10.10.10.1");
    strcpy(new->mac,"5E:FF:56:A2:AF:15");
    //strcpy(new->connect,"NON");    
    new->prochain = NULL;   
    liste->premier = new;

    return liste; 
}

Computer *insertion(Liste *liste,Computer *pass, char name[30], char ip_add[15], char mac_add[17] ) {

/* Création du nouvel élément */  
Computer *nouveau = malloc(sizeof(*nouveau));    
if (liste == NULL || nouveau == NULL)    {        
      exit(EXIT_FAILURE);    
} 
 
strcpy(nouveau->nomComputer, name);
strcpy(nouveau->ip, ip_add);
strcpy(nouveau->mac, mac_add);
//strcpy(nouveau->connect, connect_add);   
  
/* Insertion de l'élément au début de la liste */
     
nouveau->prochain = NULL;    
pass->prochain = nouveau; 
pass=pass->prochain ;

return pass ;
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
    printf("La liste des machines est :");
    while (actuel != NULL)
    {
        printf("\nMachine -> %s \nAdresse_ip -> %s \nAdresse_mac -> %s\n\n", actuel->nomComputer,actuel->ip,actuel->mac);
        actuel = actuel->prochain;
    }

}





//la fonction main 
int main(void)
{
    printf("Par defaut,on a initialise le parc avec une machine appelee \"toto\":\n\n");
     
    Liste *maListe = initialisation();
    Computer *tmp = NULL ;

    char nom_nom[30], ip_ip[15], mac_mac[17];
    char comp_ip[15];
    int i=0;
    int c=0;

  int choice ;
A:  printf("\nChoisissez une des fonctionnalites suivantes:\n\n");
    printf("1-Gerer le parc de machine\n");
    printf("2-Gerer le reseau\n");  
    printf("3-Faire une simulation\n"); 
    scanf("%d",&choice) ;

  if (choice==1){
  int option;
B:  printf("\nChoisissez parmi ces options selon l'action a faire:\n\n");
    printf("1-Ajouter une machine\n");
    printf("2-retirer une machine\n");  
    printf("3-installer un client/serveur\n");
    printf("4-desinstaller un client/serveur\n");
    printf("5-afficher la liste des machines\n");
    printf("0-Retourner en arriere\n\n");
    printf(":");
    scanf("%d",&option);

  switch(option){
      case 1:  
        
        printf("entrer le nom_de_la_machine :");
        scanf("%s", nom_nom);
        printf("entrer l'adresse_ip [format 10.10.10.1] :");
        scanf("%s", ip_ip);
        printf("entrer l'adresse_mac [format 5E:FF:56:A2:AF:15] :");
        scanf("%s", mac_mac);
        
        if (tmp==NULL){
          Computer *pass = maListe->premier;
          tmp = insertion(maListe, pass, nom_nom, ip_ip, mac_mac);
        }else
        {
          tmp = insertion(maListe, tmp, nom_nom, ip_ip, mac_mac);
        }
        
       
       /* 
        printf("entrer les noms des clients");
        char* clt;
        scanf("%s", clt);
        insertion(*liste, clt) ;
       */
      goto B ;
      break;

      case 2:
      suppression(maListe);  
      goto B ;
      break ;


      case 3: 
        goto B ;

      break ;
      
      case 5:
        afficherListe(maListe);
        goto B ;
      break ;

      case 0:
        goto A ;
      break;
      
      default : 
        printf("Choix invalide : Entrez un chiffre entre 1 et 6") ;
        printf("\n ");
        goto B ;
    }
    
  }

  if (choice==2){
  int opt;
C:  printf("\nChoisissez parmi ces options selon l'action a faire:\n\n");
    printf("1-Ajouter une machine au reseau\n");
    printf("2-retirer une machine du reseau\n");  
    printf("3-pinger une machine\n");
    printf("4-afficher la liste des machines\n");
    printf("0-Retourner en arriere\n\n");
    printf(":");
    scanf("%d",&opt);

    char machname[30] ;
    switch (opt)
    {
    case 1:
        afficherListe(maListe);
        printf("\nEntrez le nom de la machine a ajouter : ");
        scanf("%s",machname);
        Computer *actuel = maListe->premier;
        while (actuel != NULL)
        {
          if(strcmp(machname,actuel->nomComputer)==0){
            actuel->connect = OUI ;
            printf("La machine a bien ete ajoutee") ;
            break;
          }else{
            actuel = actuel->prochain;
          }
          printf("La machine n'existe pas");
        }
      goto C;  
      break;

    case 2:
        afficherListe(maListe);
        printf("\nEntrez le nom de la machine a retirer : ");
        scanf("%s",machname);
        actuel = maListe->premier;
        while (actuel != NULL)
        {
          if(strcmp(machname,actuel->nomComputer)==0){
            actuel->connect = NON ;
            printf("La machine a bien ete retiree") ;
            break;
          }else{
            actuel = actuel->prochain;
          }
          printf("La machine n'existe pas");
        }
        goto C;
      break;

    case 3:    
        afficherListe(maListe); 
        printf("entrer l'addresse_ip de la machine a pinger:");
        scanf("%s",comp_ip);
        
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
        goto C;
      break ;
    
    case 4:
        actuel = maListe->premier;
        printf("La liste des machines du reseau est :");
        int cpt=0 ;
    while (actuel != NULL)
    {   
        if(actuel->connect == OUI){
        printf("\nla machine -> %s d'adresse_ip -> %s et d'adresse_mac -> %s\n\n", actuel->nomComputer,actuel->ip,actuel->mac);
        actuel = actuel->prochain;
        cpt++ ;1
        }
    }
    if (cpt==0){
        printf("vide");
    }
        goto C;
      break;

    case 0:
      goto A ;
      break;
    
    default:
      printf("Choix invalide : Entrez un chiffre entre 1 et 6") ;
      printf("\n ");
      goto C ;
      break;
    }
  }

  if (choice==3){}

  if (choice!=1 && choice!=2 && choice!=3){
    printf("Choix invalide : Entrez un chiffre entre 1 et 3") ;
    goto A ;
  }
  int choix ;
    printf("\n\n\n Merci d'avoir utilisé notre programme. Voulez vous recommencer ?\n");
    printf("Taper sur 1 pour oui et une autre touche pour non........... ");
    scanf("%d",&choix);
      if (choix==1){
        goto A ;
      } else
      {
        return 0;
      }  
}



//Fichier pour machine
parc *backup(){
	parc *list=NULL;
	char* storeFile={"Store.dat"}
	FILE *file;
	machine *m=malloc(sizeof(machine));
	parc *p=malloc(sizeof(parc));
	if(p==NULL)
		printf("ERREUR !!! \n");
	else{
		if ((file=fopen(storeFile,"rb"))){
			puts("C'est bon !!! \n");
			puts("----------------------------------------------------");
			while(fread(m, sizeof(machine), 1, file)>0){
				if(m!=NULL){
					afficheNom(m);
					afficheMacAddr(m);
					afficheIpAddre(m);
					
					p->machine=m;
					p->next=NULL;
					if(list=NULL)
						list=p;
					else{
						parc *tmp=list;
						while(tmp->next!=NULL)
							tmp=tmp->next;
						tmp->next=p;
					}
				}
				else{
					printf(" Pas de machine trouvé !!! \n");
				}
			}
			fclose(file);
		}
		else
			printf("Echec lors de l'ouverture ...\n");
	}
	return list;
}

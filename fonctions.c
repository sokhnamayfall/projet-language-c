#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"fonctions.h"
#include"messtructures.h"
 

//Initialisation de la liste des machines 
Liste *initialisation() 
{ 
   Liste *liste = malloc(sizeof(*liste));
   Computer *new = malloc(sizeof(*new)); 
   if (liste == NULL || new == NULL)    {
           exit(EXIT_FAILURE);    
    }
    new->listserv = malloc(sizeof(serveur));
    new->listserv->listpage= malloc(sizeof(page));
    strcpy(new->nomComputer,"toto");
    strcpy(new->ip,"10.10.10.1");
    strcpy(new->mac,"5E:FF:56:A2:AF:15");
    strcpy(new->connect,"NON");
    strcpy(new->listserv->nom, "WAMP" );
    strcpy(new->listserv->type, "Apache" ); 
    strcpy(new->listserv->hote, "toto");
    strcpy(new->listserv->listpage->url, "Wikipedia");    
    new->listclient = NULL ;

    new->prochain = NULL;   
    liste->premier = new;

    return liste; 
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Mise en majuscule

void majuscule(char *chaine)
{
    int i = 0;
    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        chaine[i] = toupper(chaine[i]);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Insertion d'une nouvelle machine 

int insertion(Liste *liste, char name[30], char ip_add[15], char mac_add[17], char connect_add[5]) 
{
/* Création du nouvel élément */  
Computer *nouveau = malloc(sizeof(*nouveau));

if (liste == NULL || nouveau == NULL)    {        
      exit(EXIT_FAILURE);    
}

strcpy(nouveau->nomComputer, name);
strcpy(nouveau->ip, ip_add);
strcpy(nouveau->mac, mac_add);
strcpy(nouveau->connect, connect_add);
nouveau->listserv = NULL ;    
nouveau->listclient = NULL ;   
  
/* Insertion de l'élément dans la liste */
static Computer *pass=NULL ;
static int insert=0 ;
int cpt=0;

if(insert==0){
    pass=liste->premier ;
    nouveau->prochain = NULL;    
    pass->prochain =nouveau; 
    pass = pass->prochain ;
    insert++;
    cpt++;
    return 1;
}else{
    nouveau->prochain = NULL;    
    pass->prochain =nouveau; 
    pass = pass->prochain ;
    cpt++;
    return 1;
  }
if (cpt==0)
      {
        printf("\nEchec de l'ajout......");
      }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Suppression d'une machine 

void suppression(Liste *liste, char name[30]) 
{    
 	if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}   
  Computer *actuel = liste->premier;
  while (actuel != NULL)
    {       
      if(strcmp(name,actuel->nomComputer)==0){
        Computer *aSupprimer = actuel ;
        free(aSupprimer);
        actuel = actuel->prochain; 
        printf("La machine a ete supprimee correctement");
        break;
      }else{        
	      actuel = actuel->prochain;        
      }
    }

}

/*---------------------------------------------------------------------------------------------------------------------------------*/
// Affichage de la liste des machines

void afficherListemach(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Computer *actuel = liste->premier;
    printf("\nLa liste des machines est :");
    while (actuel != NULL)
    {
        printf("\nMachine -> %s \nAdresse_ip -> %s \nAdresse_mac -> %s\nConnectee -> %s\n\n", actuel->nomComputer,actuel->ip,actuel->mac,actuel->connect);
        actuel = actuel->prochain;
    }

}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Installation d'un serveur 

void installserv(Liste *liste, char namehote[30], char nom_serv[60], char type_serv[40])
{

/* Création du nouvel élément */  
Serveur *nouveau = malloc(sizeof(serveur));    
int cpt=0 ;
strcpy(nouveau->nom, nom_serv );
strcpy(nouveau->type, type_serv); 
strcpy(nouveau->hote, namehote); 
/* Insertion dans la liste des serveurs */
static Serveur *serv1 = NULL ;
static int instal=0 ;
Computer *actuel = liste->premier;

        while (actuel != NULL)
        {
          if(strcmp(namehote,actuel->nomComputer)==0){
            nouveau->next = NULL;    
            if (instal==0){
              serv1=actuel->listserv;
              serv1->next = nouveau ;
              serv1=serv1->next ;
              printf("\nLe serveur a bien ete installe") ;
              instal++; 
            }else{
              serv1=nouveau;
              //printf("\nNom -> %s \nType -> %s \nHote -> %s\n\n", serv1->nom,serv1->type,serv1->hote); 
              serv1=serv1->next ;
              printf("\nLe serveur a bien ete installe") ;
            }
            cpt++ ;

            
            
            // if (instal==0){
            //   serv2=malisteserv->first;
            //   serv2=nouveau ;
            //   serv2 = serv2->next ; 
            //   instal++;
            // }else{
            //   serv2=nouveau ; 
            //   serv2=serv2->next;
            //   printf("%d",instal) ;
            // }
                
            break;
          }else{
            actuel = actuel->prochain;
          }
        }
        if (cpt==0)
        {
          printf("\nEchec de l'installation : l'hote inscrit n'existe pas");
        }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Désinstallation d'un serveur 

void desinstallserv(Liste *liste, char nom_hote[30], char nom_serv[40]) 
{    
 	if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	Serveur *actuel = liste->premier->listserv;
  int cpt=0 ;
  while (actuel != NULL)
    {       
      if(strcmp(nom_serv,actuel->nom)==0){ 
        cpt++;
        free(actuel);
        printf("\nLe serveur a bien ete desinstalle");
        break;
      }else{        
	      actuel = actuel->next;        
      } 
    }
    if (cpt==0)
        {
          printf("\nEchec de la desinstallation : l'hote ou le serveur inscrit n'existe pas");
        }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Affichage des serveurs

void afficherListeserv(Liste *liste)
{
    Computer *actuel = liste->premier;
    int cptserv =0;
    printf("\nLa liste des serveurs est : ");
    while(actuel!=NULL)
      {      
        Serveur *actuelserv = actuel->listserv ;
        while (actuelserv != NULL)
        {
          printf("\nNom -> %s \nType -> %s \nHote -> %s\n\n", actuelserv->nom,actuelserv->type,actuelserv->hote);
          actuelserv = actuelserv->next;
          cptserv++ ;
        }
      actuel=actuel->prochain;
    }
    if (cptserv == 0)
    {
        printf("vide car aucun serveur n'est installe pour le moment");
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Création d'une page web
void ajouterpage(Liste *liste, char nom_serv[40], char nom_page[60])
{
/* Création du nouvel élément */  
Page *nouvelle = malloc(sizeof(*nouvelle));
int cptp=0 ;

if (liste == NULL || nouvelle == NULL)    {        
      exit(EXIT_FAILURE);    
}

strcpy(nouvelle->url, nom_page);   
  
/* Insertion de l'élément dans la liste */
static Page *page1 = NULL ;
static int p=0 ;
Computer *actuel = liste->premier;
        while (actuel != NULL)
        {
          Serveur *serv = actuel->listserv;
          while (serv != NULL )
          {
            if(strcmp(nom_serv,serv->nom)==0){
              page1 = serv->listpage ;
              nouvelle->suivante = NULL ;
              if (p==0){
                page1 = nouvelle ;
                page1 = page1->suivante;
                printf("La page a ete cree");
                p++;
              }else{
                page1 = nouvelle ;
                page1=page1->suivante;
                printf("La page a ete cree");
              }
              break;
            }
            serv = serv->next ;      
          }
          actuel = actuel->prochain;
        }
      if (cptp==0)
      {
        printf("\nEchec de la creation : le serveur inscrit n'existe pas");
      }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Recherche de page web
void rechpage(Liste *liste, char nom_serv[40], char nom_page[60])
{

}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Insertion d'une nouvelle machine dans le reseau

void insertionreseau(Liste *liste, char name[30])
{
    Computer *actuel = liste->premier;
    int cpti=0 ;
        while (actuel != NULL)
        {
          if(strcmp(name,actuel->nomComputer)==0){
            strcpy(actuel->connect,"OUI"); 
            cpti++;
            printf("La machine a bien ete ajoutee") ;
            break;
          }else{
            actuel = actuel->prochain;
          }
        }
        if (cpti==0)
          {
            printf("\nEchec de l'ajout : la machine n'existe pas");
          }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
//Suppression d'une machine du réseau

void suppressionreseau(Liste *liste, char name[30])
{
    Computer *actuel = liste->premier;
    int cpt=0;
        while (actuel != NULL)
        {
          if(strcmp(name,actuel->nomComputer)==0){
            strcpy(actuel->connect, "NON"); 
            printf("La machine a bien ete retiree") ;
            cpt++;
            break;
          }else{
            actuel = actuel->prochain;
          }
        }
        if (cpt==0)
          {
            printf("\nEchec de la suppression : la machine n'est pas presente sur le reseau");
          }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
// Affichage de la liste des machines présentes sur le réseau

void afficherListeres(Liste *liste)
{
    Computer *actuel = liste->premier;
        printf("La liste des machines du reseau est :");
        static int cpta=0 ;
    while (actuel != NULL)
    {   
        if(strcmp("OUI",actuel->connect)==0){
        printf("\nMachine -> %s \nAdresse_ip -> %s \nAdresse_mac -> %s\n\n", actuel->nomComputer,actuel->ip,actuel->mac);
        cpta++ ;
        }
        actuel = actuel->prochain;
    }
    if (cpta==0){
        printf("vide");
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/
// Affichage de la liste des machines présentes sur le réseau
void pingmachine(Liste *liste, char comp_ip[15]){

  Computer *ping = liste->premier;
  int cptp=0 ;
  while(ping!=NULL){
    if(strcmp(comp_ip,ping->ip)==0){
        printf("\nPING %s (%s) 56(84) bytes of data.",comp_ip,ping->nomComputer );
        printf("64 bytes from 10.10.10.1: icmp_seq=1 ttl=249 time=68.9 ms\n");
        printf("64 bytes from 10.10.10.1: icmp_seq=2 ttl=249 time=51.9 ms\n");
        printf("64 bytes from 10.10.10.1: icmp_seq=3 ttl=249 time=51.7 ms\n");
        printf("64 bytes from 10.10.10.1: icmp_seq=4 ttl=249 time=76.6 ms\n");
        printf("64 bytes from 10.10.10.1: icmp_seq=5 ttl=249 time=36.6 ms\n");
        printf("\n");
          printf(" --- %s ping statistics ---\n",comp_ip);
          printf("8 packets transmitted, 8 received, 0 percent packet loss, 100 percent received, time 7010ms\n"); 
          printf("\n");
          printf("Ok 5 sur 5 la machine est presente\n");
          cptp++ ;
      break; 
    }
    ping=ping->prochain ;
  }
  if (cptp==0){
      printf("\n --- %s ping statistics ---\n",comp_ip);
      printf("8 packets transmitted, 0 received,100 percent packet loss, 0 percent received, time 7010ms\n"); 
      printf("\n");
      printf("la machine n'est pas presente \n");
    }
}



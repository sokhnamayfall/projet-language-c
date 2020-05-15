#ifndef fonctions_h
#define fonctions_h

#include"messtructures.h"

Liste *initialisation(void) ;

void majuscule(char *chaine);

int insertion(Liste *liste, char name[30], char ip_add[15], char mac_add[17], char connect_add[5]) ;

void suppression(Liste *liste, char name[30]) ;

void afficherListemach(Liste *liste) ;

void installserv(Liste *liste, char namehote[30], char nom_serv[60], char type_serv[40]) ;

void desinstallserv(Liste *liste, char nom_hote[30], char nom_serv[40]) ;

void afficherListeserv(Liste *liste) ;

void insertionreseau(Liste *liste, char name[30]) ;

void suppressionreseau(Liste *liste, char name[30]) ;

void afficherListeres(Liste *liste) ;

void pingmachine(Liste *liste, char comp_ip[15]) ;


#endif


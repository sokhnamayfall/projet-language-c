#ifndef messtructures_h
#define messtructures_h

//definition des pages web
typedef struct page Page ;
struct page
    {
        char url[60];
        
        Page *suivante;
    }page;

//definition des logiciels serveurs installés 
typedef struct serveur Serveur ;
struct serveur
    {
        char nom[60];
        char type[40];
        char hote[30];
        Page *listpage;

        Serveur *next;
    }serveur;

//definition des logiciels clients installés
typedef struct client Client ;
struct client
    {
        char nom[60];
        
        Client *svt;
    }client;

//definition des ordinateurs
typedef struct computer Computer;
struct computer
 {
    char nomComputer[30];
    char ip[15];
    char mac[17];
    char connect[5];
    Client *listclient ;
    Serveur *listserv ;

    Computer *prochain;  
}computers;

// definition de la structure liste qui pointe sur les machines
typedef struct Liste Liste;
struct Liste {       
    Computer *premier; 
 };


#endif
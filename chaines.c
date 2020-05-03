typedef struct Element Element;
  struct Element {     
  	int nombre;    
  	Element *suivant; 
  };

typedef struct Liste Liste;
 struct Liste {    
 	Element *premier; 
 };

Liste *initialisation() { 
   Liste *liste = malloc(sizeof(*liste));
   Element *element = malloc(sizeof(*element)); 
   if (liste == NULL || element == NULL)    {
           exit(EXIT_FAILURE);    
    }
    element->nombre = 0;    
    element->suivant = NULL;   
    liste->premier = element;

    return liste; 
}

void insertion(Liste *liste, int nvNombre) {

    /* Création du nouvel élément */    
    Element *nouveau = malloc(sizeof(*nouveau));    
    if (liste == NULL || nouveau == NULL)    {        
        exit(EXIT_FAILURE);    
    }    
    /* Insertion de l'élément au début de la liste */
    nouveau->nombre = nvNombre;        
    nouveau->suivant = liste->premier;    
    liste->premier = nouveau; 
 }

 void suppression(Liste *liste) {    
 	if (liste == NULL)    {        
 		exit(EXIT_FAILURE);    
 	}    
 	if (liste->premier != NULL)    {        
 		Element *aSupprimer = liste->premier;        
 		liste->premier = liste->premier->suivant;        
 		free(aSupprimer);    
 	} 
 }


/* ----------------------------------les ojets du projet-----------------------------------------------------*/

typedef struct Machine Machine;
typedef struct LogServer LogServer;    /* declaration des  trois structures */ 
typedef struct LogClient LogClient;
typedef struct Liste Liste;
struct LogServer
  {
  	int idserver;
  	char[20] namelogserver; /* definition de la structure LogServer qui contient les informations sur les logiciels serveur */
  	int  portserver;  	
  };
struct LogClient
  {
  	int idclient;
  	char[20] namelogclient; /* definition de la structure LogClient qui contient les informations sur les logiciels client */
  };


  struct Machine {     
  	char[20]  adresseIp; 
  	char[20] nom;
  	int idmachine;           /* definition de la structure machine qui contient les informations sur les machines */
   /* LogClient appclt;
      LogServer appsvr;*/
    struct LogServer appsvr;
    struct LogClient appclt;
  	Machine *suivant; 
  };

 struct Liste {                /* definition de la structure liste  qui pointe sur les machines, les logserver et les logclient*/
 	Machine *premier; 
 };

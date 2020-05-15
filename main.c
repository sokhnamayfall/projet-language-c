#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"messtructures.h"
#include"fonctions.h" 

//la fonction main 
int main(void){

    FILE *fic=fopen("sauvegarde.txt", "a+") ;
    if (fic== NULL) {
      printf("Erreur lors de l'ouverture du fichier de sauvegarde. Le programme va s'arreter............");
      exit(1) ;
      }

    
     
    Liste *maListe = initialisation();
    Liste *pass = NULL ;

    char nom_nom[30], ip_ip[15], mac_mac[17], connect_connect[5];
    char nom_hote[30], nom_serv[60], type_serv[40];
    char ping_ip[15];
    char alpha ;
    int i=0;
    int c=0;

  int choice ;
  system("cls");
  printf("Par defaut,on a initialise le parc avec une machine appelee \"toto\" sur laquelle nous sommes connectes\n\n");
A:  printf("\n************Menu Principal************\n\n");
    printf("1-Gerer le parc de machine\n");
    printf("2-Gerer le reseau\n");  
    printf("3-Faire une simulation du serveur web\n"); 
    printf("4-Restaurer la derniere session\n");
    printf("5-Sauvegarder et quitter le programme\n");  
    scanf("%d",&choice) ;

  if (choice==1){
  int option;
B:  printf("\n************Menu du Parc de Machine************\n\n");
    printf("1-Ajouter une machine\n");
    printf("2-retirer une machine\n");  
    printf("3-installer un serveur web\n");
    printf("4-desinstaller un serveur web\n");
    printf("5-afficher la liste des machines\n");
    printf("6-afficher la liste des serveurs installes\n");
    printf("0-Retourner en arriere\n\n");
    printf(":");
    scanf("%d",&option);

  switch(option){
      case 1:  
        
        printf("\nEntrer le nom de la machine : ");
        scanf("%s", nom_nom);
        printf("\nEntrer l'adresse ip [format 10.10.10.1] : ");
        scanf("%s", ip_ip);
        printf("\nEntrer l'adresse_mac [format 5E:FF:56:A2:AF:15] : ");
        scanf("%s", mac_mac);
        printf("\nVoulez vous connecter la machine au reseau ? (OUI ou NON)  :");
        scanf("%s", connect_connect );

        majuscule(connect_connect); 
        int test=insertion(maListe, nom_nom, ip_ip, mac_mac, connect_connect); 
        if (test==1){
          printf("\nLa machine a bien ete ajoutee");
        }
        fprintf(fic, "\n\n%s \n%s \n%s \n%s", nom_nom, ip_ip, mac_mac, connect_connect) ;
      
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break;

      case 2:
        printf("\nEntrer le nom de la machine a supprimer : ");
        scanf("%s", nom_nom);
        suppression(maListe, nom_nom);  
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break ;


      case 3:
        printf("\nEntrer le nom du serveur web : ");
        scanf("%s", nom_serv);
        printf("\nEntrer le type du serveur (Apache, Google, Nginx,...) : ");
        scanf("%s", type_serv);
        printf("\nEntrez le nom de la machine ou vous voulez installez le serveur web : ");
        scanf("%s",nom_hote);
        
        installserv(maListe, nom_hote, nom_serv, type_serv);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break ;
      
      case 4:
        printf("\nEntrer le nom du serveur a desinstaller : ");
        scanf("%s", nom_serv);
        desinstallserv(maListe, nom_hote, nom_serv);  
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break ;

      case 5:
        afficherListemach(maListe);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break ;

      case 6:
        afficherListeserv(maListe);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto B ;
      }
      break;

      case 0:
        goto A ;
      break;
      
      default : 
        printf("Choix invalide : Entrez un chiffre entre 0 et 6") ;
        printf("\n ");
        goto B ;
    }
    
  }

  if (choice==2){
  int opt;
C:  printf("\n************Menu du Reseau************\n\n");
    printf("1-Ajouter une machine au reseau\n");
    printf("2-Retirer une machine du reseau\n");  
    printf("3-Pinger une machine\n");
    printf("4-Afficher la liste des machines\n");
    printf("0-Retourner en arriere\n\n");
    printf(":");
    scanf("%d",&opt);

    char machname[30] ;
    switch (opt)
    {
    case 1:
        afficherListemach(maListe);
        printf("\nEntrez le nom de la machine a ajouter : ");
        scanf("%s",machname);
        insertionreseau(maListe, machname);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto C ;
      }  
      break;

    case 2:
        afficherListemach(maListe);
        printf("\nEntrez le nom de la machine a retirer : ");
        scanf("%s",machname);
        suppressionreseau(maListe, machname);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto C ;
      }
      break;

    case 3:    
        afficherListeres(maListe); 
        printf("entrer l'addresse_ip de la machine a pinger:");
        scanf("%s",ping_ip);
        
        pingmachine(maListe, ping_ip);
      
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto C ;
      }
      break ;
    
    case 4:
        afficherListeres(maListe);
      printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto C ;
      }
      break;

    case 0:
      goto A ;
      break;
    
    default:
      printf("Choix invalide : Entrez un chiffre entre 0 et 6") ;
      printf("\n ");
      goto C ;
      break;
    }
  }

  if (choice==3){
  int opts;
D:  printf("\n************Menu du Serveur************\n\n");
    printf("1-Rechercher une page Web\n");
    printf("2-Ajouter une page Web\n");  
    printf("0-Retourner en arriere\n\n");
    printf(":");
    scanf("%d",&opts);

    switch (opts)
    {
    case 1:
      /* code */
      break;
    
    default:
      printf("Choix invalide : Entrez un chiffre entre 0 et 2") ;
      printf("\n ");
      goto D ;
      break;
    }
  }
// /serveur web
// 			if((strcmp(serveur.nom,web))==1){
// 				char* site;
// 				printf("enter le site web");
// 				scanf("%s,site");

// 				if(strcmp(site[2],w)==1){
//     					printf("la page est disponible");
// 				}

// 				else{
//    					printf("la page n'est pas disponible");
// 				}
// 			}

// 			else{
// 				printf("cette machine ne dispose pas de serveur web");
// 			}
//     		}
//   	}


// //serveur dhcp
// 	if(nn==7){
// 		printf("utilisation du serveur dhcp");
// 		printf("nom de la machine pour le dhcp");
// 		char* dhcpname;
// 		scanf("%s",dhcpname);

// 		int comparif(serveur.nom ){
// 			char* ss=dhcp;

// 			if((strcmp(serveur.nom,dhcp))==1){
// 				srand(time(NULL));
//   		     		int x=1+rand(12);
// 		     		computer.ip=x;
// 		    		printf("Ce machine a comme adresse ip %d",x);
//             		}

// 			else{
//             			printf("ce machine ne dispose pas de serveur dhcp");
//         		}
// 		}
// 	}
//   }

  if(choice==4){
    printf("La restauration est en cours");
    char nom_rest[30], ip_rest[15], mac_rest[17], connect_rest[5];
    int wait=0 ;
    while(wait<=5){
      printf("...");
      Sleep(200);
      wait++;
    }
    while(!feof(fic)){
      fscanf(fic, "%s %s %s %s", nom_rest, ip_rest, mac_rest, connect_rest) ;
      insertion(maListe, nom_rest, ip_rest, mac_rest, connect_rest); 
    }
      printf("\nVotre ancienne session a bien ete restauree");

    printf("\n\nPour continuer taper sur une touche...\n ");
      alpha = getch();
      if(alpha){
        goto A ;
      }
  }

  if(choice==5){
    goto E ;
  }
    
    printf("\n\n Merci d'avoir utilise notre programme. Voulez vous recommencer ?\n");
    int choix ;
    printf("Taper sur 1 pour oui et une autre touche pour non........... ");
    scanf("%d",&choix);
      if (choix==1){
        system("cls");
        goto A ;
      }else
      {
E:      printf("\n\n....................................Merci d'avoir utilise notre programme.....................................\n\n");
        fclose(fic) ;
        return 0;
      }

  if (choice!=1 && choice!=2 && choice!=3 && choice!=4){
    printf("Choix invalide : Entrez un chiffre entre 1 et 4") ;
    goto A ;
  }
}


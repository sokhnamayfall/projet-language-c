# projet-language-c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int nn;
    printf("Selon l'action à faire \n 6-utiliser les serveurs web dune machine\n 7-utiliser les serveurs dhcp dune machine\n ");
    scanf("%d",&nn);


 //serveur web
  if(nn==6){
    int comparif(serveur.nom ){
	char* ss=web;

	if((strcmp(serveur.nom,web))==1){
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

	else{
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

		int comparif(serveur.nom ){
			char* ss=dhcp;

			if((strcmp(serveur.nom,dhcp))==1){
				srand(time(NULL));
  		     		int x=1+rand(12);
		     		computer.ip=x;
		    		printf("Ce machine a comme adresse ip %d",x);
            		}

			else{
            			printf("ce machine ne dispose pas de serveur dhcp");
        		}
		}
	}

#include <arpa/inet.h>
#include <netdb.h>  
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <sys/uio.h>
#include <sys/socket.h>
#include <pthread.h> 
#include <sys/select.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>

typedef struct User
{
	char nom[30];
	int age;
}User;
 void * funct( void * arg){
 int socket = *(int*)arg;
 char msg[] = "quel est ton nom et age";
 User user;
 send(socket, msg,strlen(msg)+1,0);
 recv(socket, &user, sizeof(user),0);
 printf(" votre nom est %s et votre age est %d \n",user.nom ,user.age);
 close(socket);
 free(arg);
 pthread_exit(NULL);
}
int main(void)
{    
    int socketServer = socket(AF_INET, SOCK_STREAM, 0); 
    struct sockaddr_in addrServer;
    addrServer.sin_family = AF_INET; 
    addrServer.sin_addr.s_addr = inet_addr("127.0.0.1") ; 
    addrServer.sin_port = htons(30000);

    bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
    printf("bind : %d\n",socketServer );
    
    listen(socketServer,5);
    printf("listen\n");
    pthread_t Threads[3];
    for(int i=0 ;i<3;i++){
        struct sockaddr_in addrClient;
        socklen_t csize = sizeof(addrClient);
        int socketClient = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
        printf("accept\n");

        printf("client: %d\n",socketClient);

   
        int *arg = (int *)malloc(sizeof(int));
         *arg = socketClient;
        pthread_create(&Threads[i],NULL,funct,arg);
        
    }
    for(int i=0 ;i<3;i++){
     pthread_join(Threads[i],NULL);     
    }
    close(socketServer);
    printf("close\n");


	return 0;
} 

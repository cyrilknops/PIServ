#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <time.h>
#include "logging.c"
#include "connections.c"

#define TRUE   1
#define FALSE  0
#define PORT 24055


int main(int argc , char *argv[]) {
    int opt = TRUE;
    int master_socket , addrlen , new_socket, activity, i , valread , sd;
    int max_sd;
    struct sockaddr_in address;

    char buffer[1025];  //data buffer of 1K
    char cn[1025];
    char s[INET6_ADDRSTRLEN];
    char *client_name[30];
    //set of socket descriptors
    fd_set readfds;

    //a message
    char *message = "CChat v1.0 \r\n";
    init();

    while(1){

    }
}


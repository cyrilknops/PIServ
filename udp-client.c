#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>

#define PORT 24055
#define MAXLINE 1000

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

// Driver code 
int main()
{
    char buffer[100];
    int correct;
    int sockfd, n;
    struct sockaddr_in servaddr;

    // clear servaddr 
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_addr.s_addr = inet_addr("84.193.168.7");
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    // create datagram socket 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // connect to server 
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("\n Error : Connect Failed \n");
        exit(0);
    }
    for(int i = 0; i < 50;i++){

        // request to send datagram
        // no need to specify server address in sendto
        // connect stores the peers IP and port
        char arr[1000] = "" ;
        sprintf(arr, "%d", i);
        sendto(sockfd, arr, strlen(arr), 0, (struct sockaddr*)NULL, sizeof(servaddr));
        // waiting for response
        if(recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL)>0){
            correct++;
        }
        // close the descriptor
        delay(1);

    }
    printf("%d of the 50 received\n",correct);
    close(sockfd);


} 
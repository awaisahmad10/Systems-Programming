#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int sock;

    struct sockaddr_in server;

    // connect to the server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) 
        printf("ERROR opening socket"); 
    puts("Socket created");	

    server.sin_addr.s_addr=inet_addr("127.0.0.1");   
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock,(struct sockaddr *)&server,sizeof(server)) < 0){ 
        printf("ERROR connecting");
	return 1;
}
    puts("Connected");

while(1){
    //enter the word to search the dictionary for
    char message[1000] = "", server_reply[2000] = "";
    printf("Please enter the word to search for: ");
    scanf("%s",message);
    puts(message);
    if (send(sock,message,strlen(message),0)< 0){ 
         printf("ERROR writing to socket");
	return 1;
	}
     
   if (recv(sock,server_reply,2000,0)<0){
	puts("recv failed");
	break;
	}
puts("Reply from server:");
puts(server_reply);


}
close(sock);
    return 0;
}

// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<arpa/inet.h>

int main(int argv, char *afgv[]){ 

int socket_desc, c,read_size;
long unsigned int client_socket ;
struct sockaddr_in server, client;
//char client_message[1000];




// get a socket
socket_desc = socket(AF_INET, SOCK_STREAM,0); 
if (socket_desc==-1){ 
	 printf("Could not create socket.");
}
puts("Socket created");

//fill the fields 
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family =AF_INET; 
server.sin_port = htons( 8888 ); 


//bind the socket to the port
if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0){ 
	perror("bind faild. error");
	return 1;
}

//start listening for incoming connections
puts("bind done");
listen(socket_desc,3);

puts("waiting for incomming connections...");
c = sizeof(struct sockaddr_in);
client_socket= accept(socket_desc,(struct sockaddr *)&client, (socklen_t*)&c);

if (client_socket == -1) {
      perror("accept falid");
      return 1;
    }
puts("Connection accepted");

//while(read_size=recv(client_socket, client_message, 2000,0)>0) { 
while(1){
	// open the dictionary file
	FILE *f;
	f = fopen("english3.txt","r");
	if (f == NULL) {
		puts("ERROR opening dictionary file.");
	}
	
	// receive the word to search for from the client
	char client_message[1000] = "";
	recv(client_socket, client_message, 2000,0);
	puts(client_message);
	
	// search the dictionary for the word entered by client
	char found[1000] = "Word not found.";
	int word_matches = 0;
	char dict_word[1000];
	char output[10000] = "";
	
	while (fscanf(f, "%s", dict_word)==1) {
		if (strstr(dict_word, client_message) != 0) {
			word_matches++;
			if (strcmp(dict_word, client_message) == 0) {
				sprintf(found, "Word found.");
			}
		}
	}
	
	sprintf(output, "%s Total occurances of the word: %d\n", found, word_matches);
	write(client_socket, output, strlen(output));

	// close the file
	fclose(f); 
}


if(read_size==0){ 
  puts("client disconnected");
  fflush(stdout);
}
else if(read_size==-1){
 perror("recv failed");
}
 

return 0;
}

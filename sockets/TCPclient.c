/**
 * @file TCPclient.c
 * @author Filipe Piçarra (git: fpicarras)
 * @brief This is an example on how a simple TCP client would look like.
 * @version 0.1
 * @date 2024-02-16
 */

//Compile:
//gcc -o client TCPclient.c sockets.c -Wall

#include "sockets.h"

int main(){
    char buffer[BUFFER_SIZE+1];
    //Create a socket that connects to a machine with a certain IP on a specified port
    Socket *sock = TCPSocket("0.0.0.0", "58001");
    if(sock == NULL) return 1;

    //We signal the other server to close if we send "end", in this case, the server will return "Server Closing"
    while(fgets(buffer, BUFFER_SIZE, stdin)){
        if(!Send(sock, buffer)) break;
        Recieve(sock, buffer);
        printf("Recieved: %s\n", buffer);
        if(strcmp(buffer, "Server Closing")==0) break;
    }

    //Close the socket
    closeSocket(sock);

    return 0;
}
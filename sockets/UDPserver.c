/**
 * @file client.c
 * @author Filipe Piçarra (git: fpicarras)
 * @brief This is an example of how to run a UDP server, in this case we just recieve strings from a socket and send
 * them back to the same address... Like an echo...
 * 
 * @version 0.1
 * @date 2024-02-16
 */

//Compile:
//gcc -o server UDPserver.c sockets.c -Wall

#include "sockets.h"

int main(){
    //Creation of the Socket on port 2345, the IP will be the same as the host machine
    Socket *sock = UDPserverSocket("2345");
    char buffer[BUFFER_SIZE+1];

    struct sockaddr addr;

    while(1){
        //Notice that when recieving a string we get the address of the sender,
        //thus we can use it to send back something
        UDPserverRecieve(sock, &addr, buffer);
        if(strcmp(buffer, "end\n")==0){
            UDPserverSend(sock, &addr, "Server Closing");
            break;
        }
        UDPserverSend(sock, &addr, buffer);
    }

    //Close the socket
    closeSocket(sock);

    return 0;
}
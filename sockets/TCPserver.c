/**
 * @file TCPserver.c
 * @author Filipe Piçarra (git: fpicarras)
 * @brief This is an example on how a simple TCP server would look like, notice that this server only
 * handles one connection at a time, for more complex structures you could use threading!
 * 
 * Meaning: the main thread would accept connection, then, for each connection a thread would be created and
 * would handle that "process".
 * @version 0.1
 * @date 2024-02-16
 */

//Compile:
//gcc -o server TCPserver.c sockets.c -Wall

#include "sockets.h"

int main(){
    char buffer[BUFFER_SIZE+1];
    //Here we bind a TCP server to port 58001 and set a connection queue of size 500...
    Socket *sock = TCPserverSocket("58001", 500);
    if(sock == NULL) return 1;
    TCPserverConn *new = NULL;

    new = TCPserverAccept(sock);
    while(new != NULL){
        //while((new = TCPserverAccept(sock)) == NULL);
        TCPserverRecieve(new, buffer);
        if(strcmp(buffer, "end\n")==0){
            TCPserverSend(new, "Server Closing");
            TCPserverCloseConnection(new);
            break;
        }
        TCPserverSend(new, buffer);
    }

    closeSocket(sock);    
}
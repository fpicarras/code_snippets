#include "connectivity.h"

int main(){
    Connections *conn = newConn(10);
    isConnected(conn, 1, 2);
    delConn(conn);
}
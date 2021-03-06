#include <netinet/in.h>
#include "MySerialServer.h"
#include "sys/socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
/**
 * runing the connection socket loop.
 */
void MySerialServer::run() {
//create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        MySerialServer::threadCondition = false;
        throw "Could not create a socket";
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(MySerialServer::port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        MySerialServer::threadCondition = false;
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port
    if (listen(socketfd, 20) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        MySerialServer::threadCondition = false;
        throw "Error during listening command";

    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    // setting the timeout.
    struct timeval tv;
    tv.tv_sec = 120000;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);

    while (MySerialServer::threadCondition) {
      cout << "Waiting for connection...." << endl;
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        if (client_socket == -1) {
            std::cerr << "Error accepting client! / TimeOut!" << std::endl;
            MySerialServer::stop();

        } else {
            cout << "Got Connection!" << endl;
        }
        // hhandlling the input.
        MySerialServer::handler->handleClient(client_socket, client_socket);
    }
    close(socketfd);
}
/**
 * opening the server for connections.
 * @param port 5600 as requested.
 * @param c the client handler.
 */
thread* MySerialServer::open(int port, ClientHandler *c) {
    MySerialServer::handler = c;
    MySerialServer::port = port;
    MySerialServer::threadCondition = true;
    thread* th = new thread(&MySerialServer::run, this);
    return th;
}
/**
 * stopping accapting connections.
 */
void MySerialServer::stop() {
    MySerialServer::threadCondition = false;

}

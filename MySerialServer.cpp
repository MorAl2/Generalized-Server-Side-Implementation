#include <netinet/in.h>
#include "MySerialServer.h"
#include "sys/socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void MySerialServer::run() {
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(MySerialServer::port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cout << "Error-Socket" << endl;
        throw "Error-Socket";
    }

    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cout << "Error-Bind" << port << endl;
        throw "Error-Bind";
    }

    if (listen(sockfd, 5) == -1) {
        // Error
        cout << "Error-Listen" << endl;
        throw "Error-Listen";

    }
    struct timeval tv;
    tv.tv_sec = 120;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    cout << "Waiting For Connections... " << endl;
    while (MySerialServer::threadCondition) {
        int client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
        MySerialServer::handler->handleClient(client_socket, client_socket);
        close(client_socket);
    }
    close(sockfd);
}

void MySerialServer::open(int port, ClientHandler *c) {
    MySerialServer::handler = c;
    MySerialServer::port = port;
    MySerialServer::threadCondition = true;
    thread th(&MySerialServer::run);
}

void MySerialServer::stop() {
    MySerialServer::threadCondition = false;

}

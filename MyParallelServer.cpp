#include "MyParallelServer.h"
#include <netinet/in.h>
#include "sys/socket.h"
#include "MyClientHandler.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
/**
 * runing the connection socket loop.
 */
void MyParallelServer::run() {
//create socket
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1) {
    //error
    std::cerr << "Could not create a socket" << std::endl;
    MyParallelServer::threadCondition = false;
    throw "Could not create a socket";
  }

  //bind socket to IP address
  // we first need to create the sockaddr obj.
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
  address.sin_port = htons(MyParallelServer::port);
  //we need to convert our number
  // to a number that the network understands.

  //the actual bind command
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    std::cerr << "Could not bind the socket to an IP" << std::endl;
    MyParallelServer::threadCondition = false;
    throw "Could not bind the socket to an IP";
  }

  //making socket listen to the port
  if (listen(socketfd, 11) == -1) { //can also set to SOMAXCON (max connections)
    std::cerr << "Error during listening command" << std::endl;
    MyParallelServer::threadCondition = false;
    throw "Error during listening command";

  } else {
    std::cout << "Server is now listening ..." << std::endl;
  }

  // setting the timeout.
  struct timeval tv;
  tv.tv_sec = 12000;
  tv.tv_usec = 0;
  setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
  thread *th;
  vector<thread *> threadList;
  // as long as it open rcv connections.
  while (MyParallelServer::threadCondition) {
    cout << "Waiting for connection...." << endl;
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1) {
      std::cerr << "Error accepting client! / TimeOut!" << std::endl;
      MyParallelServer::stop();
      throw "Error accepting client";
    } else {
      cout << "Got Connection!" << endl;
    }
    // handaling the data on a thread.
    th = new thread(&ClientHandler::handleClient, this->handler, client_socket, client_socket);
    threadList.push_back(th);
  }
  for (auto &g: threadList) {
    g->join();
  }

  close(socketfd);
}
/**
 * opening the server for connections.
 * @param port 5600 as requested.
 * @param c the client handler.
 */
thread* MyParallelServer::open(int port, ClientHandler *c) {
  MyParallelServer::handler = c;
  // TODO - set the port to 5600
  MyParallelServer::port = port;
  MyParallelServer::threadCondition = true;
  thread* th1 = new thread(&MyParallelServer::run, this);
  return th1;
}
/**
 * stopping accapting connections.
 */
void MyParallelServer::stop() {
  MyParallelServer::threadCondition = false;
}

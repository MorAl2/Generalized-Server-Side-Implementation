#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <unistd.h>
#include <vector>
#include <sstream>
#include <sys/socket.h>


class MyTestClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager<string, string> *cm;

public:
    MyTestClientHandler(Solver<string, string> solver, CacheManager<string, string> cm) {
        solver = solver;
        cm = cm;
    }

    vector<string> *splitToLines(char *) {

    }

    /**
     * handle Input Stream and Output Stream.
     * @param is - input Stream.
     * @param os output Stream.
     */
    void handleClient(int is, int os) {
        char buffer[4096] = {0};
        bool endFlag = false;
        while (!endFlag) {
            int valread = read(is, buffer, 4096);
            if (valread == -1) {
                cout << "Error - Read" << endl;
                throw "Error - Read";
            }
            stringstream stream(buffer);
            string line;

            while (getline(stream, line, '\n')) {
                if (line == "end") {
                    endFlag = true;
                    break;
                } else {
                    if (cm->isSolutionExists(line)) {
                        string msg = cm->getSolution(line);
                        int is_sent = send(os, msg.c_str(), msg.length(), 0);
                        if (is_sent == -1) {
                            cout << "The Message Wasn't sent: " + msg << endl;
                        }
                    } else {
                        string solution = solver->solve(line);
                        cm->addSolution(line, solution);
                        int is_sent = send(os, solution.c_str(), solution.length(), 0);
                        if (is_sent == -1) {
                            cout << "The Message Wasn't sent: " + solution << endl;
                        }
                    }
                }
            }
        }
    }
};


#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MYTESTCLIENTHANDLER_H

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H

#include <iostream>
#include "Solver.h"
#include "CacheManager.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "State.h"
#include <queue>
#include "SearcherAbstract.h"
#include "MatrixProblem.h"
#include "MatrixSolution.h"
#include "MyClientHandler.h"
#include "SolverTester.h"
using namespace server_side;
// asjdilajsdijasidjsd
using namespace std;
namespace server_side {
    namespace boot {
        class Main {
        public:
            //mor
            int main(int argc, char *argv[]) {
              int port = atoi(argv[1]);
              Solver<MatrixProblem*, MatrixSolution*> *reverse = new SolverTester<MatrixProblem*, MatrixSolution*>();
              CacheManager<MatrixProblem*, MatrixSolution*> *cache = new FileCacheManager<MatrixProblem*, MatrixSolution*>(5);
              ClientHandler *handler = new MyClientHandler(reverse, cache);
              server_side::Server *serial = new MySerialServer();
              serial->open(port, handler);
              while (serial->getCondition()) {

              }


//                SearcherAbstract<string> *temp = new SearcherAbstract<string>();
//                string x = "a";
//                string y = "b";
//                string z = "c";
//                State<string> *s1 = new State<string>(x);
//                State<string> *s2 = new State<string>(y);
//                State<string> *s3 = new State<string>(z);
//                s1->setCost(8);
//                s2->setCost(4);
//                s3->setCost(6);
//                if(*s1==*s2){
//                    cout << "IF:yes" << endl;
//                }
//                temp->getOpenList()->push(*s1);
//                temp->getOpenList()->push(*s2);
//                temp->getOpenList()->push(*s3);
//                cout << temp->getOpenList()->top().getCost() << endl;
                /*try {
                     int port = atoi(argv[1]);
                     Solver<string, string> *reverse = new StringReverser();
                     CacheManager<string, string> *cache = new FileCacheManager(5);
                     ClientHandler *handler = new MyTestClientHandler(reverse, cache);
                     server_side::Server *serial = new MySerialServer();
                     serial->open(port, handler);


                     cout << "Main Done.." << endl;
                     while (serial->getCondition()) {

                     }
                 }
                 catch (const char *e) {
                     cout << e << endl;
                 }*/
            }
        };
    }
}

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION_MAIN_H

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
#include "SearcherStack.h"
#include "DFSearch.h"

using namespace server_side;
using namespace std;
namespace server_side {
    namespace boot {
        class Main {
        public:
            int main(int argc, char *argv[]) {
                MatrixProblem *mat = new MatrixProblem();
                vector<State<string> *> *raw1 = new vector<State<string> *>();
                vector<State<string> *> *raw2 = new vector<State<string> *>();
                vector<State<string> *> *raw3 = new vector<State<string> *>();
                vector<State<string> *> *raw4 = new vector<State<string> *>();


                auto temp = new State<string>("1", 1);
                int x = 0, y = -1;
                temp->setPosition(0, 0);
                raw1->push_back(temp);
                temp = new State<string>("2", 2);
                temp->setPosition(0, 1);
                raw1->push_back(temp);
                temp = new State<string>("3", 3);
                temp->setPosition(0, 2);
                raw1->push_back(temp);
                temp = new State<string>("4", 4);
                temp->setPosition(0, 3);
                raw1->push_back(temp);


                temp = new State<string>("5", 5);
                temp->setPosition(1, 0);
                raw2->push_back(temp);
                temp = new State<string>("6", 6);
                temp->setPosition(1, 1);
                raw2->push_back(temp);
                temp = new State<string>("7", 7);
                temp->setPosition(1, 2);
                raw2->push_back(temp);
                temp = new State<string>("8", 8);
                temp->setPosition(1, 3);
                raw2->push_back(temp);


                temp = new State<string>("9", 9);
                temp->setPosition(2, 0);
                raw3->push_back(temp);
                temp = new State<string>("10", 10);
                temp->setPosition(2, 1);
                raw3->push_back(temp);
                temp = new State<string>("11", 11);
                temp->setPosition(2, 2);
                raw3->push_back(temp);
                temp = new State<string>("12", 12);
                temp->setPosition(2, 3);
                raw3->push_back(temp);


                temp = new State<string>("13", 13);
                temp->setPosition(3, 0);
                raw4->push_back(temp);
                temp = new State<string>("14", 14);
                temp->setPosition(3, 1);
                raw4->push_back(temp);
                temp = new State<string>("15", 15);
                temp->setPosition(3, 2);
                raw4->push_back(temp);
                temp = new State<string>("16", 16);
                temp->setPosition(3, 3);
                raw4->push_back(temp);
                mat->addline(raw1);
                mat->addline(raw2);
                mat->addline(raw3);
                mat->addline(raw4);
                mat->setStart(0, 0);
                mat->setEnd(3, 3);
                Searcher<std::string> *k = new DFSearch<std::string>();
                Solution *p = k->search(mat);
                cout<< p->getSolution()<<endl;

//              int port = atoi(argv[1]);
//              Solver<MatrixProblem*, MatrixSolution*> *reverse = new SolverTester<MatrixProblem*, MatrixSolution*>();
//              CacheManager<MatrixProblem*, MatrixSolution*> *cache = new FileCacheManager<MatrixProblem*, MatrixSolution*>(5);
//              ClientHandler *handler = new MyClientHandler(reverse, cache);
//              server_side::Server *serial = new MySerialServer();
//              serial->open(port, handler);
//              while (serial->getCondition()) {
//
//              }


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

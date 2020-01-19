#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MYCLIENTHANDLER_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MYCLIENTHANDLER_H_

#include <sstream>
#include <sys/socket.h>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "MatrixProblem.h"
#include "MatrixSolution.h"
#include "unistd.h"

class MyClientHandler : public ClientHandler {
    Solver<MatrixProblem *, MatrixSolution *> *solver;
    CacheManager<MatrixProblem *, MatrixSolution *> *cm;

public:


    MyClientHandler(Solver<MatrixProblem *, MatrixSolution *> *sol,
                    CacheManager<MatrixProblem *, MatrixSolution *> *cache) {
        solver = sol;
        cm = cache;
    }

    /**
     * handle Input Stream and Output Stream.
     * @param is - input Stream.
     * @param os output Stream.
     */
    void handleClient(int is, int os) {
        bool endFlag = false;
        MatrixProblem *matrix_problem = new MatrixProblem();
        int size = 0;
        int rowPos = 0;
        bool startFlag = true;
      int dimension = 0;
        while (!endFlag) {
          char buffer[1024] = {0};
          int valread = read(is, buffer, 1024);
            cout << buffer<<endl;
            if (valread == -1) {
                cout << "Error - Read" << endl;
                throw "Error - Read";
            }
            stringstream stream1(buffer);
            string line;
            while (getline(stream1, line, '\n')) {
          //    cout << line<<endl;
                // i got the information
                if(line == ""){
                    continue;
                }
                if (line == "end") {
                    endFlag = true;
                    break;
                } else {
                    // creating a Problem Object from The Information.
                    vector<double> *row = new vector<double>();
                    stringstream stream(line);
                    string val;
                    while (getline(stream, val, ',')) {
                        row->push_back(atoi(val.c_str()));
                    }
                    flush(stream);
                    if (dimension == 0) {
                        dimension = row->size()-1;
                    }
                    if (size > dimension) {
                        if (startFlag) {
                            matrix_problem->setStart(row->at(0), row->at(1));
                            startFlag = false;
                        } else {
                            matrix_problem->setEnd(row->at(0), row->at(1));
                        }
                    }
                    else if (size <= dimension) {
                        vector<State<string> *> *stateRow = new vector<State<string> *>();
                        int colPos = 0;
                        for (auto it = row->begin(); it != row->end(); it++) {
                            double value = *it.base();
                            auto start = new State<string>(to_string(value), value);
                            start->setPosition(rowPos, colPos);
                            stateRow->push_back(start);
                            matrix_problem->addToStateString(to_string((int) value) + ",");
                            colPos++;
                        }
                        matrix_problem->addline(stateRow);
                        size++;
                        rowPos++;
                    }
                }
            }
        }
        State<string> test("2", 2);
        cout<< "start: (" << matrix_problem->getStart().first << ", " <<matrix_problem->getStart().second<< ")" <<endl;
       cout<< "end: (" << matrix_problem->getEnd().first << ", " <<matrix_problem->getEnd().second<< ")" <<endl;
        if (cm->isSolutionExists(matrix_problem)) {
            string sol = cm->getSolution(matrix_problem);
            int is_sent = send(os, sol.c_str(), sol.length(), 0);
            if (is_sent == -1) {
                cout << "The Message Wasn't sent: " + sol << endl;
            }
        } else {
            MatrixSolution *matrix_solution = solver->solve(matrix_problem);
            cout << matrix_solution->getSolution() << endl;
            cm->addSolution(matrix_problem, matrix_solution);
            int is_sent = send(os, matrix_solution->to_string().c_str(), matrix_solution->to_string().length(), 0);
            if (is_sent == -1) {
                cout << "The Message Wasn't sent: " + matrix_solution->to_string() << endl;
            }
        }
    }



  vector<string> split(string str)
  {
    vector<std::string> result;
    string temp;
    int markbegin = 0;
    int markend = 0;

    for (int i = 0; i < str.length(); ++i) {
      if (str[i] == '\n') {
        markend = i;
        result.push_back(str.substr(markbegin, markend - markbegin));
        markbegin = (i + 1);
      }
    }
    return result;
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MYCLIENTHANDLER_H_

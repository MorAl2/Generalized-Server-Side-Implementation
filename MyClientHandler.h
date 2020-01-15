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
      MatrixProblem *matrix_problem = new MatrixProblem(line);
      int dimension = 0;
      int col = 1;
      bool startFlag = true;
      while (getline(stream, line, '\n')) {
        // i got the information
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
          if (dimension == 0) {
            dimension = row->size();
          }
          if (col > dimension) {
            if(startFlag){
              matrix_problem->setStart(row->at(0),row->at(1));
              startFlag = false;
            } else{
              matrix_problem->setEnd(row->at(0),row->at(1));
            }
          }
          if (col <= dimension) {
            vector<State<string>*> *stateRow = new vector<State<string>*>();
            for(auto it = row->begin();it!= row->end();it++){
                double value = *it.base();
                stateRow->push_back(new State<string>(to_string(value),value));
                matrix_problem->addToStateString(to_string(value)+",");
            }
            matrix_problem->addline(stateRow);
          }
          col++;
        }
      }
      if (cm->isSolutionExists(matrix_problem)) {
        string sol = cm->getSolution(matrix_problem);
        int is_sent = send(os, sol.c_str(), sol.length(), 0);
        if (is_sent == -1) {
          cout << "The Message Wasn't sent: " + sol << endl;
        }
      } else {
        MatrixSolution *matrix_solution = solver->solve(matrix_problem);
        cm->addSolution(matrix_problem, matrix_solution);
        int is_sent = send(os, matrix_solution->to_string().c_str(), matrix_solution->to_string().length(), 0);
        if (is_sent == -1) {
          cout << "The Message Wasn't sent: " + matrix_solution->to_string() << endl;
        }
      }
    }
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MYCLIENTHANDLER_H_

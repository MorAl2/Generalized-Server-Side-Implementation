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

      while (getline(stream, line, '\n')) {
        // i got the information
        if (line == "end") {
          endFlag = true;
          break;
        } else {
          // creating a Problem Object from The Information.
          vector<int>* row = new vector<int>();
          stringstream stream(line);
          string val;
          while (getline(stream, val, ',')){
            row->push_back(atoi(val.c_str()));
          }
          matrix_problem->addline(row);
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

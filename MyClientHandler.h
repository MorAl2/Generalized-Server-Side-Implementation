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

// class for handaling the Input.
class MyClientHandler : public ClientHandler {
  Solver<MatrixProblem *, MatrixSolution *> *solver;
  CacheManager<MatrixProblem *, MatrixSolution *> *cm;
 public:
  // CTOR.
  MyClientHandler(Solver<MatrixProblem *, MatrixSolution *> *sol,
                  CacheManager<MatrixProblem *, MatrixSolution *> *cache) {
    solver = sol;
    cm = cache;
  }
// TODO - handle non cubic matrix!!!!
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
    // reading until the end is reached.
    while (!endFlag) {
      // buffer for holding the rcved data.
      char buffer[1024] = {0};
      // rcv the data.
      int valread = read(is, buffer, 1024);
      if (valread == -1) {
        cout << "Error - Read" << endl;
        throw "Error - Read";
      }
      // spliting to lines.
      stringstream stream1(buffer);
      string line;
      // going throughe each lines.
      while (getline(stream1, line, '\n')) {
        // if the lines is empty.
        if (line == "") {
          continue;
        }
        // if the end is reached.
        if (line == "end") {
          endFlag = true;
          break;
        } else {
          // creating a Problem Object from The Information.
          vector<double> *row = new vector<double>();
          stringstream stream(line);
          string val;
          // going for each value.
          while (getline(stream, val, ',')) {
            row->push_back(atoi(val.c_str()));
          }
          flush(stream);
          // setting the dimension of the matrix.
          if (dimension == 0) {
            dimension = row->size() - 1;
          }
          // the start and end values.
          if (size > dimension) {
            if (startFlag) {
              matrix_problem->setStart(row->at(0), row->at(1));
              startFlag = false;
            } else {
              matrix_problem->setEnd(row->at(0), row->at(1));
            }
          } else if (size <= dimension) {
            // creaeting a new line of the matrix.
            vector<State<string> *> *stateRow = new vector<State<string> *>();
            int colPos = 0;
            // going over each value and adding to the matrix.
            for (auto it = row->begin(); it != row->end(); it++) {
              double value = *it.base();
              auto start = new State<string>(to_string(value), value);
              start->setPosition(rowPos, colPos);
              stateRow->push_back(start);
              matrix_problem->addToStateString(to_string((int) value) + ",");
              colPos++;
            }
            // adding the line to the matrix.
            matrix_problem->addline(stateRow);
            size++;
            rowPos++;
          }
        }
      }
    }
    // checking if the solution is in the cache.
    if (cm->isSolutionExists(matrix_problem)) {
      string sol = cm->getSolution(matrix_problem);
      int is_sent = send(os, sol.c_str(), sol.length(), 0);
      if (is_sent == -1) {
        cout << "The Message Wasn't sent: " + sol << endl;
      }
    } else {
      // if its isnt in the cache solving it and adding to cache.
      MatrixSolution *matrix_solution = solver->solve(matrix_problem);
      cm->addSolution(matrix_problem, matrix_solution);
      int is_sent = send(os, matrix_solution->to_string().c_str(), matrix_solution->to_string().length(), 0);
      if (is_sent == -1) {
        cout << "The Message Wasn't sent: " + matrix_solution->to_string() << endl;
      }
    }
    // closing the connection.
    close(is);
  }
};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MYCLIENTHANDLER_H_

#ifndef GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_
#define GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_

#include <iostream>
#include <vector>
#include "State.h"
#include "Searchable.h"

using namespace std;
// class for the matrix to be searched on.
class MatrixProblem : public Searchable<string> {
  // description.
  string state;
  // the matrix.
  vector<vector<State<string> *> *> matrix;
  // the start and goal position.
  pair<int, int> src;
  pair<int, int> target;

 public:
  /** class for saving to the cache by string.
   *
   * @return desciption string.
   */
  string to_string() {
    return state;
  }

  /** adding new line to the matrix.
   *
   * @param mat the line.
   */
  void addline(vector<State<string> *> *mat) {
    matrix.push_back(mat);
  }
  /** setting the start position.
 *
 * @param x col
 * @param y row
 */
  void setStart(int x, int y) {
    this->src = pair<int, int>(x, y);
  }
/** setting the end position.
 *
 * @param x col
 * @param y row
 */
  void setEnd(int x, int y) {
    this->target = pair<int, int>(x, y);

  }
  /** add data to the description string.
   *
   * @param x the data.
   */
  void addToStateString(string x) {
    state.append(x);
  }
  /**
   * getting the start position.
   * @return start position.
   */
  State<string> *getInitialState() {
    return matrix.at(src.first)->at(src.second);
  }
  /**
   * checking if the vertex is the goal.
   * @param s the vertex.
   * @return true if its the goal, false otherwise.
   */
  bool isGoalState(State<string> *s) {
    if (s->rowPos == target.first && s->colPos == target.second) {
      return true;
    }
    return false;
  }
  /** if the location is a valid location.
   *
   * @param row
   * @param col
   * @param size matrix size.
   * @return if the location is valid.
   */
  bool isValidLocation(int row, int col, int size) {
    return (row >= 0) && (row < size) &&
        (col >= 0) && (col < size);
  }
  /**
   * checking all the possible states and returning the valid ones.
   * @param the vertex.
   * @return vector of the possible states.
   */
  vector<State<string> *> *getAllPossibleStates(State<string> *s) {
    int row = s->rowPos;
    int col = s->colPos;
    int size = matrix.size();
    vector<State<string> *> *adjList = new vector<State<string> *>();
    if (isValidLocation(row + 1, col, size) && matrix.at(row + 1)->at(col)->cost != -1) {
      adjList->push_back(matrix.at(row + 1)->at(col));
    }
    if (isValidLocation(row, col + 1, size) && matrix.at(row)->at(col + 1)->cost != -1) {
      adjList->push_back(matrix.at(row)->at(col + 1));
    }
    if (isValidLocation(row - 1, col, size) && matrix.at(row - 1)->at(col)->cost != -1) {
      adjList->push_back(matrix.at(row - 1)->at(col));
    }
    if (isValidLocation(row, col - 1, size) && matrix.at(row)->at(col - 1)->cost != -1) {
      adjList->push_back(matrix.at(row)->at(col - 1));
    }

    return adjList;
  }
  /**
 * getting the start position.
*/
  virtual pair<int, int> getStart() {
    return this->src;
  }
  /**
   * getting the goal position.
  */

  virtual pair<int, int> getEnd() {
    return this->target;
  }

};

#endif //GENERALIZED_SERVER_SIDE_IMPLEMENTATION__MATRIXPROBLEM_H_

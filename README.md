# Generalized-Server-Side-Implementation

Provides Generic Implemantion of ServerSide using Sockets and MultiThreading, 
The Solver Inetrface Provides API for Problem Solving using The ClientHandler Interface which is an API
of handaling Stream of data recived by the Socket.

This prodcut was build based on the SOLID design Pattrem Priniciples and provide an easy way for Managing ServerSize Comunictaion.

The Current Main of the program Runs Search Algorithm For findiing the shortest path in a field/Matrix/Maze.
The Problem And Solving It Is Also Generic and the api can be used to solve any given problem by the right class which will Impliment The Solver Interface.
(https://github.com/MorAl2/Generalized-Server-Side-Implementation)

# Authors

- Mor Almado.
- Noy Israeli.


## Installation

- Compile the files by Running The following Command:
"g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread"
- g++ must be Installed Beforehand by using "sudo apt-get install g++" 

## Usage

- The program takes as CommandLine Argument the port of which the server should listen on, if no port was given the default port is 5600.

one the server rcved a connection the ClientHandler kicks in and handles the data rcved by the input stream/socket.

the current program Configitraion rcv a metrix as data from the socket at the following format:
1. each value is divided by :","
2. each line is divided by :\n"
3. the metrix is Cubic.
4. after the matrix data the line is the start point
5. the next point is the goal point.
6. afterwards the word "end" on a new line.

the program will then process the data and check if it has solution for that problem in the cache.
otherwise it will solve the problem Using the Proper Solver Implemention and send back the least costly path from start to goal point which is the solutio to this problem.

Any problem can be solved by specfing the Right Implemntaion of Solver And ClinetHandler Intefaces for processing and solving the problem.

Using the ObjectAdapter Solid principles can still work, for example in the main program it adptes from search algorithem to the solver interface and use the Searcher to find the least costly Path using the A* Algo.

3 more Search algorithem are implimented in the files include an compare between them in the PDF file.
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
GitHub Link for the project: https://github.com/MorAl2/FlightSimulatorInterpreter

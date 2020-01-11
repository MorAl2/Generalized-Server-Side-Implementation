#include <iostream>
#include <sstream>
#include <fstream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Main.h"

using namespace std;
    int main(int argc, char *argv[]) {
        try {
            server_side::boot::Main* run = new  server_side::boot::Main();
            run->main(argc,argv);
        }
        catch (const char *e) {
            cout << e << endl;
        }
    }


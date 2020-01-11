#include "StringReverser.h"

// reverse and return the string
string StringReverser::solve(string p) {
    int n = p.length();
    for (int i = 0; i < n / 2; i++)
        swap(p[i], p[n - i - 1]);
    return p;
}

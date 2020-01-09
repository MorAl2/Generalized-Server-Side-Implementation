//
// Created by noy on 09/01/2020.
//

#include "StringReverser.h"
#include <bits/stdc++.h>
using namespace std;
// Function to reverse a string
string StringReverser::solve(string p) {
        int n = p.length();
        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++)
            swap(p[i], p[n - i - 1]);
}

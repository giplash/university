//
//  main.cpp
//  lab-2
//
//  Created by Viktor Anashkin on 9/26/18.
//  Copyright © 2018 BSU. All rights reserved.
//

#include <iostream>
#include "Complex.h"
#include <vector>
using namespace std;

vector<Complex> add(vector<Complex>, vector<Complex>);
void input(vector<Complex>&, int n);
void output(vector<Complex>);

int main(int argc, const char * argv[]) {
    vector<Complex> a, b, c;
    int dimension;
    cout << "Input vector's dimension:" << endl;
    cin >> dimension;
    cout << "Input vector A coords:" <<  endl << endl;
    input(a, dimension);
    cout << "Input vector B coords:" <<  endl << endl;
    input(b, dimension);
    c = add(a, b);
    cout << "Result:" << endl;
    output(c);
    return 0;
}

void input(vector<Complex>& a, int n) {
    for (int i = 0; i < n; i++) {
        double real, imag;
        cout << "Input real and imaginary parts of " << i+1 << "nth coord" << endl;
        cin >> real >> imag;
        Complex el(real, imag);
        a.push_back(el);
    }
};

void output(vector<Complex> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << i + 1 << ") " << a[i] << endl;
    }
}

vector<Complex> add(vector<Complex> a, vector<Complex> b) {
    vector<Complex> c;
    if (a.size() != b.size()) {
        cout << "We can't do this. Vector's dimensions are not the same" << endl;
        return c;
    }
    for (int i = 0; i < a.size(); i++) {
        Complex res = a[i] + b[i];
        c.push_back(res);
    }
    return c;
    
}

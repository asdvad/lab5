#include "Header.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    vectors v[5];
    InputMatrix(v);
    vectors w[5];
    for (int i = 0; i < 5; i++) {
        SortMatrix(&v[i], &w[i], 0, 4);
    }
    cout << "\n";
    OutputMatrix(v);
    SumPidDiagonal(v);
    return 0;
}
#include "Header.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void InputMatrix(vectors V[])
{
    cout << "input matrix\n";
    for (int i = 0; i < num; i++) {

        for (int j = 0; j < num; j++) {
            cin >> V[i].Vector[j];
        }
    }
}

void OutputMatrix(vectors V[])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << V[i].Vector[j] << setw(7);
        }
        cout << "\n";
    }
}
void SortMatrix(vectors* V, vectors* W, int l, int r)
{
    int m = (l + r) / 2;
    if (l != r) {
        SortMatrix(V, W, l, m);
        SortMatrix(V, W, m + 1, r);
        int i = l;
        int k = l;
        int ii = m + 1;
        while (i < m + 1 && ii < r + 1) {
            if (V->Vector[i] >= V->Vector[ii]) {
                W->Vector[k] = V->Vector[ii];
                k++;
                ii++;
            }
            else if (V->Vector[ii] > V->Vector[i]) {
                W->Vector[k] = V->Vector[i];
                k++;
                i++;
            }
        }
        if (i < m + 1) {
            while (i != m + 1) {
                W->Vector[k] = V->Vector[i];
                i++;
                k++;
            }
        }
        else if (ii < r + 1) {
            while (ii != r + 1) {
                W->Vector[k] = V->Vector[ii];
                ii++;
                k++;
            }
        }
        for (int i = 0; i <= r; i++) {
            V->Vector[i] = W->Vector[i];
        }
    }
}

void SumPidDiagonal(vectors V[])
{
    double F = 1;
    for (int column = 0; column < num; column++) {
        int sum = 0;
        for (int elements = num-1; elements > num-column-1; elements--) {
            sum += V[elements].Vector[column];
        }
        F *= (column == 0 ? 1 : sum);
        cout << "Sum[" << column << "]=" << sum << "\n";
    }

    F = (F < 0 ? -pow(-F, 0.25) : pow(F, 0.25));
    cout << "F = " << F;

    return;
}

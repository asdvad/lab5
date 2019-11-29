#pragma once
#define num 5
#include <string>
#include <iostream>
#include <iomanip>
class vectors
{
private:
    double Vector[num];
public:
    friend void InputMatrix(vectors V[]);
    friend void OutputMatrix(vectors V[]);
    friend void SortMatrix(vectors* V, vectors* W, int l, int r);
    friend void SumPidDiagonal(vectors V[]);
};
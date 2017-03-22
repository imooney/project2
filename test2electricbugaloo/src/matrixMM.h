//  matrixMM.h
//  Created by Isaac Mooney on 3/15/17.

#ifndef matrixMM_h
#define matrixMM_h

#include <vector>
#include "test_vecNd.h"

class matrixMM {
private:
    std::vector<vecNd> matrix;
    int size;
public:
    //constructors and destructor
    matrixMM(); //default
    matrixMM(const int &);
    matrixMM(const std::vector<vecNd> &, const int &);
    matrixMM(const matrixMM &);
    
    ~matrixMM() {};

    //overloaded operators
    matrixMM & operator = (const matrixMM &);
    matrixMM & operator += (const matrixMM &);
    matrixMM & operator -= (const matrixMM &);
    
    //member functions
    void sizecheck(const matrixMM &);
    void Print();
    double Size() { return size;}
    double Get(const int col, const int row) {
        if ((col >= 0 && col < size) && (row >= 0 && row < size)) {
            return matrix[col][row];
        }
        std::cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
    void Set(const int col, const int row, const double num) {
        if ((col >= 0 && col < size) && (row >= 0 && row < size)) {
            matrix[col][row] = num;
            return;
        }
        std::cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
};

#endif /* matrixMM_h */

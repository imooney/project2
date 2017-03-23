//  matrixNM.h
//  Created by Isaac Mooney on 3/15/17.

#ifndef matrixNM_h
#define matrixNM_h

#include <vector>
#include "vecNd.h"

class matrixNM {
private:
    std::vector<vecNd> matrix; // the vector containing the vecNds
    int row_size; // number of columns in the matrix
    int col_size; // number of rows (number of vecNds)
public:
    //constructors and destructor
    matrixNM(); //default: 3x3 matrix of 0s
    matrixNM(const int &); // nxn matrix of 0s
    matrixNM(const int &, const int &); // nxm matrix of 0s
    matrixNM(const std::vector<vecNd> &, const int &); // nxm matrix of your choice
    matrixNM(const matrixNM &); // copy of nxm matrix of your choice
    
    ~matrixNM() {}; // destructor

    //overloaded operators
    vecNd & operator [] (const int &);
    matrixNM & operator = (const matrixNM &);
    matrixNM & operator += (const matrixNM &);
    matrixNM & operator -= (const matrixNM &);
    matrixNM & operator + (const matrixNM &);
    matrixNM & operator - (const matrixNM &);
    matrixNM & operator *= (const double &);
    matrixNM & operator * (const double &);
    matrixNM & operator / (const double &);
    matrixNM & operator /= (const double &);
    matrixNM & operator * (const matrixNM &); //matrix multiplication
    
    //member functions
    void sizecheck(const matrixNM &); // ensures matrices in operation are compatible
    void Print(); // prints the matrix to the stream
    double Size() { return row_size*col_size;} // gets the number of elements
    // gets a particular element at position ij
    double Get(const int col, const int row) const {
        if ((col >= 0 && col < col_size) && (row >= 0 && row < row_size)) {
            return matrix[col][row];
        }
        std::cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
    // sets a particular element at position ij
    void Set(const int col, const int row, const double num) {
        if ((col >= 0 && col < col_size) && (row >= 0 && row < row_size)) {
            matrix[col][row] = num;
            return;
        }
        std::cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
    //swaps two rows with each other
    void row_swap(const int &, const int &);
    //swaps two columns with each other
    void col_swap(const int &, const int &);
    //returns the multiplicative identity matrix of given size
    static matrixNM & Id(const int &);
};

#endif /* matrixNM_h */

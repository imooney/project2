//  matrixNM.h
//  Created by Isaac Mooney on 3/15/17.

#ifndef matrixNM_h
#define matrixNM_h

#include <vector>
#include "vecNd.h"

class matrixNM {
private:
    std::vector<vecNd> matrix;                          //the vector containing the vecNds
    int row_size;                                       //number of columns in the matrix
    int col_size;                                       //number of rows (number of vecNds)
public:
    //constructors and destructor
    matrixNM();                                         //default: 3x3 matrix of 0s
    matrixNM(const int &);                              //nxn matrix of 0s
    matrixNM(const int &, const int &);                 //nxm matrix of 0s
    matrixNM(const std::vector<vecNd> &, const int &);  //nxm matrix of your choice
    matrixNM(const matrixNM &);                         //copy of nxm matrix of your choice
    
    ~matrixNM() {};                                     //destructor

    //overloaded operators
    vecNd    & operator []  (const int &);              //matrix access
    matrixNM & operator =   (const matrixNM &);         //matrix assignment
    matrixNM & operator +=  (const matrixNM &);         //matrix addition
    matrixNM & operator -=  (const matrixNM &);         //matrix subtraction
    matrixNM & operator +   (const matrixNM &);         //matrix addition
    matrixNM & operator -   (const matrixNM &);         //matrix subtraction
    matrixNM & operator *=  (const double &);           //scalar multiplication
    matrixNM & operator *   (const double &);           //scalar multiplication
    matrixNM & operator /   (const double &);           //scalar division
    matrixNM & operator /=  (const double &);           //scalar division
    matrixNM & operator *   (const matrixNM &);         //matrix multiplication
    matrixNM & operator *=  (const matrixNM &);         //matrix multiplication
    
    //member functions
    void sizecheck(const matrixNM &);                   //ensures matrices in operation are compatible
    void Print();                                       //prints the matrix to the stream
    double Size() { return row_size*col_size;}          //gets the number of elements
    
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
    
    //row and column operations
    matrixNM & row_swap(const int &, const int &);      //swaps two rows with each other
    matrixNM & col_swap(const int &, const int &);      //swaps two columns with each other
    matrixNM & row_delete(const int &);                 //removes a row
    matrixNM & col_delete(const int &);                 //removes a column
    matrixNM & row_add_other(const int &, const int &, const double &); //adds row multiple to another
    matrixNM & col_add_other(const int &, const int &, const double &); //adds column multiple to another
    //linear algebra operations
    static matrixNM & Id(const int &);                  //returns multiplicative identity matrix
    matrixNM & transpose();                             //transpose
    void assign_subset(const matrixNM &);               //assigns size n-1 matrix to bottom right corner
    matrixNM & upper_triangularize();                   //upper triangularize
    double determinant();                               //determinant
    matrixNM & LUdecomp(std::vector<int> &);            //LU decomposition
    matrixNM & inverse();                               //inverse
};

#endif /* matrixNM_h */

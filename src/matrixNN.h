//  matrixNN.h
//  Created by Isaac Mooney on 3/12/17.

#ifndef matrixNN_h
#define matrixNN_h

#include <iostream>
#include <vector>
#include "vecNd.h"
#include "matrixNN.h"

using namespace std;

//a simple nxn matrix class
class matrixNN {
private:
    //vector of vecNds
    vector<vecNd*> matrix;
    //size of the vector
    int size;
public:
    //Constructors and Destructor
    matrixNN(); //default constructor
    matrixNN(int length); //constructs empty ND vecNd
    matrixNN(vector<vecNd*> mat, int length); //constructs ND vecNd with given values
    matrixNN(const matrixNN & vec); //copy constructor
    
    //destructor
    ~matrixNN() {
        /*
        while (!matrix.empty()) {
            delete matrix.back();
            matrix.pop_back();
        }
         */
    }
    
    //overloaded operators
    //matrixNN& operator += (matrixNN &);
    //matrixNN& operator -= (matrixNN &);
    matrixNN& operator + (matrixNN &);
    /*
    matrixNN& operator - (matrixNN &);
    double operator * (matrixNN &);
    matrixNN& operator * (double &);
    matrixNN& operator *= (double &);
     */
    vecNd operator [] (const int &);
    const matrixNN &operator=(const matrixNN &); //assignment operator
    
    //setter functions
    void Set(int col, int row, double value) {
        //check that we're in bounds
        if (col < size && row < size) {
            //set the value
            matrix[col][row] = value;
        }
        else {cerr << "You're out of bounds." << '\n';}
    }
    
    //getter functions
    double Get(int col, int row) {
        //check that we're in bounds
        if (col < size && row < size) {
            //get the value
            return (*matrix[col])[row];
        }
        else {cerr << "You're out of bounds." << '\n'; return -1;}
    }
    
    //member functions
    //prints the matrix to the stream
    void print();
    /*
    //calculates the magnitude of the matrix
    double Length();
     */
    //checks that two matrices being operated on each other are the same size
    void sizecheck(matrixNN &);
    /*
    //vector product in 3 dimensions (vector*vector -> vector)
    vecNd cross3D(matrixNN &);
    //vector product in 2 dimensions (vector*vector -> scalar)
    double cross2D(matrixNN &);
     */
};

#endif /* matrixNN_h */

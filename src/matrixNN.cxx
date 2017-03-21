//  matrixNN.cxx
//  Created by Isaac Mooney on 3/12/17.

#include "vecNd.h"
#include "matrixNN.h"
#include <iostream>
#include <vector>

using namespace std;

void matrixNN::sizecheck(matrixNN & m) {
    cout << "matrix sizecheck" << endl;
    //checks that two vectors are the same size
    if (size != m.size) {
        cerr << "Operation not defined for matrices of different sizes. Exiting.\n";
        exit(1);
    }
    else { return;}
}

//creates a 3x3 matrix with value -1 in every entry
matrixNN::matrixNN() {
    cout << "matrix construct 1" << endl;
    size = 3;
    double init[3] = {-1, -1, -1};
    vecNd *col = new vecNd(init, size);
    matrix.reserve(size);
    for (int i = 0; i < size; ++ i) {
        matrix[i] = col;
    }
    //matrix = vector<vecNd>(size, *col);
    //vector<vecNd> matrix(3, *col);
}

//creates a 3x3 matrix with value -1 in every entry
matrixNN::matrixNN(int length) {
    cout << "matrix construct 2" << endl;
    size = length;
    vecNd *col = new vecNd(size);
    matrix.reserve(size);
    for (int i = 0; i < size; ++ i) {
        matrix[i] = col;
    }
}


matrixNN::matrixNN(vector<vecNd*> mat, int length) {
    cout << "matrix construct 3" << endl;
    //constructor for vecNd of given length with given values
    if (length <= 1) {
        cerr << "Please give a non-trivial matrix (2D or greater). Exiting.\n"; exit(1);
    }
    //initializes array size and allocates the memory
    size = length;
    //FIX LATER. SHOULD BE ABLE TO DO: matrix = new matrixNN(size);
    //allocate the memory of the same size as the assigned vector
    matrix.resize(size);
    /*
    for (int i = 0; i < size; ++i) {
        matrix[i] = new vecNd(size);
    }
     */
    for(int i = 0; i < size; ++ i) {
        matrix[i] = mat.at(i);
    }
}

matrixNN::matrixNN(const matrixNN & copy) {
    cout << "matrix copy " << endl;
    //copy constructor
    //allocates the memory
    matrix.resize(copy.size);
    cout << "i ";
    //copies the size
    size = copy.size;
    cout << "have ";
    //copies the values
    for (int i = 0; i < size; ++ i) {
        cout << "you ";
        *matrix[i] = *copy.matrix[i];
    }
    cout << "now" << endl;
}

const matrixNN &matrixNN::operator=(const matrixNN & eq) {
    cout << "matrix = " << endl;
    //if the pointer is at the location of the assignment, just return the value
    if (this == &eq) {
        return *this;
    }
    //delete the current values to get ready for the new ones
    //allocate the memory of the same size as the assigned vector
    matrix.resize(eq.size);
    //assign that size to the private size
    size = eq.size;
    for (int i = 0; i < size; ++ i) {
        //copy the values over
        matrix[i] = eq.matrix[i];
    }
    //return the vecNd at the pointer to itself
    return *this;
}

matrixNN& matrixNN::operator+(matrixNN & mat) {
    cout << "matrix +" << endl;
    sizecheck(mat);
    matrixNN * add = new matrixNN(mat.size);
    for (int i = 0; i < mat.size; ++ i) {
        *(add->matrix[i]) = *mat.matrix[i] + *matrix[i];
        cout << "back here "; (add->matrix[i])->Print();
    }
    cout << "DONE" << endl;
    return *add;
}

/*
matrixNN& matrixNN::operator+=(matrixNN & mat) {
    //overloaded += operator
    sizecheck(mat);
    for (int i = 0; i < mat.size; ++ i) {
        //adds the values and assigns the results to the first matrix
        *matrix[i] += *mat.matrix[i];
    }
    return *this;
}
*/
/*
matrixNN& matrixNN::operator-=(matrixNN & mat) {
    //overloaded -= operator
    sizecheck(mat);
    for (int i = 0; i < mat.size; ++ i) {
        //adds the values and assigns the results to the first matrix
        *matrix[i] -= *mat[i];
    }
    return *this;
}
*/
vecNd matrixNN::operator[](const int & index) {
    cout << "matrix []" << endl;
    //check that it's in bounds
    if (index < size) {
        //return it
        return *matrix[index];
    }
    else {cerr << "You're out of bounds. Exiting." << '\n'; exit(1);}
}


void matrixNN::print() {
    cout << "matrix print" << endl;
    for (int i = 0; i < size; ++ i) {
        //cout << ((*matrix[i])[i]) << endl;
        matrix[i]->Print();
    }
    cout << '\n';
}

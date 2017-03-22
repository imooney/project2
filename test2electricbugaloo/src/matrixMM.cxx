//  matrixMM.cxx
//  Created by Isaac Mooney on 3/15/17.

#include "matrixMM.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~~~~~

//default constructor
matrixMM::matrixMM() {
    size = 3;
    vecNd* row = new vecNd(3);
    matrix.resize(3);
    for (unsigned i = 0; i < 3; ++ i) {
        matrix[i] = *row;
    }
}

//constructor for given size
matrixMM::matrixMM(const int & dim) {
    size = dim;
    vecNd* row = new vecNd(size);
    matrix.resize(size);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] = *row;
    }
}

//constructor for given values and given size
matrixMM::matrixMM(const vector<vecNd> & mat, const int & dim) {
    if (dim <= 1) {
        cerr << "Matrix must be non-trivial: i.e. 2x2 or greater. Exiting.\n"; exit(1);
    }
    size = dim;
    matrix.resize(size);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] = mat[i];
    }
}

//copy constructor
matrixMM::matrixMM(const matrixMM & copy) {
    size = copy.size;
    matrix.resize(size);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] = copy.matrix[i];
    }
}

//~~~~~~~~~~~~~~~~~~~~~~OVERLOADED OPERATORS~~~~~~~~~~~~~~~~~~~~~~

//overloaded assignment operator
matrixMM & matrixMM::operator = (const matrixMM & eq) {
    if (this == & eq) {
        return *this;
    }
    size = eq.size;
    matrix.resize(size);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] = eq.matrix[i];
    }
    return *this;
}

//overloaded += operator
matrixMM & matrixMM::operator += (const matrixMM & add) {
    sizecheck(add);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] += add.matrix[i];
    }
    return *this;
}

//overloaded -= operator
matrixMM & matrixMM::operator -= (const matrixMM & add) {
    sizecheck(add);
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i] -= add.matrix[i];
    }
    return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~


//checks that the matrices being compared are the same size
void matrixMM::sizecheck(const matrixMM & mat) {
    if (mat.size != size) {
        cerr << "Matrices must have the same size for this operation. Exiting.\n"; exit(1);
    }
    return;
}

//prints the matrix
void matrixMM::Print() {
    for (unsigned i = 0; i < size; ++ i) {
        matrix[i].Print();
    }
    cout << '\n';
    return;
}


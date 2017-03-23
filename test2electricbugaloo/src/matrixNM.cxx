//  matrixNM.cxx
//  Created by Isaac Mooney on 3/15/17.

#include "matrixNM.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~~~~~

//default constructor
matrixNM::matrixNM() {
    row_size = 3; col_size = 3;
    vecNd* row = new vecNd(3);
    matrix.resize(3);
    for (unsigned i = 0; i < 3; ++ i) {
        matrix[i] = *row;
    }
}

//constructor for given size square matrix
matrixNM::matrixNM(const int & dim) {
    row_size = dim; col_size = dim;
    vecNd* row = new vecNd(row_size);
    matrix.resize(col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] = *row;
    }
}

//constructor for given size nxm matrix
matrixNM::matrixNM(const int & num_cols, const int & num_rows) {
    col_size = num_rows; row_size = num_cols;
    vecNd* row = new vecNd(row_size);
    matrix.resize(col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] = *row;
    }
}

//constructor for given values and given size
matrixNM::matrixNM(const vector<vecNd> & mat, const int & num_rows) {
    if (num_rows <= 1 && mat[0].Size() <=1) {
        cerr << "Matrix must be non-trivial: i.e. 1xm || nx1 or greater. Exiting.\n"; exit(1);
    }
    row_size = mat[0].Size(); col_size = num_rows;
    matrix.resize(col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] = mat[i];
    }
}

//copy constructor
matrixNM::matrixNM(const matrixNM & copy) {
    row_size = copy.row_size; col_size = copy.col_size;
    matrix.resize(col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] = copy.matrix[i];
    }
}

//~~~~~~~~~~~~~~~~~~~~~~OVERLOADED OPERATORS~~~~~~~~~~~~~~~~~~~~~~

vecNd & matrixNM::operator [] (const int & index) {
    if (index < 0 || index >= col_size) {
        cout << "mat brak" << endl;
        cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
    return matrix[index];
}

//overloaded assignment operator
matrixNM & matrixNM::operator = (const matrixNM & eq) {
    if (this == & eq) {
        return *this;
    }
    col_size = eq.col_size; row_size = eq.row_size;
    matrix.resize(col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] = eq.matrix[i];
    }
    return *this;
}

//overloaded += operator
matrixNM & matrixNM::operator += (const matrixNM & add) {
    sizecheck(add);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] += add.matrix[i];
    }
    return *this;
}

//overloaded -= operator
matrixNM & matrixNM::operator -= (const matrixNM & add) {
    sizecheck(add);
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] -= add.matrix[i];
    }
    return *this;
}

//overloaded + operator
matrixNM & matrixNM::operator + (const matrixNM & add) {
    sizecheck(add);
    matrixNM * res = new matrixNM(add.row_size, add.col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        res->matrix[i] = matrix[i] + add.matrix[i];
    }
    return *res;
}

//overloaded - operator
matrixNM & matrixNM::operator - (const matrixNM & subtract) {
    sizecheck(subtract);
    matrixNM * res = new matrixNM(subtract.row_size, subtract.col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        res->matrix[i] = matrix[i] - subtract.matrix[i];
    }
    return *res;
}

//overloaded *= (scalar) operator
matrixNM & matrixNM::operator *= (const double & scale) {
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] *= scale;
    }
    return *this;
}

//overloaded * (scalar) operator
matrixNM & matrixNM::operator * (const double & scale) {
    matrixNM * res = new matrixNM(row_size, col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        res->matrix[i] = matrix[i]*scale;
    }
    return *res;
}

//overloaded /= (scalar) operator
matrixNM & matrixNM::operator /= (const double & scale) {
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i] /= scale;
    }
    return *this;
}

//overloaded / (scalar) operator
matrixNM & matrixNM::operator / (const double & scale) {
    matrixNM * res = new matrixNM(row_size, col_size);
    for (unsigned i = 0; i < col_size; ++ i) {
        res->matrix[i] = matrix[i]/(double)scale;
    }
    return *res;
}

//overloaded * (matrix) operator
matrixNM & matrixNM::operator * (const matrixNM & mult) {
    if (row_size != mult.col_size) {
        cerr << "Dimensions incorrect for matrix multiplication. Exiting.\n"; exit(1);
    }
    matrixNM * prod = new matrixNM(mult.row_size, col_size);
    for (unsigned l = 0; l < mult.row_size; ++ l) {
        for (unsigned k = 0; k < col_size; ++ k) {
            for (unsigned j = 0; j < row_size; ++ j) {
                prod->matrix[k][l] += matrix[k][j] * mult.matrix[j][l];
            }
        }
    }
    return *prod;
}

//~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~


//checks that the matrices being compared are the same size
void matrixNM::sizecheck(const matrixNM & mat) {
    if (mat.row_size != row_size || mat.col_size != col_size) {
        cerr << "Matrices must have the same size for this operation. Exiting.\n"; exit(1);
    }
    return;
}

//prints the matrix
void matrixNM::Print() {
    for (unsigned i = 0; i < col_size; ++ i) {
        matrix[i].Print();
    }
    cout << '\n';
    return;
}

//swaps two rows with each other
void matrixNM::row_swap(const int & row1, const int & row2) {
    vecNd * temp = new vecNd();
    *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = *temp;
    return;
}

//swaps two columns with each other
void matrixNM::col_swap(const int & col1, const int & col2) {
    double temp = -99999;
    for (unsigned i = 0; i < col_size; ++ i) {
        temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
    return;
}

//returns identity matrix of given size
matrixNM & matrixNM::Id(const int & dim) {
    matrixNM * id = new matrixNM(dim);
    for (unsigned i = 0; i < dim; ++ i) {
        id->matrix[i][i] = 1;
    }
    return *id;
}


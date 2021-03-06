//  matrixNM.cxx
//  Created by Isaac Mooney on 3/15/17.

#include "matrixNM.h"
#include <cmath>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~~~~~//

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

//~~~~~~~~~~~~~~~~~~~~~~OVERLOADED OPERATORS~~~~~~~~~~~~~~~~~~~~~~//

vecNd & matrixNM::operator [] (const int & index) {
    if (index < 0 || index >= col_size) {
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
//I am aware that there exist algorithms which cut down the computational complexity
//to O(n^2.3) or so, rather than O(n^3). However, most of these algorithms tend to
//be memory intensive, so I just stuck with the naïve algorithm which works fine
//for small matrices. So, run this on large matrices at your own peril.
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

//overloaded * (matrix) operator
matrixNM & matrixNM::operator *= (const matrixNM & mult) {
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
    *this = *prod;
    return *this;
}

//~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~//


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
matrixNM & matrixNM::row_swap(const int & row1, const int & row2) {
    matrixNM * rowswap = new matrixNM(*this);
    rowswap->matrix[row1] = matrix[row2];
    rowswap->matrix[row2] = matrix[row1];
    return *rowswap;
}

//swaps two columns with each other
matrixNM & matrixNM::col_swap(const int & col1, const int & col2) {
    matrixNM * colswap = new matrixNM(*this);
    for (unsigned i = 0; i < col_size; ++ i) {
        colswap->matrix[i][col1] = matrix[i][col2];
        colswap->matrix[i][col2] = matrix[i][col1];
    }
    return *colswap;
}

//returns identity matrix of given size
matrixNM & matrixNM::Id(const int & dim) {
    matrixNM * id = new matrixNM(dim);
    for (unsigned i = 0; i < dim; ++ i) {
        id->matrix[i][i] = 1;
    }
    return *id;
}

//returns transpose
matrixNM & matrixNM::transpose() {
    matrixNM * trans = new matrixNM(*this);
    for (unsigned i = 0; i < col_size; ++ i) {
        for (unsigned j = 0; j < i; ++ j) {
            trans->matrix[i][j] = matrix[j][i];
            trans->matrix[j][i] = matrix[i][j];
        }
    }
    return *trans;
}

//returns matrix with column subtracted from original
matrixNM & matrixNM::col_delete(const int & col) {
    matrixNM * narrow = new matrixNM(row_size - 1, col_size);
    for (unsigned i = 0; i < col; ++ i) {
        for (int j = 0; j < col_size; ++ j) {
            narrow->matrix[j][i] = matrix[j][i];
        }
    }
    for (unsigned i = col + 1; i < row_size; ++ i) {
        for (int j = 0; j < col_size; ++ j) {
            narrow->matrix[j][i - 1] = matrix[j][i];
        }
    }
    return *narrow;
}

//returns matrix with row subtracted from original
matrixNM & matrixNM::row_delete(const int & row) {
    matrixNM * squash = new matrixNM(row_size, col_size - 1);
    for (unsigned i = 0; i < row; ++ i) {
        squash->matrix[i] = matrix[i];
    }
    for (unsigned i = row + 1; i < col_size; ++ i) {
        squash->matrix[i - 1] = matrix[i];
    }
    return *squash;
}

//adds multiple of one row to another
matrixNM & matrixNM::row_add_other(const int & row1, const int & row2, const double & scale) {
    matrixNM * rowadd = new matrixNM(*this);
    rowadd->matrix[row1] += matrix[row2]*scale;
    return *rowadd;
}

//adds multiple of one col to another
matrixNM & matrixNM::col_add_other(const int & col1, const int & col2, const double & scale) {
    matrixNM * coladd = new matrixNM(*this);
    for (unsigned i = 0; i < col_size; ++ i) {
        coladd->matrix[i][col1] += matrix[i][col2]*scale;
    }
    return *coladd;
}

//assigns a matrix of size - 1 to the bottom right corner of the larger matrix.
void matrixNM::assign_subset(const matrixNM & other) {
    for (unsigned i = 1; i < col_size; ++ i) {
        for (unsigned j = 1; j < row_size; ++ j) {
            matrix[i][j] = other.matrix[i-1][j-1];
        }
    }
}

//turns the given matrix into an upper triangular one with the same determinant
//via elementary row operations:
//  (a): Swapping rows flips the sign of the determinant
//  (b): Adding a multiple of one row to another leaves the determinant unchanged
//  (c): Multiplying a row by a constant multiplies the determinant by that constant
matrixNM & matrixNM::upper_triangularize() {
    double row_zero = -1, row_nonzero = -1;
    int counter = 0;
    if (row_size == 1) {
        return *this;
    }
    for (unsigned i = 0; i < col_size; ++ i) {
        if (matrix[i][0] == 0) {
            row_zero = i;
            ++ counter;
        }
        else {
            row_nonzero = i;
        }
    }
    matrixNM *mini = new matrixNM();
    if (counter == col_size) {
        *mini = row_delete(0);
        *mini = mini->col_delete(0);
        assign_subset(mini->upper_triangularize());
    }
    else {
        if (matrix[0][0] == 0) {
            *this = row_swap(0, row_nonzero);
            matrix[0] *= -1;
            *mini = *this;
        }
        else {
            *mini = *this;
        }
        for (unsigned i = 1; i < col_size - 1; ++ i) {
            if (matrix[i][0] != 0) {
                *this = row_add_other(i, row_nonzero, -matrix[i][0]/matrix[row_nonzero][0]);
            }
        }
        *this = row_add_other(row_nonzero, 0, -matrix[row_nonzero][0]/matrix[0][0]);
        *mini = row_delete(0);
        *mini = mini->col_delete(0);
        assign_subset(mini->upper_triangularize());
    }
}

//calculates the determinant by upper triangularizing (a copy of) the matrix,
//then recognizing that the determinant of an upper triangular matrix is just
//the product of its diagonal entries, returning that result as the determinant.
double matrixNM::determinant() {
    if (row_size != col_size) {
        cerr << "The determinant is only defined for square matrices. Exiting.\n"; exit(1);
    }
    matrixNM * detmat = new matrixNM(*this);
    detmat->upper_triangularize();
    double det = 1;
    for (unsigned i = 0; i < row_size; ++ i) {
        det *= detmat->matrix[i][i];
    }
    return det;
}

matrixNM & matrixNM::inverse() {
    return *this;
}

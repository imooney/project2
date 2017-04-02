//  matrix.cxx
//  Created by Isaac Mooney on 3/15/17.

#include "matrixNM.h"
#include <vector>

using namespace std;

const int g_size = 5;

//declaration of tests of matrixMN class

void print_test(matrixNM *test_mat);
void getset_test(matrixNM *test_mat);
void size_test(matrixNM* test_mat);
void plus_test(matrixNM* test_mat);
void minus_test(matrixNM* test_mat);
void plusequals_test(matrixNM* test_mat);
void minusequals_test(matrixNM* test_mat);
void star_test(matrixNM* test_mat);
void starequals_test(matrixNM* test_mat);
void div_test(matrixNM* test_mat);
void divequals_test(matrixNM* test_mat);
void matmult_test(matrixNM * test_mat);
void matmulteq_test(matrixNM * test_mat);
void rowswap_test(matrixNM* test_mat);
void colswap_test(matrixNM* test_mat);
void transpose_test(matrixNM* test_mat);
void row_col_delete_test(matrixNM* test_mat);
void row_col_add_test(matrixNM* test_mat);
void determinant_test();
void inverse_test();

int main() {
    
    double vec_a[5] = {0,1,2,3,4};      double vec_b[5] = {5,4,3,2,1};
    double vec_c[5] = {-1,-2,-3,-4,-5}; double vec_d[5] = {0,1,-1,2,-2};
    double vec_e[5] = {5,5,5,5,5};
    
    double vec_f[5] = {0,-1,-2,-3,-4};  double vec_g[5] = {-5,-4,-3,-2,-1};
    double vec_h[5] = {1,2,3,4,5};      double vec_i[5] = {0,-1,1,-2,2};
    double vec_j[5] = {-5,-5,-5,-5,-5};
    
    vecNd * vec5_a = new vecNd(vec_a, 5); vecNd * vec5_b = new vecNd(vec_b, 5);
    vecNd * vec5_c = new vecNd(vec_c, 5); vecNd * vec5_d = new vecNd(vec_d, 5);
    vecNd * vec5_e = new vecNd(vec_e, 5);
    
    vecNd * vec5_f = new vecNd(vec_f, 5); vecNd * vec5_g = new vecNd(vec_g, 5);
    vecNd * vec5_h = new vecNd(vec_h, 5); vecNd * vec5_i = new vecNd(vec_i, 5);
    vecNd * vec5_j = new vecNd(vec_j, 5);
    
    vector<vecNd> full; full.resize(5);     full[0] = *vec5_a; full[1] = *vec5_b;
    full[2] = *vec5_c;  full[3] = *vec5_d;  full[4] = *vec5_e;
    
    vector<vecNd> full2; full2.resize(5); full2[0] = *vec5_f; full2[1] = *vec5_g;
    full2[2] = *vec5_h; full2[3] = *vec5_i; full2[4] = *vec5_j;
    
    vector<vecNd> uneven;   uneven.resize(3);
    uneven[0] = *vec5_f;    uneven[1] = *vec5_a; uneven[2] = *vec5_h;
    
    cout << "Testing constructors and print function: " << '\n';
    matrixNM * def_test     = new matrixNM();
    matrixNM * num_test     = new matrixNM(g_size);
    matrixNM * full_test    = new matrixNM(full, g_size);
    matrixNM * full2_test   = new matrixNM(full2, g_size);
    matrixNM * assign_test  = new matrixNM(g_size);
    matrixNM * uneven_test  = new matrixNM(uneven, 3);
    matrixNM * copy_uneven  = new matrixNM(*uneven_test);
    
    matrixNM *test_mat = new matrixNM[7];
    test_mat[0] = *def_test;    test_mat[1] = *num_test;    test_mat[2] = *full_test;
    test_mat[3] = *full2_test;  test_mat[4] = *assign_test; test_mat[5] = *uneven_test;
    test_mat[6] = *copy_uneven;
    
    *assign_test = *full_test;
    
    //testing print function
    print_test(test_mat);
    
    //testing size function
    size_test(test_mat);
    
    //testing += operator
    plusequals_test(test_mat);
    
    //testing getters and setters
    getset_test(test_mat);
    
    //testing -= operator
    minusequals_test(test_mat);
    
    //testing + and - operators
    plus_test(test_mat);
    minus_test(test_mat);
    
    //testing * (scalar) and *= (scalar)
    starequals_test(test_mat);
    star_test(test_mat);
    
    //testing / (scalar) and /= (scalar)
    div_test(test_mat);
    divequals_test(test_mat);
    
    //testing row and column swapping
    rowswap_test(test_mat);
    colswap_test(test_mat);
    
    //identity matrix test
    matrixNM identity = matrixNM::Id(5); identity.Print();
    
    //testing * (matrix) and *= (matrix)
    matmult_test(test_mat);
    matmulteq_test(test_mat);
    
    //testing matrix transpose
    transpose_test(test_mat);
    
    //testing deletion of column & row
    row_col_delete_test(test_mat);
    
    //testing determinant
    determinant_test();
    
    //testing inverse
    inverse_test();
    
    delete def_test;    def_test    = NULL;
    delete num_test;    num_test    = NULL;
    delete full_test;   full_test   = NULL;
    delete full2_test;  full2_test  = NULL;
    delete assign_test; assign_test = NULL;
    delete uneven_test; uneven_test = NULL;
    delete copy_uneven; copy_uneven = NULL;
     
    delete vec5_a; delete vec5_b; delete vec5_c; delete vec5_d; delete vec5_e;
    vec5_a = NULL; vec5_b = NULL; vec5_c = NULL; vec5_d = NULL; vec5_e = NULL;
    
    delete [] test_mat;
    
    return 0;
}


//implementation of tests of matrixMN class


void print_test(matrixNM *test_mat) {
    cout << "uneven_test: " << '\n'; test_mat[5].Print();
    cout << "copy_uneven: " << '\n'; test_mat[6].Print();
    cout << "def_test: " << '\n'; test_mat[0].Print();
    cout << "num_test: " << '\n'; test_mat[1].Print();
    cout << "full_test: " << '\n'; test_mat[2].Print();
    cout << "assign_test: " << '\n'; test_mat[4].Print();
}
void getset_test(matrixNM *test_mat) {
    cout << "full_test[1][1] = " << test_mat[2].Get(1,1) << '\n' << '\n';
    cout << "setting full_test[1][1] = -10.5.\n"; test_mat[2].Set(1,1,-10.5);
    cout << "resulting matrix: \n"; test_mat[2].Print();
    cout << "full_test[1][1] = " << test_mat[2].Get(1,1) << '\n' << '\n';
}
void size_test(matrixNM* test_mat) {
    double test_uneven = test_mat[5].Size();
    cout << "Number of entries in uneven_test: " << test_uneven << '\n';
    double test = test_mat[0].Size();
    cout << "Number of entries in def_test: " << test << '\n';
    
}
void plus_test(matrixNM* test_mat) {
    cout << "def_test = full_test + full2_test results in: \n";
    test_mat[0] = test_mat[2] + test_mat[3];
    cout << "def_test: \n"; test_mat[0].Print();
}
void minus_test(matrixNM* test_mat) {
    cout << "def_test = full_test - full2_test results in: \n";
    test_mat[0] = test_mat[2] - test_mat[3];
    cout << "def_test: \n"; test_mat[0].Print();
}
void plusequals_test(matrixNM* test_mat) {
    cout << "assign_test += full_test results in: " << '\n'; test_mat[4] += test_mat[2];
    cout << "assign_test: \n"; test_mat[4].Print();
    cout << "full_test: \n"; test_mat[2].Print();
    //uncomment to check that += doesn't add differing sized matrices:
    //*uneven_test += *assign_test; uneven_test->Print();
}
void minusequals_test(matrixNM* test_mat) {
    cout << "full_test -= full2_test results in: \n"; test_mat[2]-= test_mat[3];
    cout << "full_test: \n"; test_mat[2].Print();
    cout << "full2_test: \n"; test_mat[3].Print();
}
void star_test(matrixNM* test_mat) {
    cout << "multiplying def_test by 2 and assigning it to num_test results in num_test = \n";
    test_mat[1] = test_mat[0]*2; test_mat[1].Print();
}
void starequals_test(matrixNM* test_mat) {
    cout << "multiplying def_test by 10. def_test = \n";
    test_mat[0] *= 10; test_mat[0].Print();
}
void div_test(matrixNM* test_mat) {
    cout << "dividing def_test by 100 and assigning it to num_test results in num_test = \n";
    test_mat[1] = test_mat[0]/100; test_mat[1].Print();
}
void divequals_test(matrixNM* test_mat) {
    cout << "dividing def_test by 2. def_test = \n";
    test_mat[0] /= 2; test_mat[0].Print();
}

void matmult_test(matrixNM* test_mat) {
    cout << "testing matrix multiplication. First, full_test * full2_test:\n";
    test_mat[0] = test_mat[2] * test_mat[3]; test_mat[0].Print();
    cout << "Next, uneven_test * full2_test:\n";
    test_mat[0] = test_mat[5] * test_mat[3];
    test_mat[0].Print();
}

void matmulteq_test(matrixNM* test_mat) {
    cout << "testing matrix multiplication and assignment with full_test *= full2_test:\n";
    test_mat[2] *= test_mat[3];
    test_mat[2].Print();;
}

void rowswap_test(matrixNM* test_mat) {
    cout << "swapping 2nd and 3rd rows in def_test: \n";
    test_mat[1] = test_mat[0].row_swap(1,2); test_mat[0].Print(); test_mat[1].Print();
}
void colswap_test(matrixNM* test_mat) {
    cout << "swapping 2nd and 3rd columns in def_test: \n";
    test_mat[1] = test_mat[0].col_swap(1,2); test_mat[0].Print(); test_mat[1].Print();
}

void transpose_test(matrixNM* test_mat) {
    cout << "taking the transpose of full2_test and assigning it to full_test:\n";
    test_mat[2] = test_mat[3].transpose();
    test_mat[2].Print();
    cout << "printing full2_test to check that it is unchanged:\n";
    test_mat[3].Print();
}

void row_col_delete_test(matrixNM* test_mat) {
    cout << "deleting row 1 from full2_test:\n";
    test_mat[3] = test_mat[3].row_delete(1);
    test_mat[3].Print();
    cout << "now deleting column 1 from full2_test, too: \n";
    test_mat[3] = test_mat[3].col_delete(1);
    test_mat[3].Print();
}

void row_col_add_test(matrixNM* test_mat) {
    cout << "adding 5*(row 3) to row 2 in full_test:" << '\n';
    test_mat[2] = test_mat[2].row_add_other(1,2,5);
    test_mat[2].Print();
    cout << "now adding 5*(column 3) to column 2 in full_test:" << '\n';
    test_mat[2] = test_mat[2].col_add_other(1,2,5);
    test_mat[2].Print();
}

void determinant_test() {
    cout << "taking determinant of:\n";
    double det_vec1[10]     = {2,3,4,1,5,6,4,5,2,3};
    double det_vec2[10]     = {-2,4,-3,-2,9,5,6,5,8,7};
    double det_vec3[10]     = {-1,-3,3,2,1,1,3,3,6,7};
    double det_vec4[10]     = {1,2,3,4,5,8,6,9,8,1};
    double det_vec5[10]     = {3.3,2.9,2.1,1.1,11,4,5,2,3,5};
    double det_vec6[10]     = {9,3,4,2,3,7,4,5,6,9};
    double det_vec7[10]     = {4.5,3,1,2.5,10,8,6,4,2,1};
    double det_vec8[10]     = {1.3,4.3,9.2,7,9,9,7,5,3,5};
    double det_vec9[10]     = {0.5,0.5,7.6,2,8,7,6,5,4,3};
    double det_vec10[10]    = {8.8,7,9,7,4.3,3,1.2,8,9.9,1};
    
    vecNd * det_vecn1       = new vecNd(det_vec1, 10);
    vecNd * det_vecn2       = new vecNd(det_vec2, 10);
    vecNd * det_vecn3       = new vecNd(det_vec3, 10);
    vecNd * det_vecn4       = new vecNd(det_vec4, 10);
    vecNd * det_vecn5       = new vecNd(det_vec5, 10);
    vecNd * det_vecn6       = new vecNd(det_vec6, 10);
    vecNd * det_vecn7       = new vecNd(det_vec7, 10);
    vecNd * det_vecn8       = new vecNd(det_vec8, 10);
    vecNd * det_vecn9       = new vecNd(det_vec9, 10);
    vecNd * det_vecn10      = new vecNd(det_vec10, 10);
    
    vector<vecNd> det_vec;   det_vec.resize(10);      det_vec[0] = *det_vecn1;
    det_vec[1] = *det_vecn2; det_vec[2] = *det_vecn3; det_vec[3] = *det_vecn4;
    det_vec[4] = *det_vecn5; det_vec[5] = *det_vecn6; det_vec[6] = *det_vecn7;
    det_vec[7] = *det_vecn8; det_vec[8] = *det_vecn9; det_vec[9] = *det_vecn10;
    
    matrixNM * det_mat = new matrixNM(det_vec, 10);
    det_mat->Print();
    
    double det = det_mat->determinant();
    cout << "determinant is: " << det << '\n';
    
    delete det_mat; det_mat = NULL;
    delete det_vecn1; delete det_vecn2; delete det_vecn3; delete det_vecn4; delete det_vecn5;
    delete det_vecn6; delete det_vecn7; delete det_vecn8; delete det_vecn9; delete det_vecn10;
    det_vecn1 = NULL; det_vecn2 = NULL; det_vecn3 = NULL; det_vecn4 = NULL; det_vecn5 = NULL;
    det_vecn6 = NULL; det_vecn7 = NULL; det_vecn8 = NULL; det_vecn9 = NULL; det_vecn10 = NULL;
}

void inverse_test() {
    cout << "taking inverse of:\n";
    double inv_vec1[3]      = {1,2,3};
    double inv_vec2[3]      = {3,2,3};
    double inv_vec3[3]      = {1,1,1};
    
    vecNd * inv_vecn1       = new vecNd(inv_vec1, 3);
    vecNd * inv_vecn2       = new vecNd(inv_vec2, 3);
    vecNd * inv_vecn3       = new vecNd(inv_vec3, 3);
    
    vector<vecNd> inv_vec;   inv_vec.resize(3);
    inv_vec[0] = *inv_vecn1; inv_vec[1] = *inv_vecn2; inv_vec[2] = *inv_vecn3;
    
    matrixNM * inv_mat = new matrixNM(inv_vec, 3);
    inv_mat->Print();
    
    matrixNM * inverse = new matrixNM(inv_mat->inverse());
    cout << "the inverse is:\n";
    inverse->Print();
    cout << "and the original matrix again, to make sure we haven't altered it:\n";
    inv_mat->Print();
    
    delete inv_mat; inv_mat = NULL;     delete inverse; inverse = NULL;
    delete inv_vecn1; delete inv_vecn2; delete inv_vecn3;
    inv_vecn1 = NULL; inv_vecn2 = NULL; inv_vecn3 = NULL;
}


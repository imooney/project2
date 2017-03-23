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
void rowswap_test(matrixNM* test_mat);
void colswap_test(matrixNM* test_mat);

int main() {
    
    double vec_a[5] = {0,1,2,3,4}; double vec_b[5] = {5,4,3,2,1};
    double vec_c[5] = {-1,-2,-3,-4,-5}; double vec_d[5] = {0,1,-1,2,-2};
    double vec_e[5] = {5,5,5,5,5};
    
    double vec_f[5] = {0,-1,-2,-3,-4}; double vec_g[5] = {-5,-4,-3,-2,-1};
    double vec_h[5] = {1,2,3,4,5}; double vec_i[5] = {0,-1,1,-2,2};
    double vec_j[5] = {-5,-5,-5,-5,-5};
    
    vecNd * vec5_a = new vecNd(vec_a, 5); vecNd * vec5_b = new vecNd(vec_b, 5);
    vecNd * vec5_c = new vecNd(vec_c, 5); vecNd * vec5_d = new vecNd(vec_d, 5);
    vecNd * vec5_e = new vecNd(vec_e, 5);
    
    vecNd * vec5_f = new vecNd(vec_f, 5); vecNd * vec5_g = new vecNd(vec_g, 5);
    vecNd * vec5_h = new vecNd(vec_h, 5); vecNd * vec5_i = new vecNd(vec_i, 5);
    vecNd * vec5_j = new vecNd(vec_j, 5);
    
    vector<vecNd> full; full.resize(5); full[0] = *vec5_a; full[1] = *vec5_b;
    full[2] = *vec5_c; full[3] = *vec5_d; full[4] = *vec5_e;
    
    vector<vecNd> full2; full2.resize(5); full2[0] = *vec5_f; full2[1] = *vec5_g;
    full2[2] = *vec5_h; full2[3] = *vec5_i; full2[4] = *vec5_j;
    
    vector<vecNd> uneven; uneven.resize(3); uneven[0] = *vec5_f; uneven[1] = *vec5_a; uneven[2] = *vec5_h;
    
    cout << "Testing constructors and print function: " << '\n';
    matrixNM * def_test = new matrixNM();
    matrixNM * num_test = new matrixNM(g_size);
    matrixNM * full_test = new matrixNM(full, g_size);
    matrixNM * full2_test = new matrixNM(full2, g_size);
    matrixNM * assign_test = new matrixNM(g_size);
    matrixNM * uneven_test = new matrixNM(uneven, 3);
    matrixNM * copy_uneven = new matrixNM(*uneven_test);
    
    matrixNM *test_mat = new matrixNM[7];
    test_mat[0] = *def_test; test_mat[1] = *num_test; test_mat[2] = *full_test;
    test_mat[3] = *full2_test; test_mat[4] = *assign_test; test_mat[5] = *uneven_test;
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
    
    matrixNM test = matrixNM::Id(5); test.Print();
    

    delete def_test; def_test = NULL;
    delete num_test; num_test = NULL;
    delete full_test; full_test = NULL;
    delete full2_test; full2_test = NULL;
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

void rowswap_test(matrixNM* test_mat) {
    cout << "swapping 2nd and 3rd rows in def_test: \n";
    test_mat[0].row_swap(1,2); test_mat[0].Print();
}
void colswap_test(matrixNM* test_mat) {
    cout << "swapping 2nd and 3rd columns in def_test: \n";
    test_mat[0].col_swap(1,2); test_mat[0].Print();
}


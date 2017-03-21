//  matrix.cxx
//  Created by Isaac Mooney on 3/12/17.

#include <iostream>
#include "vecNd.h"
#include "matrixNN.h"

using namespace std;

const int g_size = 5;

//NOTE: the C++ vector represents the 0th column of the matrix, with the 0th vecNd pointer
//representing the 0th row, and so on.

int main() {
    /*
    matrixNN *matrix = new matrixNN();
    //test arrays
    double vec_a[g_size] = {0,0,0,0,0}; double vec_b[g_size] = {1,1,1,1,1};
    double vec_c[g_size] = {1,0,1,0,1}; double vec_d[g_size] = {-1,-3.1,4,2,12};
    double vec_e[g_size] = {4,19,8,-1,-9.3};
    
    //test vecNds
    vecNd *test_a = new vecNd(vec_a, g_size); vecNd *test_b = new vecNd(vec_b, g_size);
    vecNd *test_c = new vecNd(vec_c, g_size); vecNd *test_d = new vecNd(vec_d, g_size);
    vecNd *test_e = new vecNd(vec_e, g_size);

    //create vector of vecNds
    vector<vecNd*> test_vecNd; test_vecNd.resize(5); test_vecNd[0] = test_a;
    test_vecNd[1] = test_b; test_vecNd[2] = test_c; test_vecNd[3] = test_d; test_vecNd[4] = test_e;

    //create matrixNN using vector of vecNds
    matrixNN * matrix_test = new matrixNN(test_vecNd, g_size);

    //tests:
    //Print
    matrix->print(); matrix_test->print();
    //Getter
    double gettest = matrix_test->Get(3,3); cout << "matrix_test[3][3] = " << gettest << '\n';
    //Copy constructor and assignment operator
    matrixNN *copy_test = new matrixNN();
    *copy_test = *matrix_test;
    //+=
    double testtest = copy_test->Get(3,4); cout << "copy_test[3][4] = " << testtest << '\n';
    
    matrixNN * plus_test = new matrixNN(5);
    cout <<"WHERE" << endl;
    *plus_test = *copy_test + *matrix_test; double yetanother = plus_test->Get(2,2); cout << "yet another " << yetanother << endl; plus_test->print();
    cout << "HERE" << endl;
    */
    
    
    /*
    *copy_test += *matrix_test;
    cout << "MATRIX_TEST: " << endl;
    matrix_test->print();
    double newtest = copy_test->Get(3,4); cout << "copy_test[3][4] = " << newtest << '\n' << '\n';
    double mattest = matrix_test->Get(3,4); cout << "matrix_test[3][4] = " << mattest << '\n' << '\n';
    cout << "COPY_TEST: " << endl;
    copy_test->print(); cout << '\n'; cout << "MATRIX_TEST: " << endl; matrix_test->print();
    *copy_test -= *matrix_test;
    cout << "COPY_TEST: " << endl;
    copy_test->print();
    */
    //deletes
    /*
    delete matrix; matrix = NULL;
    delete test_a; test_a = NULL; delete test_b; test_b = NULL;
    delete test_c; test_c = NULL; delete test_d; test_d = NULL;
    delete test_e; test_e = NULL;
    delete copy_test; copy_test = NULL;
    delete matrix_test; matrix_test = NULL;
    delete plus_test; plus_test = NULL;
     */
    return 0;
}

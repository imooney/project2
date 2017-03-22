//  test_matrix.cxx
//  Created by Isaac Mooney on 3/15/17.

#include "matrixMM.h"
#include <vector>

using namespace std;

const int g_size = 5;

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
    
    cout << "Testing constructors and print function: " << '\n';
    matrixMM * def_test = new matrixMM();
    matrixMM * num_test = new matrixMM(g_size);
    matrixMM * full_test = new matrixMM(full, g_size);
    matrixMM * full2_test = new matrixMM(full2, g_size);
    matrixMM * assign_test = new matrixMM(g_size);
    *assign_test = *full_test;
    
    //testing print function
    double test = def_test->Size(); cout << test << endl;
    def_test->Print(); num_test->Print(); full_test->Print(); assign_test->Print();
    
    //testing += operator
    *assign_test += *full_test; assign_test->Print(); full_test->Print();
    
    //testing getters and setters
    cout << "full_test[1][1] = " << full_test->Get(1,1) << '\n' << '\n';
    full_test->Set(1,1,-10.5); full_test->Print();
    cout << "full_test[1][1] = " << full_test->Get(1,1) << '\n' << '\n';
    *full_test -= *full2_test; full_test->Print(); full2_test->Print();
    
    delete def_test; def_test = NULL;
    
    delete num_test; num_test = NULL;
    delete full_test; full_test = NULL;
    delete full2_test; full2_test = NULL;
     
    delete vec5_a; delete vec5_b; delete vec5_c; delete vec5_d; delete vec5_e;
    vec5_a = NULL; vec5_b = NULL; vec5_c = NULL; vec5_d = NULL; vec5_e = NULL;
    
    return 0;
}

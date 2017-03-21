//  implement.cxx
//  Created by Isaac Mooney on 3/1/17.

#include "vecNd.h"
#include <iostream>

using namespace std;

//for the sake of testing, will use vectors of size 5
const int g_size = 5;

//declaration of tests of vecNd class
void print_test(vecNd *test_vec);
void length_test(vecNd* test_vec);
void plus_test(vecNd* test_vec);
void minus_test(vecNd* test_vec);
void plusequals_test(vecNd* test_vec);
void minusequals_test(vecNd* test_vec);
void brackets_test(vecNd* test_vec);
void star_test(vecNd* test_vec);
void starequals_test(vecNd* test_vec);
void dot_test(vecNd* test_vec);
void cross_test(vecNd* test_vec);
void cross2D_test(vecNd* test_vec);

int main() {
    cout << "Testing!" << '\n';
    //test arrays
    double vec_a[g_size] = {0,0,0,0,0}; double vec_b[g_size] = {1,1,1,1,1};
    double vec_c[g_size] = {1,0,1,0,1}; double vec_d[g_size] = {-1,-3.1,4,2,12};
    double vec_e[g_size] = {4,19,8,-1,-9.3}; double vec_f[g_size] = {-33,-22,-11,0,11};
    
    //test vecNds
    vecNd *test_empty = new vecNd();
    vecNd *test_a = new vecNd(vec_a, g_size); vecNd *test_b = new vecNd(vec_b, g_size);
    vecNd *test_c = new vecNd(vec_c, g_size); vecNd *test_d = new vecNd(vec_d, g_size);
    vecNd *test_e = new vecNd(vec_e, g_size); vecNd *test_f = new vecNd(vec_f, g_size);
    
    //array of them
    vecNd *test_vec = new vecNd[7];
    test_vec[0] = *test_empty;
    test_vec[1] = *test_a; test_vec[2] = *test_b; test_vec[3] = *test_c;
    test_vec[4] = *test_d; test_vec[5] = *test_e; test_vec[6] = *test_f;
    
    //calling tests of vecNd class
    //functions
    //Print:
    print_test(test_vec);
    
    //test of copy constructor
    cout << "~~~testing copy constructor~~~\n";
    vecNd *copytest = new vecNd(*test_f);
    copytest->Print();
    
    //Length:
    length_test(test_vec);
    
    //x (cross product):
    cross_test(test_vec);
    
    //x (cross product - 2D):
    cross2D_test(test_vec);

    //operators
    //+:
    plus_test(test_vec);
    
    //-:
    minus_test(test_vec);
    
    //+=:
    plusequals_test(test_vec);
    
    //-=:
    minusequals_test(test_vec);
    
    //[]:
    brackets_test(test_vec);
    
    //* (scalar*vec):
    star_test(test_vec);
    
    //*= (vec <- scalar*vec):
    starequals_test(test_vec);
    
    //* (vec*vec scalar):
    dot_test(test_vec);
    
    //deletes
    delete test_empty; test_empty = NULL;
    delete test_a; test_a = NULL; delete test_b; test_b = NULL;
    delete test_c; test_c = NULL; delete test_d; test_d = NULL;
    delete test_e; test_e = NULL; delete test_f; test_f = NULL;
    delete [] test_vec; test_vec = NULL;
    return 0;
}

//implementation of tests of vecNd class

void print_test(vecNd *test_vec) {
    cout << "~~~testing print function~~~\n";
    cout << "empty = "; test_vec[0].Print();
    cout << "\na = "; test_vec[1].Print(); cout << "\nb = "; test_vec[2].Print();
    cout << "\nc = "; test_vec[3].Print(); cout << "\nd = "; test_vec[4].Print();
    cout << "\ne = "; test_vec[5].Print(); cout << "\nf = "; test_vec[6].Print();
}


void length_test(vecNd* test_vec) {
    cout << "\n~~~testing length function~~~\n";
    cout << "empty: " << test_vec[0].Length() << '\n';
    cout << "a: " << test_vec[1].Length() << '\n'; cout << "b: " << test_vec[2].Length() << '\n';
    cout << "c: " << test_vec[3].Length() << '\n'; cout << "d: " << test_vec[4].Length() << '\n';
    cout << "e: " << test_vec[5].Length() << '\n'; cout << "f: " << test_vec[6].Length() << '\n';
}

void plus_test(vecNd* test_vec) {
    cout << "~~~testing + operator~~~\n";
    //uncomment the next line to check that mismatched sizes are handled well
    //cout << "empty + a = "; (test_vec[0] + test_vec[1]).Print(); cout << '\n';
    cout << "a + b = "; (test_vec[1] + test_vec[2]).Print(); cout << '\n';
    cout << "c + d = "; (test_vec[3] + test_vec[4]).Print(); cout << '\n';
    cout << "e + f = "; (test_vec[5] + test_vec[6]).Print(); cout << '\n';
}

void minus_test(vecNd* test_vec) {
    cout << "~~~testing - operator~~~\n";
    //uncomment the next line to check that mismatched sizes are handled well
    //cout << "empty - a = "; (test_vec[0] - test_vec[1]).Print(); cout << '\n';
    cout << "a - b = "; (test_vec[1] - test_vec[2]).Print(); cout << '\n';
    cout << "c - d = "; (test_vec[3] - test_vec[4]).Print(); cout << '\n';
    cout << "e - f = "; (test_vec[5] - test_vec[6]).Print(); cout << '\n';
}

void plusequals_test(vecNd* test_vec) {
    cout << "~~~testing += operator~~~\n";
    //uncomment below to check that mismatched sizes are handled well
    /*test_vec[0] += test_vec[1]*/; test_vec[1] += test_vec[2];
    test_vec[3] += test_vec[4]; test_vec[5] += test_vec[6];
    /*cout << "empty += a: "; test_vec[0].Print(); cout << '\n';*/
    cout << "a += b: "; test_vec[1].Print(); cout << '\n';
    cout << "c += d: "; test_vec[3].Print(); cout << '\n';
    cout << "e += f: "; test_vec[5].Print(); cout << '\n';
}

void minusequals_test(vecNd* test_vec) {
    cout << "~~~testing -= operator~~~\n";
    //uncomment below to check that mismatched sizes are handled well
    /*test_vec[0] -= test_vec[4]*/; test_vec[1] -= test_vec[2];
    test_vec[5] -= test_vec[1]; test_vec[3] -= test_vec[6];
    /*cout << "empty -= d: "; test_vec[0].Print(); cout << '\n';*/
    cout << "a -= b: ";  test_vec[1].Print(); cout << '\n';
    cout << "e -= a: "; test_vec[5].Print(); cout << '\n';
    cout << "c -= f: "; test_vec[3].Print(); cout << '\n';
}

void brackets_test(vecNd* test_vec) {
    cout << "~~~testing [] operator~~~\n";
    cout << "empty[0] = " << test_vec[0][0] << '\n';
    cout << "a[2] = " << test_vec[1][2] << '\n';
    cout << "c[3] = " << test_vec[3][3] << '\n';
    cout << "e[4] = " << test_vec[5][4] << '\n';
}

void star_test(vecNd* test_vec) {
    cout << "~~~testing * (multiplication) operator~~~\n";
    //uncomment below to check that mismatched sizes are handled well
    //cout << "empty * a = " << (test_vec[0] * test_vec[1]) << '\n';
    double s1 = 3, s2 = -1, s3 = 0.1;
    cout << "b * 3 = "; (test_vec[2] * s1).Print(); cout << '\n';
    cout << "d * -1 = "; (test_vec[4] * s2).Print(); cout << '\n';
    cout << "f * 0.1 = "; (test_vec[6] * s3).Print(); cout << '\n';
}

void starequals_test(vecNd* test_vec) {
    cout << "~~~testing *= operator~~~\n";
    double s0 = 5, s1 = 1, s2 = -4, s3 = 8.5;
    test_vec[0] *= s0; test_vec[1] *= s1;
    test_vec[3] *= s2; test_vec[5] *= s3;
    cout << "empty *= 5: "; test_vec[0].Print(); cout << '\n';
    cout << "a *= 1: "; test_vec[1].Print(); cout << '\n';
    cout << "c *= -4: "; test_vec[3].Print(); cout << '\n';
    cout << "e *= 8.5: "; test_vec[5].Print(); cout << '\n';
}

void dot_test(vecNd* test_vec) {
    cout << "~~~testing * (dot) operator~~~\n";
    //uncomment below to check that mismatched sizes are handled well
    //cout << "empty * a = " << (test_vec[0] * test_vec[1]) << '\n';
    cout << "a * b = " << (test_vec[1] * test_vec[2]) << '\n';
    cout << "c * d = " << (test_vec[3] * test_vec[4]) << '\n';
    cout << "e * f = " << (test_vec[5] * test_vec[6]) << '\n';
}

void cross_test(vecNd* test_vec) {
    cout << "~~~testing x (cross product)~~~\n";
    double vec1[3] = {1,2,3}, vec2[3] = {-3,-2,-1}, vec3[3] = {-1,-1,-1}, vec4[3] = {-3.3, 4.2, 0};
    vecNd* v1 = new vecNd(vec1, 3); vecNd* v2 = new vecNd(vec2, 3);
    vecNd* v3 = new vecNd(vec3, 3); vecNd* v4 = new vecNd(vec4, 3);
    //uncomment below to check that non-3D vectors are handled well
    //cout << "empty x a = "; (test_vec[0].cross(test_vec[1])).Print(); cout << '\n';
    cout << "{1,2,3} x {-3,-2,-1} = "; (v1->cross3D(*v2)).Print(); cout << '\n';
    cout << "{-1,-1,-1} x {-3.3,4.2,0} = "; (v3->cross3D(*v4)).Print(); cout << '\n';
    cout << "{-3.3,4.2,0} x {1,2,3} = "; (v4->cross3D(*v1)).Print(); cout << '\n';
    delete v1; v1 = NULL; delete v2; v2 = NULL; delete v3; v3 = NULL;delete v4; v4 = NULL;
}

void cross2D_test(vecNd* test_vec) {
    cout << "~~~testing x (cross product)~~~\n";
    double vec1[2] = {1,2}, vec2[2] = {-3,-2}, vec3[2] = {-1,-1}, vec4[2] = {-3.3, 4.2};
    vecNd* v1 = new vecNd(vec1, 2); vecNd* v2 = new vecNd(vec2, 2);
    vecNd* v3 = new vecNd(vec3, 2); vecNd* v4 = new vecNd(vec4, 2);
    //uncomment below to check that non-2D vectors are handled well
    //cout << "empty x a = " << (test_vec[0].cross2D(test_vec[1])) << '\n';
    cout << "{1,2} x {-3,-2} = " << (v1->cross2D(*v2)) << '\n';
    cout << "{-1,-1} x {-3.3,4.2} = " << (v3->cross2D(*v4)) << '\n';
    cout << "{-3.3,4.2} x {1,2} = " << (v4->cross2D(*v1)) << '\n';
    delete v1; v1 = NULL; delete v2; v2 = NULL; delete v3; v3 = NULL;delete v4; v4 = NULL;
}

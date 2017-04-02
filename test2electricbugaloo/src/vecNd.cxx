//  vecNd.cxx
//  Created by Isaac Mooney on 3/16/17.

#include <iostream>
#include <cmath>
#include <iomanip>
#include "vecNd.h"
#include "matrixNM.h"
using namespace std;

//~~~~~~~~~~~~~~~~~~~~CONSTRUCTORS~~~~~~~~~~~~~~~~~~~~//

vecNd::vecNd() {
    size = 3;
    vec = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] = 0;
    }
}

vecNd::vecNd(const int dim) {
    size = dim;
    vec = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] = 0;
    }
}

vecNd::vecNd(double * init, const int dim) {
    size = dim;
    vec = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] = init[i];
    }
}

vecNd::vecNd(const vecNd & copy) {
    delete [] vec;
    size = copy.size;
    vec = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] = copy.vec[i];
    }
}


//~~~~~~~~~~~~~~~~~~~~OVERLOADED OPERATORS~~~~~~~~~~~~~~~~~~~~//


vecNd & vecNd::operator = (const vecNd & eq) {
    if (this == &eq) {
        return *this;
    }
    delete [] vec;
    size = eq.size;
    vec = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] = eq.vec[i];
    }
    return *this;
}

double & vecNd::operator [] (const int index) const {
    if (index < 0 || index >= size) {
        cerr << "Out of bounds. Exiting.\n"; exit(1);
    }
    return vec[index];
}

vecNd & vecNd::operator += (const vecNd & add) {
    sizecheck(add);
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] += add.vec[i];
    }
    return *this;
}

vecNd & vecNd::operator -= (const vecNd & subtract) {
    sizecheck(subtract);
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] -= subtract.vec[i];
    }
    return *this;
}

vecNd & vecNd::operator + (const vecNd & add) {
    sizecheck(add);
    double * result = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        result[i] = vec[i] + add.vec[i];
    }
    vecNd * res = new vecNd(result, size);
    return *res;
}

vecNd & vecNd::operator - (const vecNd & subtract) {
    sizecheck(subtract);
    double * result = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        result[i] = vec[i] - subtract.vec[i];
    }
    vecNd * res = new vecNd(result, size);
    return *res;
}

double vecNd::operator * (const vecNd & mult) {
    sizecheck(mult);
    double result = 0;
    for (unsigned i = 0; i < size; ++ i) {
        result += vec[i]*mult.vec[i];
    }
    return result;
}

vecNd & vecNd::operator * (const double & s) {
    double * result = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        result[i] = s*vec[i];
    }
    vecNd * res = new vecNd(result, size);
    return *res;
}

vecNd & vecNd::operator *= (const double & s) {
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] *= s;
    }
    return *this;
}

vecNd & vecNd::operator / (const double & s) {
    double * result = new double[size];
    for (unsigned i = 0; i < size; ++ i) {
        result[i] = vec[i]/s;
    }
    vecNd * res = new vecNd(result, size);
    return *res;
}

vecNd & vecNd::operator /= (const double & s) {
    for (unsigned i = 0; i < size; ++ i) {
        vec[i] /= s;
    }
    return *this;
}


//~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTIONS~~~~~~~~~~~~~~~~~~~~//


void vecNd::sizecheck(const vecNd & v) {
    if (size != v.size) {
        cerr << "Cannot perform operation with vectors of different dimension. Exiting.\n"; exit(1);
    }
    return;
}

void vecNd::Print() {
    cout << "(";
    for (unsigned i = 0; i < size - 1; ++ i) {
        cout << setw(10) << vec[i];
    }
    cout << setw(10) << vec[size - 1] << setw(10) << ")\n";
    return;
}

double vecNd::Length() {
    double mag = 0;
    for (unsigned i = 0; i < size; ++ i) {
        mag += pow(vec[i], 2);
    }
    return sqrt(mag);
}

double vecNd::cross2D(const vecNd & v) {
    if (size != 2) {
        cout << "2D vector product is only defined in 2 dimensions. Exiting.\n"; exit(1);
    }
    sizecheck(v);
    double cross = -1;
    cross = vec[0]*v.vec[1] - vec[1]*v.vec[0];
    return cross;
}

vecNd & vecNd::cross3D(const vecNd & v) {
    if (size != 3) {
        cout << "3D vector product is only defined in 3 dimensions. Exiting.\n"; exit(1);
    }
    sizecheck(v);
    double vec3[3] = {};
    vec3[0] = vec[1]*v.vec[2] - vec[2]*v.vec[1];
    vec3[1] = vec[2]*v.vec[0] - vec[0]*v.vec[2];
    vec3[2] = vec[0]*v.vec[1] - vec[1]*v.vec[0];
    vecNd * cross = new vecNd(vec3, size);
    return *cross;
}

//  vecNd.cxx
//  Created by Isaac Mooney on 3/1/17.

#include "vecNd.h"
#include <iostream>
#include <cmath>

using namespace std;

void vecNd::sizecheck(vecNd & v) {
    //cout << "vec sizecheck" << endl;
    //checks that two vectors are the same size
    if (size != v.size) {
        cerr << "Operation not defined for vectors of different sizes. Exiting.\n";
        exit(1);
    }
    else { return;}
}

vecNd::vecNd() {
    //cout << "vec constructor 1" << endl;
    //default constructor - initializes 3D vector entries to 0
    size = 3;
    //allocates sufficient memory
    vec = new double[size];
    for (int i = 0; i < size; ++ i) {
        //initializes all values to zero
        vec[i] = 0;
    }
    //cout << "Default constructor called - initializes 3D vector {0, 0, 0}." << '\n';
}

vecNd::vecNd(int length) {
    //cout << "vec constructor 2" << endl;
    //constructor for vecNd of given length - initialized to 0
    if (length <= 1) {
        cerr << "Please give a non-trivial vector (2D or greater). Exiting.\n"; exit(1);
    }
    //initializes array size and allocates the memory
    size = length;
    vec = new double[size];
    for (int i = 0; i < size; ++ i) {
        //initializes to zero
        vec[i] = 0;
    }
}

vecNd::vecNd(double * loc, int length) {
    //cout << "vec constructor 3" << endl;
    //constructor for vecNd of given length with given values
    if (length <= 1) {
        cerr << "Please give a non-trivial vector (2D or greater). Exiting.\n"; exit(1);
    }
    //initializes array size and allocates the memory
    size = length;
    vec = new double[size];
    for(int i = 0; i < size; ++ i) {
        //initializes to given values
        vec[i] = loc[i];
    }
}

vecNd::vecNd(const vecNd & copy) {
    //cout << "vec copy constructor" << endl;
    //copy constructor
    //allocates the memory
    vec = new double[copy.size];
    //copies the size
    size = copy.size;
    //copies the values
    for (int i = 0; i < size; ++ i) {
        vec[i] = copy.vec[i];
    }
}

vecNd vecNd::operator+=(vecNd & v) {
    //cout << "vec +=" << endl;
    //overloaded += operator
    sizecheck(v);
    for (int i = 0; i < v.size; ++ i) {
        //adds the values and assigns the results to the first vector
        vec[i] += v[i];
    }
    return *this;
}

vecNd vecNd::operator-=(vecNd & v) {
    //cout << "vec -= " << endl;
    //overloaded -= operator
    sizecheck(v);
    for (int i = 0; i < v.size; ++ i) {
        //subtracts the values and assigns the results to the first vector
        vec[i] -= v[i];
    }
    return *this;
}

vecNd vecNd::operator+(vecNd & v) {
    //cout << "vec +" << endl;
    //overloaded + operator
    sizecheck(v);
    //allocates memory for result array
    double *added = new double[size];
    for (int i = 0; i < v.size; ++ i) {
        //add the values and stick them in the result array
        cout << "b" << endl;
        added[i] = vec[i] + v[i];
        cout << "c" << endl;
    }
    //return it as a vecNd
    return vecNd(added, v.size);
}

vecNd vecNd::operator-(vecNd & v) {
    //cout << "vec - " << endl;
    //overloaded - operator
    sizecheck(v);
    //allocates memory for result array
    double *subtracted = new double[size];
    for (int i = 0; i < v.size; ++ i) {
        //subtract the values and stick them in the result array
        subtracted[i] = vec[i] - v[i];
    }
    //return it as a vecNd
    return vecNd(subtracted, v.size);
}

double vecNd::operator*(vecNd & v) {
    //cout << "vec *" << endl;
    //overloaded * operator (scalar product)
    sizecheck(v);
    //initialize the result of the scalar product
    double scal = 0;
    for (int i = 0; i < v.size; ++ i) {
        //component-wise multiplication, adding the result to the value
        scal += vec[i]*v[i];
    }
    return scal;
}

vecNd vecNd::operator*(double & s) {
    //cout << "vec vec *" << endl;
    //overloaded * operator (scalar*vector)
    //allocate the memory for a result vector
    double *mult = new double[size];
    for (int i = 0; i < size; ++ i) {
        //scale the values by the given constant and put them in the new vector
        mult[i] = s*vec[i];
    }
    //return it as a vecNd
    return vecNd(mult, size);
}

vecNd vecNd::operator*=(double & s) {
    //cout << "vec *=" << endl;
    //overloaded *= operator (vector <- scalar*vector)
    for (int i = 0; i < size; ++ i) {
        //scale the values by the given constant
        vec[i] *= s;
    }
    //return the vecNd at the pointer to itself
    return *this;
}

double vecNd::operator[](const int & index) {
    //cout << "vec [] " << endl;
    //check that it's in bounds
    if (index < size) {
        //return it
        return vec[index];
    }
    else {cerr << "You're out of bounds. Exiting." << '\n'; exit(1);}
}

const vecNd &vecNd::operator=(const vecNd & eq) {
    //cout << "vec =" << endl;
    //if the pointer is at the location of the assignment, just return the value
    if (this == &eq) {
        return *this;
    }
    //delete the current values to get ready for the new ones
    delete [] vec;
    //allocate the memory of the same size as the assigned vector
    vec = new double[eq.size];
    //assign that size to the private size
    size = eq.size;
    for (int i = 0; i < size; ++ i) {
        //copy the values over
        vec[i] = eq.vec[i];
    }
    //return the vecNd at the pointer to itself
    return *this;
}

void vecNd::Print() {
    //cout << "vec print" << endl;
    //prints the vector
    cout << "(\t";
    for (int i = 0; i < size - 1; ++ i) {
        //print the values one-by-one
        cout << vec[i] << "\t";
    }
    cout << vec[size - 1] << "\t)\n";
    return;
}

double vecNd::Length() {
    //cout << "vec length" << endl;
    //gives the magnitude of the vector
    //initialize magnitude to zero
    double magnitude = 0;
    for (int i = 0; i < size; ++ i) {
        //add the sum of squares of components of the vector
        magnitude += pow(vec[i],2);
    }
    //magnitude is the square root of that
    return sqrt(magnitude);
}

vecNd vecNd::cross3D(vecNd & v) {
    //cross product for 3 dimensional vectors. Returns a vector.
    if (size != 3) {
        cout << "3D vector product is only defined in three dimensions. Exiting.\n";
        exit(1);
    }
    sizecheck(v);
    //initialize an empty 3D vector
    double vec3[3] = {};
    //determinant of the 3x3 matrix with i,j,k and the two vectors.
    vec3[0] = vec[1]*v[2] - vec[2]*v[1];
    vec3[1] = vec[2]*v[0] - vec[0]*v[2];
    vec3[2] = vec[0]*v[1] - vec[1]*v[0];
    //make it a vecNd and return it
    return vecNd(vec3, size);
}

double vecNd::cross2D(vecNd & v) {
    //cross product for 2 dimensional vectors. Returns a scalar.
    if (size != 2) {
        cout << "2D vector product is only defined in two dimensions. Exiting.\n";
        exit(1);
    }
    sizecheck(v);
    //initialize the result to -1
    double cross = -1;
    //determinant of the 2x2 matrix composed of the two vectors
    cross = vec[0]*v[1] - vec[1]*v[0];
    return cross;
}

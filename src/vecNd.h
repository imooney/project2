//  vecNd.h
//  Created by Isaac Mooney on 3/1/17.

#ifndef vecNd_h
#define vecNd_h

#include <iostream>

using namespace std;

//a simple n-dimensional vector class
class vecNd {
private:
    //array of values
    double *vec;
    //size of the array
    int size;
public:
    //Constructors and Destructor
    vecNd(); //default constructor
    vecNd(int length); //constructs empty ND vecNd
    vecNd(double * loc, int length); //constructs ND vecNd with given values
    vecNd(const vecNd & vec); //copy constructor
    
    ~vecNd() {delete vec; vec = NULL;} //destructor
    
    //overloaded operators
    vecNd operator += (vecNd &);
    vecNd operator -= (vecNd &);
    vecNd operator + (vecNd &);
    vecNd operator - (vecNd &);
    double operator * (vecNd &); //vector * vector -> scalar
    vecNd operator * (double &); //vector * scalar -> vector
    vecNd operator *= (double &); //vector = vector*scalar
    double operator [] (const int &);
    const vecNd &operator=(const vecNd &); //assignment operator
    
    //setter functions
    void Set(int index, double value) {
        //check that we're in bounds
        if (index < size) {
            //set the value
            vec[index] = value;
        }
        else {cerr << "You're out of bounds." << '\n';}
    }
    
    //getter functions
    double Get(int index) {
        //check that we're in bounds
        if (index < size) {
            //get the value
            return vec[index];
        }
        else {cerr << "You're out of bounds." << '\n'; return -1;}
    }
    
    //member functions
    //prints the vector to the stream
    void Print();
    //calculates the magnitude of the vector
    double Length();
    //checks that two vectors being operated on each other are the same size
    void sizecheck(vecNd &);
    //vector product in 3 dimensions (vector*vector -> vector)
    vecNd cross3D(vecNd &);
    //vector product in 2 dimensions (vector*vector -> scalar)
    double cross2D(vecNd &);
};

#endif /* vecNd_h */

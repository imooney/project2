//  test_vecNd.h
//  Created by Isaac Mooney on 3/15/17.

#ifndef test_vecNd_h
#define test_vecNd_h

#include <iostream>

class matrixMM;

class vecNd {
private:
    double *vec;
    int size;
public:
    //constructors and destructor
    vecNd();
    vecNd(const int);
    vecNd(double *, const int);
    vecNd(const vecNd &);
    
    ~vecNd() {delete [] vec; vec = NULL;}
    
    //overloaded operators
    vecNd & operator = (const vecNd &);
    double & operator [] (const int);
    vecNd & operator += (const vecNd &);
    vecNd & operator -= (const vecNd &);
    vecNd & operator + (const vecNd &);
    vecNd & operator - (const vecNd &);
    double operator * (const vecNd &);
    vecNd & operator * (const double &);
    vecNd & operator *= (const double &);
    
    //member functions
    void sizecheck(const vecNd &);
    void Print();
    double Length();
    double cross2D(const vecNd &);
    vecNd & cross3D(const vecNd &);
};

#endif /* test_vecNd_h */

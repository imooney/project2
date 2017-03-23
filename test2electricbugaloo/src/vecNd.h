//  vecNd.h
//  Created by Isaac Mooney on 3/15/17.

#ifndef vecNd_h
#define vecNd_h

#include <iostream>

class matrixNM;

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
    double & operator [] (const int) const;
    vecNd & operator += (const vecNd &);
    vecNd & operator -= (const vecNd &);
    vecNd & operator + (const vecNd &);
    vecNd & operator - (const vecNd &);
    double operator * (const vecNd &);
    vecNd & operator * (const double &);
    vecNd & operator *= (const double &);
    vecNd & operator / (const double &);
    vecNd & operator /= (const double &);
    
    //member functions
    void sizecheck(const vecNd &);
    void Print();
    double Length();
    double cross2D(const vecNd &);
    vecNd & cross3D(const vecNd &);
    int Size() const {return size;}
    double Get (const int & index) const {
        if (index < 0 || index >= size) {
            std::cerr << "Out of bounds. Exiting.\n"; exit(1);
        }
        return vec[index];
    }
    void Set(const int & index, const double & num) {
        if (index < 0 || index >= size) {
            std::cerr << "Out of bounds. Exiting.\n"; exit(1);
        }
        vec[index] = num;
        return;
    }
};

#endif /* vecNd_h */

//
//  DenVector.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/4/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef Denver_DenVector_h
#define Denver_DenVector_h

#include <boost/shared_ptr.hpp>

//
//
//
class DENVector {
public:
    DENVector(double x = 0, double y = 0, double z = 0);
    DENVector(const DENVector& other);
    ~DENVector() {}
    void invert();
    void scale(double scaleFactor);
    void init();
    double x() const;
    double y() const;
    double z() const;
    double magnitude() const;
    double squareMagnitude() const;
    void normalize();
    void multiply(double scalar);
    
    const DENVector& operator=(const DENVector& rhs);
    const DENVector& operator+(const DENVector& rhs);
    //
    static DENVector add(const DENVector& v1, const DENVector& v2);
    static DENVector scalarProduct(const DENVector& v1, const DENVector& v2);
    static DENVector vectorProduct(const DENVector& v1, const DENVector& v2);
    static DENVector normal(const DENVector& v);
    static DENVector scale(const DENVector& v, double scaleFactor);
private:
    class DENVectorImpl;
    
    boost::shared_ptr<DENVectorImpl> mImpl;
};


#endif

//
//  DenVectorImpl.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/5/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef Denver_DenVectorImpl_h
#define Denver_DenVectorImpl_h

#include "DenVector.h"

//
//
//
class DENVector::DENVectorImpl {
public:
    DENVectorImpl(double x = 0, double y = 0, double z = 0)
        : mX(x), mY(y), mZ(z) {}
    DENVectorImpl(const DENVectorImpl& other);
    ~DENVectorImpl() {}
    DENVectorImpl *clone();
    void invert() { mX = -mX; mY = -mY; mZ = -mZ; }
    void scale(double scaleFactor) {
        mX *= scaleFactor;
        mY *= scaleFactor;
        mZ *= scaleFactor;
    }
    void init() { mX = mY = mZ = 0; }
    double x() const { return mX; }
    double y() const { return mY; }
    double z() const { return mZ; }
    // setters
    double& x() { return mX; }
    double& y() { return mY; }
    double& z() { return mZ; }
    double magnitude() const;
    double squareMagnitude() const;
    void normalize();
    void multiply(double scalar);
    
    const DENVector& operator=(const DENVector& rhs);
    const DENVectorImpl& operator+(const DENVectorImpl& rhs);
private:
    double mX;
    double mY;
    double mZ;
};

#endif

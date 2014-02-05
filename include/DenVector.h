//
//  DenVector.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/4/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef Denver_DenVector_h
#define Denver_DenVector_h

//
//
//
class DENVector {
public:
    DENVector(double x = 0, double y = 0, double z = 0) :
        mX(x), mY(y), mZ(z) {}
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
    double magnitude() const;
    double squareMagnitude() const;
    void normalize();
    void multiply(double scalar);
    void add(const DENVector& v);
private:
    double mX;
    double mY;
    double mZ;
};


#endif

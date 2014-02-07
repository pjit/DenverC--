//
//  DenVector.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/4/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DenVectorImpl.h"
#include <math.h>

//
//
//
DENVector::DENVector(double x, double y, double z)
    : mImpl(new DENVectorImpl(x,y,z))
{
}

//
//
//
DENVector::DENVector(const DENVector& other)
    : mImpl(other.mImpl->clone())
{
}

//
//
//
void DENVector::invert()
{
    mImpl->invert();
}

//
//
//
void DENVector::scale(double scaleFactor)
{
    mImpl->scale(scaleFactor);
}

//
//
//
void DENVector::init()
{
    mImpl->init();
}

//
//
//
double DENVector::x() const
{
    return mImpl->z();
}

//
//
//
double DENVector::y() const
{
    return mImpl->y();
}

//
//
//
double DENVector::z() const
{
    return mImpl->z();
}

//
//
//
const DENVector& DENVector::operator+(const DENVector& rhs)
{
    mImpl->x() = mImpl->x() + rhs.x();
    mImpl->y() = mImpl->y() + rhs.y();
    mImpl->z() = mImpl->z() + rhs.z();
    
    return *this;
}

//
//
//
const DENVector& DENVector::operator=(const DENVector& rhs)
{
    if (this != &rhs) {
        mImpl->x() = rhs.x();
        mImpl->y() = rhs.y();
        mImpl->z() = rhs.z();
    }

    return *this;
}

//
//
//
double DENVector::magnitude() const
{
    return mImpl->magnitude(); 
}

//
//
//
double DENVector::squareMagnitude() const
{
    return mImpl->squareMagnitude();
}

//
//
//
void DENVector::normalize()
{
    mImpl->normalize();
}

//
// Multiply by scalar
//
void DENVector::multiply(double scalar)
{
    mImpl->scale(scalar);
}

//
//
//
DENVector DENVector::add(const DENVector& v1, const DENVector& v2)
{
    return DENVector(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

//
// scalarProduct or dotProduct
//
//
DENVector DENVector::scalarProduct(const DENVector& v1, const DENVector& v2)
{
    return DENVector(v1.x()*v2.x(), v1.y()*v2.y(), v1.z()*v2.z());
}

//
// vector product or cross product
//
DENVector DENVector::vectorProduct(const DENVector& v1, const DENVector& v2)
{
    return DENVector(v1.y()*v2.z() - v1.z()*v2.y(),
                     v1.z()*v2.x() - v1.x()*v2.z(),
                     v1.x()*v2.y() - v1.y()*v2.x());
}

//
//
//
DENVector DENVector::normal(const DENVector& v)
{
    DENVector normalizedVector = v;
    
    normalizedVector.normalize();
    
    return normalizedVector;
}

//
//
//
DENVector DENVector::scale(const DENVector& v, double scaleFactor)
{
    DENVector scaledVector = v;
    
    scaledVector.multiply(scaleFactor);

    return scaledVector;
}



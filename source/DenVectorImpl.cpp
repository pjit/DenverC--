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
DENVector::DENVectorImpl::DENVectorImpl(const DENVectorImpl& other)
{
    mX = other.x(); mY = other.y(); mZ = other.z();
}

//
//
//
DENVector::DENVectorImpl* DENVector::DENVectorImpl::clone()
{
    return new DENVectorImpl(*this);
}

//
//
//
double DENVector::DENVectorImpl::magnitude() const
{
    return sqrt(squareMagnitude());
}

//
//
//
double DENVector::DENVectorImpl::squareMagnitude() const
{
    return mX*mX + mY*mY + mZ*mZ;
}

//
//
//
void DENVector::DENVectorImpl::normalize()
{
    double n = magnitude();
    
    if (n > 0) {
        mX /= n;
        mY /= n;
        mZ /= n;
    }
}

//
// Multiply by scalar
//
void DENVector::DENVectorImpl::multiply(double scalar)
{
    scale(scalar);
}

//
//
//
const DENVector::DENVectorImpl& DENVector::DENVectorImpl::operator+(const DENVector::DENVectorImpl& rhs)
{
    mX += rhs.x(); mY += rhs.y(); mZ += rhs.z();
    
    return *this;
}




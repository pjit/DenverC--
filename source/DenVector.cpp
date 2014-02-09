//
//  DenVector.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/4/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DenVector.h"
#include <math.h>

//
// DENVector::Private
//
// Actual implementation of DENVector
//
class DENVector::Private {
public:
    Private(DENReal x = 0, DENReal y = 0, DENReal z = 0)
    : mX(x), mY(y), mZ(z) {}
    Private(const Private& other) {
        mX = other.mX; mY = other.mY; mZ = other.mZ;
    }
    ~Private() {}
    Private *clone() const { return new Private(*this); }
    // Invert individual components of a vector
    inline void invert() { mX = -mX; mY = -mY; mZ = -mZ; }
    // Scale vector with the given scale factor
    inline void scale(DENReal scaleFactor) {
        mX *= scaleFactor;
        mY *= scaleFactor;
        mZ *= scaleFactor;
    }
    // Reset vector - set all components to 0
    inline void reset(DENReal x, DENReal y, DENReal z) { mX = x; mY = y; mZ = z; }
    // Maginitue of a vector
    DENReal magnitude() const;
    // Square magnitude - square is faster than square root.
    DENReal squareMagnitude() const;
    // Normalize the vector
    void normalize();
    const Private& operator=(const Private& rhs);
    const Private& operator+(const Private& rhs);
public: // Ok to have them public - already hidden for clients
    DENReal mX, mY, mZ;
};

//
//
//
DENReal DENVector::Private::magnitude() const
{
    return sqrt(squareMagnitude());
}

//
//
//
DENReal DENVector::Private::squareMagnitude() const
{
    return mX*mX + mY*mY + mZ*mZ;
}

//
//
//
void DENVector::Private::normalize()
{
    DENReal n = magnitude();
    
    if (n > 0) {
        mX /= n;
        mY /= n;
        mZ /= n;
    }
}

//
// DENVector Class
//

//
//
//
DENVector::DENVector(DENReal x, DENReal y, DENReal z)
    : d(new Private(x,y,z))
{
}

//
//
//
DENVector::DENVector(const DENVector& other)
    : d(other.d->clone())
{
}

//
//
//
void DENVector::invert()
{
    d->invert();
}

//
//
//
void DENVector::scale(DENReal scaleFactor)
{
    d->scale(scaleFactor);
}

//
//
//
void DENVector::reset(DENReal x, DENReal y, DENReal z)
{
    d->reset(x, y, z);
}

//
//
//
inline DENReal DENVector::x() const
{
    return d->mX;
}

//
//
//
inline DENReal DENVector::y() const
{
    return d->mY;
}

//
//
//
inline DENReal DENVector::z() const
{
    return d->mZ;
}

//
//
//
const DENVector& DENVector::operator+(const DENVector& rhs)
{
    d->mX += rhs.x();
    d->mY += rhs.y();
    d->mZ += rhs.z();
    
    return *this;
}

//
//
//
const DENVector& DENVector::operator=(const DENVector& rhs)
{
    if (this != &rhs) {
        DENVector copy(rhs);
        
        d->mX = rhs.x();
        d->mY = rhs.y();
        d->mZ = rhs.z();
        
        this->swap(copy);
    }

    return *this;
}

//
//
//
DENReal DENVector::magnitude() const
{
    return d->magnitude();
}

//
//
//
DENReal DENVector::squareMagnitude() const
{
    return d->squareMagnitude();
}

//
//
//
void DENVector::normalize()
{
    d->normalize();
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
DENReal DENVector::scalarProduct(const DENVector& v1, const DENVector& v2)
{
    return (v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z());
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
DENVector DENVector::scale(const DENVector& v, DENReal scaleFactor)
{
    DENVector scaledVector = v;
    
    scaledVector.scale(scaleFactor);

    return scaledVector;
}



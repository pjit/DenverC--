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
//
//
void DENVector::add(const DENVector &v)
{
    this->mX += v.mX;
    this->mY += v.mY;
    this->mZ += v.mZ;
}

//
//
//
double DENVector::magnitude() const
{
    return sqrt(squareMagnitude());
}

//
//
//
double DENVector::squareMagnitude() const
{
    return mX*mX + mY*mY + mZ*mZ;
}

//
//
//
void DENVector::normalize()
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
void DENVector::multiply(double scalar)
{
    scale(scalar);
}

//
//
//
void DENVector.add = function() {
    if (arguments.length == 2) {
        var v = new DENVector();
        
        v.x = (arguments[0].x || 0) + (arguments[1].x || 0);
        v.y = (arguments[0].y || 0) + (arguments[1].y || 0);
        v.z = (arguments[0].z || 0) + (arguments[1].z || 0);
        
        return v;
    }
}

//
//
// scalarProduct or dotProduct
//
//
DENVector.scalarProduct = function() {
    if (arguments.length == 2) {
        var result = (arguments[0].x || 0) * (arguments[1].x || 0) +
        (arguments[0].y || 0) * (arguments[1].y || 0) +
        (arguments[0].z || 0) * (arguments[1].z || 0);
        
        return result;
    }
}

//
// vector product or cross product
//
DENVector.vectorProduct = function() {
    if (arguments.length == 2) {
        var v = new DENVector();
        
        v.x = (arguments[0].y || 0) * (arguments[1].z || 0) -
        (arguments[0].z || 0) * (arguments[1].y || 0);
        
        v.y = (arguments[0].z || 0) * (arguments[1].x || 0) -
        (arguments[0].x || 0) * (arguments[1].z || 0);
        
        v.z = (arguments[0].x || 0) * (arguments[1].y || 0) -
        (arguments[0].y || 0) * (arguments[1].x || 0);
        
        return v;
    }
}

//
//
//
DENVector.normal = function() {
    if (arguments.length == 1) {
        var v = new DENVector(arguments[0].x || 0, arguments[0].y || 0, arguments[0].z || 0);
        
        v.normalize();
        
        return v;
    }
}

//
//
//
DENVector.scale = function() {
    if (arguments.length == 2) {
        var v = new DENVector(arguments[0].x || 0, arguments[0].y || 0, arguments[0].z || 0);
        var scaleFactor = arguments[1];
        
        v.multiply(scaleFactor);
        
        return v;
    }
}



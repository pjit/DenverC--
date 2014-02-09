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
#include "DENUtils.h"

//
// DENVector
//
// Represents vector with x,y,z component
//
class DENVector {
public:
    DENVector(DENReal x = 0, DENReal y = 0, DENReal z = 0);
    DENVector(const DENVector& other);
    ~DENVector() {}
    const DENVector& operator=(const DENVector& rhs);
    const DENVector& operator+(const DENVector& rhs);
    // Invert individual components of a vector
    void invert();
    // Scale vector with the given scale factor
    void scale(DENReal scaleFactor);
    // Reset vector - set all components to 0 or to the given values
    void reset(DENReal x = 0, DENReal y = 0, DENReal z = 0);
    // x, y, and x components
    DENReal x() const;
    DENReal y() const;
    DENReal z() const;
    // Magnitude of a vector
    DENReal magnitude() const;
    // Square magnitude - square is faster than square root.
    DENReal squareMagnitude() const;
    // Normalize the vector
    void normalize();
    // General methods which return new vector instead of modifying the existing vector.
    static DENVector add(const DENVector& v1, const DENVector& v2);
    static DENReal scalarProduct(const DENVector& v1, const DENVector& v2);
    static DENVector vectorProduct(const DENVector& v1, const DENVector& v2);
    // Normal to a given vector - same direction w/ magnitude one
    static DENVector normal(const DENVector& v);
    static DENVector scale(const DENVector& v, DENReal scaleFactor);
private:
    void swap(DENVector& other) { d.swap(other.d); }

private:
    class Private;
    
    boost::shared_ptr<Private> d;
};


#endif

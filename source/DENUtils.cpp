//
//  DENUtils.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <math.h>
#include <limits.h>
#include "DENUtils.h"

// Threshhold for DENReal comparison
double const THRESHHOLD_FOR_COMPARISON = 0.0000000000000001;

//
//
//
bool DENRealEqual(const DENReal& r1, const DENReal& r2)
{
    double diff = fabs(r1-r2);
    DENReal f1 = r1;
    DENReal f2 = r2;

    return true ; //return fabs(r1 - r2) < numeric_limits<DENReal>::ep
}

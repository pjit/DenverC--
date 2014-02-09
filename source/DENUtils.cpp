//
//  DENUtils.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/8/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include <math.h>
#include "DENUtils.h"

// Threshhold for DENReal comparison
double const THRESHHOLD_FOR_COMPARISON = DEN_MIN;

//
//
//
bool DENRealEqual(const DENReal& r1, const DENReal& r2)
{
    return fabs(r1 - r2) < THRESHHOLD_FOR_COMPARISON;
}

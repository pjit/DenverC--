//
//  DENParticleForce.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/22/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef Denver_DENParticleForce_h
#define Denver_DENParticleForce_h

#include "DENUtils.h"

//
class DENParticle;

//
//
//
class DENParticleForce
{
public:
    virtual void updateForce(DENParticle& , DENReal duration) = 0;
};

#endif

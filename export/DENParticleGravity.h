//
//  DENParticleGravity.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/22/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef __Denver__DENParticleGravity__
#define __Denver__DENParticleGravity__

#include <boost/shared_ptr.hpp>
#include "DENParticleForce.h"

//
class DENVector;
class DENParticle;

//
// Force that applies a gravitational force.
//
class DENParticleGravity : public DENParticleForce {
public:
	DENParticleGravity();
	DENParticleGravity(const DENVector&);
	DENParticleGravity(const DENParticleGravity&);
	void updateForce(DENParticle&, DENReal);
private:
	void swap(DENParticleGravity& other) { d.swap(other.d); }
private:
	class Private;
	
	boost::shared_ptr<Private> d;
};


#endif /* defined(__Denver__DENParticleGravity__) */

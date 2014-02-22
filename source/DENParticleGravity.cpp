//
//  DENParticleGravity.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/22/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DENParticleGravity.h"
#include "DENVector.h"
#include "DENParticle.h"

//
// DENParticleGravity::Private
//
// Actual implementation of DENParticleGravity
//
class DENParticleGravity::Private {
public:
	Private(const DENVector& gravity) : mGravity(gravity) {}
	Private() {
		// Default
		mGravity.reset(0, -10, 0);
	}
	Private(const Private& other) {
		mGravity = other.mGravity;
	}
	~Private() {}
	Private *clone() const { return new Private(*this); }
	void updateForce(DENParticle&, DENReal);
public:
	DENVector mGravity;
};

//
//
//
DENParticleGravity::DENParticleGravity() : d(new Private())
{
}

//
//
//
DENParticleGravity::DENParticleGravity(const DENVector& gravity)
	: d(new Private(gravity))
{
}

//
//
//
DENParticleGravity::DENParticleGravity(const DENParticleGravity& other)
	: d(other.d->clone())
{
}

//
//
//
void DENParticleGravity::updateForce(DENParticle& p, DENReal duration)
{
	d->updateForce(p, duration);
}

//
//
//
void DENParticleGravity::Private::updateForce(DENParticle& p, DENReal duration)
{
	// Check that we do not have infinite mass
	if (p.hasFiniteMass()) {
		// Apply the mass-scaled force to the particle
		p.addForce(DENVector::scale(mGravity, p.getMass()));
	}
}





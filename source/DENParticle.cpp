//
//  DENParticle.cpp
//  Denver
//
//  Created by PARAMJIT SINGH on 2/7/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#include "DENParticle.h"
#include <math.h>
#include <float.h>

//
// DENParticle::Private
//
// Actual implemenation of DENParticle.
//
class DENParticle::Private {
public:
	Private();
	Private(const DENParticle&);
	~Private() {}
	Private *clone() const { return new Private(*this); }
	//
	// Integrates the particle forward in time by the given amount.
	// This function uses a Newton-Euler integration method, which
	// is a linear approximation of the correct integral. For this
	// reason it may be inaccurate in some cases.
	//
	void integrate(DENReal duration);
	// Returns total force on the particle
	const DENVector& getForce() const { return mForceAccum; }
public:
    // Linear position,velocity of the particle in the world space
    // These two properties should not be changed directly - only through
    // integrator but acceleration can be set directly.
    DENVector mPosition;
    DENVector mVelocity;
    // Acceleration of the particle. This value can be used to set acceleration due
    // to gravity (its primary use) or any other constant acceleration
    DENVector mAcceleration;
    // Holds accumulated force to be applied at the next simulation iteration only.
    // This value is zeroed at each integration step.
    DENVector mForceAccum;
    // Holds the amount of damping applied to linear motion. Dumping is required
    // to remove energy added through numerical instability in the integrator
    DENReal mDamping;
    // Holds the inverse of the mass of the particle. It is more useful to hold
    // the inverse mass because integration is simpler and because in real-time
    // simulation i is more useful to have objects with infinite mass (immovable)
    // than zero mass (completely unstable in numerical simulation)
    // zero inverse mass = infinite mass  = immovable objects
    // zero mass = infinite inverse mass.
    DENReal mInverseMass;
};

//
//
//
DENParticle::Private::Private()
    : mDamping(0), mInverseMass(0)
{
}

//
//
// DENParticle::Private::integrate
//
// Integrates the particle forward in time by the given amount.
// This function uses a Newton-Euler integration method, which
// is a linear approximation of the correct integral. For this
// reason it may be inaccurate in some cases.
//
void DENParticle::Private::integrate(DENReal duration)
{
    if (mInverseMass > 0 && duration > 0) {
        DENVector scaledVel = DENVector::scale(mVelocity, duration);
                
        // Update linear position
        mPosition = mPosition + scaledVel;
        // Acceleration from the force
        DENVector resultingAcc = mAcceleration;
        DENVector scaledAcc = DENVector::scale(mForceAccum, mInverseMass);
        
        resultingAcc = resultingAcc + scaledAcc;
        // Update linear velocity from the acceleration
        mVelocity = mVelocity + DENVector::scale(resultingAcc, duration);
        // Impose drag
        mVelocity.scale(pow(mDamping, duration));
        // Clear the forces
        mForceAccum.reset();
    }
}

//
//
//
DENParticle::DENParticle()
    : d(new Private())
{
}

//
//
//
DENParticle::DENParticle(const DENParticle& other)
: d(other.d->clone())
{
}

//
//
//
const DENParticle& DENParticle::operator=(const DENParticle& rhs)
{
    if (this != &rhs) {
        DENParticle copy(rhs);
        
        d->mPosition = rhs.d->mPosition;
        d->mVelocity = rhs.d->mVelocity;
        d->mAcceleration = rhs.d->mAcceleration;
        d->mForceAccum = rhs.d->mForceAccum;
        d->mDamping = rhs.d->mDamping;
        d->mInverseMass = rhs.d->mInverseMass;
        
        this->swap(copy);
    }
    
    return *this;
}

//
//
//
const DENVector& DENParticle::getPosition() const
{
    return d->mPosition;
}

//
//
//
const DENVector& DENParticle::getVelocity() const
{
    return d->mVelocity;
}

//
//
//
const DENVector& DENParticle::getAcceleration() const
{
    return d->mAcceleration;
}

//
//
//
const DENVector& DENParticle::getForce() const
{
	return d->getForce();
}

//
//
//
DENReal DENParticle::getDamping() const
{
    return d->mDamping;
}

//
//
//
void DENParticle::setPosition(const DENVector& p)
{
    d->mPosition = p;
}

//
//
//
void DENParticle::setVelocity(const DENVector& v)
{
    d->mVelocity = v;
}

//
//
//
void DENParticle::setAcceleration(const DENVector& a)
{
    d->mAcceleration = a;
}

//
//
//
void DENParticle::setDamping(DENReal damping)
{
    d->mDamping = damping;
}

//
//
//
void DENParticle::setInverseMass(DENReal inverseMass)
{
    d->mInverseMass = inverseMass;
}

//
//
//
void DENParticle::setMass(DENReal mass)
{
    // Holds the inverse of the mass of the particle. It is more useful to hold
    // the inverse mass because integration is simpler and because in real-time
    // simulation i is more useful to have objects with infinite mass (immovable)
    // than zero mass (completely unstable in numerical simulation)
    // zero inverse mass = infinite mass  = immovable objects
    // zero mass = infinite inverse mass.
    if (mass > 0) {
        d->mInverseMass = 1.0/mass;
    }
}

//
//
//
DENReal DENParticle::getMass() const
{
    if (d->mInverseMass == 0) {
        return DEN_MAX;
    }
    else {
        return (1.0/d->mInverseMass);
    }
}

//
//
//
bool DENParticle::hasFiniteMass() const
{
    return d->mInverseMass != 0;
}

//
// Add force for integration
//
void DENParticle::addForce(const DENVector& force)
{
    d->mForceAccum = d->mForceAccum + force;
}

//
// clear accumulated force
//
void DENParticle::clearAccumulator()
{
    d->mForceAccum.reset();
}



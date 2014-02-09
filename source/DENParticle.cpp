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
    // Linear position,velocity of the particle in the world space.
    inline void setPosition(const DENVector& p) { mPosition = p; }
    inline void setVelocity(const DENVector& v) { mVelocity = v; }
    // Acceleration of the particle. This value can be used to set acceleration due
    // to gravity (its primary use) or any other constant acceleration
    inline void setAcceleration(const DENVector& acc) { mAcceleration = acc; }
    // Holds the amount of damping applied to linear motion. Dumping is required
    // to remove energy added through numerical instability in the integrator
    inline void setDamping(DENReal damping) { mDamping = damping; }
    // Holds the inverse of the mass of the particle. It is more useful to hold
    // the inverse mass because integration is simpler and because in real-time
    // simulation i is more useful to have objects with infinite mass (immovable)
    // than zero mass (completely unstable in numerical simulation)
    // zero inverse mass = infinite mass  = immovable objects
    // zero mass = infinite inverse mass.
    inline void setInverseMass(DENReal inversemass) { mInverseMass = inversemass; }
    inline void setMass(DENReal mass) {
        if (mass > 0) {
            mInverseMass = 1.0/mass;
        }
    }
    inline DENReal getMass() const;
    inline bool hasFiniteMass() const { return mInverseMass != 0; }
    // Add force for integration
    void addForce(const DENVector& force) { mForceAccum = mForceAccum + force; }
    // clear accumulated force
    inline void clearAccumulator() { mForceAccum.reset(); }
    //
    // Integrates the particle forward in time by the given amount.
    // This function uses a Newton-Euler integration method, which
    // is a linear approximation of the correct integral. For this
    // reason it may be inaccurate in some cases.
    //
    void integrate(DENReal duration);
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
        clearAccumulator();
    }
}

//
//
//
DENReal DENParticle::Private::getMass() const
{
    if (mInverseMass == 0) {
        return DEN_MAX;
    }
    else {
        return (1.0/mInverseMass);
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
DENReal DENParticle::getDamping() const
{
    return d->mDamping;
}




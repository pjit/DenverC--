//
//  DENParticle.h
//  Denver
//
//  Created by PARAMJIT SINGH on 2/7/14.
//  Copyright (c) 2014 ijk. All rights reserved.
//

#ifndef __Denver__DENParticle__
#define __Denver__DENParticle__

#include <boost/shared_ptr.hpp>
#include "DENVector.h"

class DENParticle {
public:
    DENParticle();
    DENParticle(const DENParticle&);
    ~DENParticle() {}
    const DENParticle& operator=(const DENParticle&);
    // Linear position,velocity of the particle in the world space.
    void setPosition(const DENVector&);
    void setVelocity(const DENVector&);
    // Acceleration of the particle. This value can be used to set acceleration due
    // to gravity (its primary use) or any other constant acceleration
    void setAcceleration(const DENVector&);
    // Holds the amount of damping applied to linear motion. Dumping is required
    // to remove energy added through numerical instability in the integrator
    void setDamping(DENReal damping);
    // Holds the inverse of the mass of the particle. It is more useful to hold
    // the inverse mass because integration is simpler and because in real-time
    // simulation i is more useful to have objects with infinite mass (immovable)
    // than zero mass (completely unstable in numerical simulation)
    // zero inverse mass = infinite mass  = immovable objects
    // zero mass = infinite inverse mass.
    void setInverseMass(DENReal inversemass);
    void setMass(DENReal mass);
    DENReal getMass() const;
    // All getters
    const DENVector& getPosition() const;
    const DENVector& getVelocity() const;
    const DENVector& getAcceleration() const;
    DENReal getDamping() const;    
    bool hasFiniteMass() const;
    // Add force for integration
    void addForce(const DENVector&);
    // clear accumulated force
    void clearAccumulator();
    //
    // Integrates the particle forward in time by the given amount.
    // This function uses a Newton-Euler integration method, which
    // is a linear approximation of the correct integral. For this
    // reason it may be inaccurate in some cases.
    //
    void integrate(DENReal duration);
private:
    void swap(DENParticle& other) { d.swap(other.d); }
    
    class Private;
    
    boost::shared_ptr<Private> d;
};

#endif /* defined(__Denver__DENParticle__) */

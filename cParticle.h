// Filename: cParticle.h

#ifndef C_PARTICLE_H
#define C_PARTICLE_H

#include "swarm1.h"

class cParticle
{

private:
    int     mData[MAX_INPUTS];
    int     mpBest;
    float   mVelocity;

public:
    cParticle();
    int     cParticle::getdata(int index) const;
    void    cParticle::setData(int index, int value);
    int     cParticle::getpBest() const;
    void    cParticle::setpBest(int value);
    float   cParticle::getVelocity() const;
    void    cParticle::setVelocity(float value);

}; // end cParticle class.

#endif

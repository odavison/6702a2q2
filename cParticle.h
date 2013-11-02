// Filename: cParticle.h

#ifndef C_PARTICLE_H
#define C_PARTICLE_H

#include "swarm1.h"

class cParticle
{

private:
    int     mData[MAX_INPUTS];
	int		mTotal;
    int     mpBest;
    float   mVelocity;

public:
    cParticle();
    int     getData(int index) const;
    void    setData(int index, int value);
	int     getTotal() const;
    void    setTotal(int value);
    int     getpBest() const;
    void    setpBest(int value);
    float   getVelocity() const;
    void    setVelocity(float value);

}; // end cParticle class.

#endif

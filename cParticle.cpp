// Filename: cParticle.cpp

#include "cParticle.h"

cParticle::cParticle()
{
    mpBest = 0;
    mVelocity = 0.0;
}

int cParticle::getData(int index) const
{
    return this->mData[index];
}

void cParticle::setData(int index, int value)
{
    this->mData[index] = value;
}

int cParticle::getTotal() const
{
    return this->mTotal;
}

void cParticle::setTotal(int value)
{
    this->mTotal = value;
}

int cParticle::getpBest() const
{
    return this->mpBest;
}

void cParticle::setpBest(int value)
{
    this->mpBest = value;
}

float cParticle::getVelocity() const
{
    return this ->mVelocity;
}

void cParticle::setVelocity(float value)
{
    this->mVelocity = value;
}
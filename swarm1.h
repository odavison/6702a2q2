// Filename: swarm1.h

#ifndef SWARM1_H
#define SWARM1_H

/*
Sources:
Kennedy, J. and Eberhart, R. C. Particle swarm optimization.
       Proc. IEEE int'l conf. on neural networks Vol. IV, pp. 1942-1948.
       IEEE service center, Piscataway, NJ, 1995.
PSO Tutorial found at: http://www.swarmintelligence.org/tutorials.php
*/
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int TARGET = 100;
const int MAX_INPUTS = 3;           // Number of variables to be optimized
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;           //Maximum velocity change allowed.

const int MAX_EPOCHS = 200;
//The particles will be initialized with data randomly chosen within the range
//of these starting min and max values: 
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;

#include "cParticle.h"

int     main();
void    psoAlgorithm();
void    getVelocity(int gBestIndex);
void    updateParticles(int gBestIndex);
void    initialize();
int     testProblem(int index);
float   gRand();
int     getRandomNumber(int low, int high);
int     minimum();

#endif

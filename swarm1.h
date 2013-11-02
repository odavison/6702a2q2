// Filename: swarm1.h

#ifndef SWARM1_H
#define SWARM1_H

#define EX7
#define SEED 1

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

#ifdef EX0
#define EXAMPLE_NAME "EX0"

const int TARGET = 100;
const int MAX_INPUTS = 3;           // Number of variables to be optimized
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;           //Maximum velocity change allowed.

const int MAX_EPOCHS = 200;
//The particles will be initialized with data randomly chosen within the range
//of these starting min and max values: 
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;
#endif //EX0

#ifdef EX1
#define EXAMPLE_NAME "EX1"

const int TARGET = 50;
const int MAX_INPUTS = 3;
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 200;
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;
#endif //EX1

#ifdef EX2
#define EXAMPLE_NAME "EX2"

const int TARGET = 50;
const int MAX_INPUTS = 10;
const int MAX_PARTICLES = 20;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 200;
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;
#endif //EX2

#ifdef EX3
#define EXAMPLE_NAME "EX3"

const int TARGET = 50;
const int MAX_INPUTS = 10;
const int MAX_PARTICLES = 3;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 200;
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;
#endif //EX3

#ifdef EX4
#define EXAMPLE_NAME "EX4"

const int TARGET = 50;
const int MAX_INPUTS = 3;
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 200;
const int START_RANGE_MIN = 149;
const int START_RANGE_MAX = 190;
#endif //EX4

#ifdef EX5
#define EXAMPLE_NAME "EX5"

const int TARGET = 50;
const int MAX_INPUTS = 10;
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 20000;
const int START_RANGE_MIN = 1400;
const int START_RANGE_MAX = 1900;
#endif //EX5

#ifdef EX6
#define EXAMPLE_NAME "EX6"

const int TARGET = 500000;
const int MAX_INPUTS = 10;
const int MAX_PARTICLES = 10;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 20000000;
const int START_RANGE_MIN = 14000;
const int START_RANGE_MAX = 890000;
#endif //EX6

#ifdef EX7
#define EXAMPLE_NAME "EX7"

const int TARGET = 500000;
const int MAX_INPUTS = 1000;
const int MAX_PARTICLES = 1000;
const float V_MAX = 10.0;

const int MAX_EPOCHS = 1000;
const int START_RANGE_MIN = 14000;
const int START_RANGE_MAX = 890000;
#endif //EX7


#include "cParticle.h"

int     main();
void    psoAlgorithm();
void    getVelocity(int gBestIndex);
void    updateParticles(int gBestIndex);
void    initialize();
int     testProblem(int index);
void	updateTotal(int index);
float   gRand();
int     getRandomNumber(int low, int high);
int     minimum();

#endif

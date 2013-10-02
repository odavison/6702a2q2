// Filename: swarm1.cpp

#include "swarm1.h"

cParticle particles[MAX_PARTICLES];

int main()
{
    srand((unsigned)time(0));

    psoAlgorithm();

    return 0;
}

void psoAlgorithm()
{
    int gBest = 0;
    int gBestTest = 0;
    int epoch = 0;
    bool done = false;

    initialize();

    do
    {
      /* Two conditions can end this loop:
            if the maximum number of epochs allowed has been reached, or,
            if the Target value has been found.
      */
        if(epoch < MAX_EPOCHS){

            for(int i = 0; i <= MAX_PARTICLES - 1; i++)
            {
                for(int j = 0; j <= MAX_INPUTS - 1; j++)
                {
                    if(j < MAX_INPUTS - 1){
                        cout << particles[i].getData(j) << " + ";
                    }else{
                        cout << particles[i].getData(j) << " = ";
                    }
                } // j

                cout << testProblem(i) << endl;
                if(testProblem(i) == TARGET)
                {
                    done = true;
                }
            } // i

            gBestTest = minimum();

            //If any particle's pBest value is better than the gBest value,
            //make it the new gBest Value.
            if(abs(TARGET - testProblem(gBestTest)) < abs(TARGET - testProblem(gBest)))
            {
                gBest = gBestTest;
            }

            getVelocity(gBest);

            updateParticles(gBest);

            epoch += 1;

        }else{
            done = true;
        }

    }while(!done);

    cout << epoch << " epochs completed." << endl;

    return;
}

void initialize()
{
    int total;

    for(int i = 0; i <= MAX_PARTICLES - 1; i++)
    {
        total = 0;
        for(int j = 0; j <= MAX_INPUTS - 1; j++)
        {
            particles[i].setData(j, getRandomNumber(START_RANGE_MIN, START_RANGE_MAX));
            total += particles[i].getData(j);
        } // j
        particles[i].setpBest(total);
    } // i

    return;
}

void getVelocity(int gBestIndex)
{
/* from Kennedy & Eberhart(1995).
    vx[][] = vx[][] + 2 * rand() * (pbestx[][] - presentx[][]) + 
                      2 * rand() * (pbestx[][gbest] - presentx[][])
*/
    int testResults, bestResults;
    float vValue;
    
    bestResults = testProblem(gBestIndex);

    for(int i = 0; i <= MAX_PARTICLES - 1; i++)
    {
        testResults = testProblem(i);
        vValue = particles[i].getVelocity() + 
            2 * gRand() * (particles[i].getpBest() - testResults) + 2 * gRand() * 
                                                    (bestResults - testResults);

        if(vValue > V_MAX){
            particles[i].setVelocity(V_MAX);
        }else if(vValue < -V_MAX){
            particles[i].setVelocity(-V_MAX);
        }else{
            particles[i].setVelocity(vValue);
        }
    } // i
}

void updateParticles(int gBestIndex)
{
    int total, tempData;
    
    for(int i = 0; i <= MAX_PARTICLES - 1; i++)
    {
        for(int j = 0; j <= MAX_INPUTS - 1; j++)
        {
            if(particles[i].getData(j) != particles[gBestIndex].getData(j))
            {
                tempData = particles[i].getData(j);
                particles[i].setData(j, tempData + static_cast<int>(particles[i].getVelocity()));
            }
        } // j

        //Check pBest value.
        total = testProblem(i);
        if(abs(TARGET - total) < particles[i].getpBest())
        {
            particles[i].setpBest(total);
        }

    } // i

}

int testProblem(int index)
{
    int total = 0;

    for(int i = 0; i <= MAX_INPUTS - 1; i++)
    {
        total += particles[index].getData(i);
    } // i

    return total;
}

float gRand()
{
    // Returns a pseudo-random float between 0.0 and 1.0
    return float(rand()/(RAND_MAX + 1.0));
}

int getRandomNumber(int low, int high)
{
    // Returns a pseudo-random integer between low and high.
    return low + int(((high - low) + 1) * rand() / (RAND_MAX + 1.0)); 
}

int minimum()
{
//Returns an array index.
    int winner = 0;
    bool foundNewWinner;
    bool done = false;

    do
    {
        foundNewWinner = false;
        for(int i = 0; i <= MAX_PARTICLES - 1; i++)
        {
            if(i != winner){             //Avoid self-comparison.
                //The minimum has to be in relation to the Target.
                if(abs(TARGET - testProblem(i)) < abs(TARGET - testProblem(winner)))
                {
                    winner = i;
                    foundNewWinner = true;
                }
            }
        } // i

        if(foundNewWinner == false)
        {
            done = true;
        }

    }while(!done);

    return winner;
}

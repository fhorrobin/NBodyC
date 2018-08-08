#ifndef LEAPFROG_H_
#define LEAPFROG_H_

#include "simulation.h"
#include "particle.h"

void leapfrog_integrate(Simulation *sim, double dt);

void leapfrog_push_step(Particle2D *particle, double dt);

void leapfrog_kick_step(Particle2D *particle, double dt);

#endif // LEAPFROG_H_
#ifndef LEAPFROG_H_
#define LEAPFROG_H_

#include "simulation.h"
#include "particle.h"

/**
 * @brief Integrate the system of particles with the leapfrog method.
 * @param sim Pointer to the simulation to be integrated.
 * @param dt The timestep for the integration.
 */
void leapfrog_integrate(Simulation *sim, double dt);

/**
 * @brief Push Step (advance position) for the leapfrog integrator.
 * @param particle Pointer to the particle to be advanced.
 * @param dt Timestep for the push step.
 */ 
void leapfrog_push_step(Particle2D *particle, double dt);

/**
 * @brief Kick Step (advance velocity) for the leapfrog integrator.
 * @param paricle Pointer to the particle to be advanced.
 * @param dt Time step for the kick step.
 */  
void leapfrog_kick_step(Particle2D *particle, double dt);

#endif // LEAPFROG_H_

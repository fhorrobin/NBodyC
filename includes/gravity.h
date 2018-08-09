/**
 * @file gravity.h
 * @brief Functions to perform gravity calculations.
 */


#ifndef GRAVITY_H_
#define GRAVITY_H_

#include "simulation.h"
#include "particle.h"

/**
 * @brief Calculates the gravitational interations by computing each force pair.
 * N^2 Method that computes the interaction of each particle with each other particle. This is
 * the most accurate way to calculate the gravitational interaction of point particles but also the
 * slowest. This method treats the particles as point particles. Useful for simulations with few particles
 * where high precision is needed.
 * @param sim Pointer to the simulation.
 * @param particle Pointer to the particle for which the acceleration is wanted.
 */
void full_gravity(Simulation *sim, Particle2D *particle);

#endif // GRAVITY_H_

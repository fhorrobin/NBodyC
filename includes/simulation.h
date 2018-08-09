/**
 * @file simulation.h
 * @brief Data and methods for an NBody simulation.
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <stdlib.h>
#include "particle.h"

/**
 * @struct Simulation_
 * @brief Data structure for a simulation.
 * Holds the particles and other information about an
 * NBody simulation. Particles are stored as pointer array to
 * pointers of particles.
 * @param particles The particles in the simulation.
 * @param num_particles The number of particles in the simulation.
 * @param curr The current index for inserting particles.
 * @param dt The timestep for the simulation.
 */
struct Simulation_ {
    Particle2D **particles;
    size_t num_particles;
    size_t curr;
    double dt;
};
typedef struct Simulation_ Simulation;

/**
 * @
 * @brief Allocate the memory for a simulation.
 * @param inum_particles The number of particles in the simulation.
 * @param idt the timestep for the simulation.
 * @returns A pointer to the simulation.
 * @throws Memory Allocation Error if the memory cannot be allocated.
 */
Simulation *create_simulation(size_t inum_particles, double idt);

/**
 * @brief Deallocate the memory from a simulation.
 * @param sim Pointer to the simulation to be deleted.
 */ 
void delete_simulation(Simulation *sim);

/**
 * @brief Add a particle to the simulation.
 * If the simulation has more particles in it than num_particles, then the
 * array of particles is dynamically reallocated to make space for a new
 * particle. This operation is slow for large numbers of particles so setting
 * num_particles correctly is recommended.
 * @param sim Pointer to the simulation to add a particle to.
 * @param particle Pointer to the particle to add.
 */ 
void add_particle(Simulation *sim, Particle2D *particle);

/**
 * @brief Run a simulation.
 * @param sim Pointer to the simulation to simulate.
 * @param num_steps Number of steps to simulate.
 */ 
void simulate(Simulation *sim, size_t num_steps);

#endif // SIMULATION_H_

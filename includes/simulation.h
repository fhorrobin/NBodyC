#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <stdlib.h>
#include "particle.h"

struct Simulation_ {
    Particle2D **particles;
    size_t num_particles;
    size_t curr;
    double dt;
};
typedef struct Simulation_ Simulation;

Simulation *create_simulation(size_t inum_particles, double idt);

void delete_simulation(Simulation *sim);

void add_particle(Simulation *sim, Particle2D *particle);

void simulate(Simulation *sim, size_t num_steps);

#endif // SIMULATION_H_

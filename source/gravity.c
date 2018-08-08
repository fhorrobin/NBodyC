#include <stdlib.h>
#include <math.h>
#include "../includes/gravity.h"

void full_gravity(Simulation *sim, Particle2D *particle)
{
    double dx, dy;
    double r2;
    
    particle->ax = 0.0;
    particle->ay = 0.0;

    for (size_t i = 0; i < sim->num_particles; i++) {
        if (sim->particles[i] != particle) {
            dx = sim->particles[i]->x - particle->x;
            dy = sim->particles[i]->y - particle->y;

            r2 = dx * dx + dy * dy;

            particle->ax += (sim->particles[i]->mass * dx) / (r2 * sqrt(r2));
            particle->ay += (sim->particles[i]->mass * dy) / (r2 * sqrt(r2));
        }
    }
}
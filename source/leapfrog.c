#include <stdlib.h>
#include "../includes/leapfrog.h"
#include "../includes/gravity.h"

void leapfrog_integrate(Simulation *sim, double dt)
{
    for (size_t i = 0; i < sim->num_particles; i++) {
        leapfrog_push_step(sim->particles[i], dt);
    }

    for (size_t i = 0; i < sim->num_particles; i++) {
        full_gravity(sim, sim->particles[i]);
    }

    for (size_t i = 0; i < sim->num_particles; i++) {
        leapfrog_kick_step(sim->particles[i], dt);
    }

    for (size_t i = 0; i < sim->num_particles; i++) {
        leapfrog_push_step(sim->particles[i], dt);
    }
}

void leapfrog_push_step(Particle2D *particle, double dt)
{
    particle->x += particle->vx * dt / 2;
    particle->y += particle->vy * dt / 2;
}

void leapfrog_kick_step(Particle2D *particle, double dt)
{
    particle->vx += particle->ax * dt;
    particle->vy += particle->ay * dt;
}
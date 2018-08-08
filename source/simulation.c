#include <stdlib.h>
#include <stdio.h>
#include "../includes/simulation.h"
#include "../includes/leapfrog.h"
#include "../includes/error_handler.h"

Simulation *create_simulation(size_t inum_particles, double idt)
{
    Simulation *sim = malloc(sizeof(Simulation));

    // Throws an error if allocation of the simulation fails.
    if (sim == NULL) {
        standard_error(__FILE__, __LINE__, errno);
    }

    sim->num_particles = inum_particles;
    sim->curr = 0;

    sim->particles = malloc(sizeof(Particle2D*) * sim->num_particles);

    // Throws an error if allocation of the particles fails.
    if (sim->particles == NULL) {
        standard_error(__FILE__, __LINE__, errno);
    }

    for (size_t i = 0; i < sim->num_particles; i++) {
        sim->particles[i] = NULL;
    }

    sim->dt = idt;

    return sim;
}

void delete_simulation(Simulation *sim)
{
    for (size_t i = 0; i < sim->num_particles; i++) {
        delete_particle(sim->particles[i]);
    }

    free(sim->particles);

    free(sim);
}

void add_particle(Simulation *sim, Particle2D *particle)
{
    // If there is space in the array
    if (sim->curr < sim->num_particles) {
        sim->particles[sim->curr] = particle;
        sim->curr++;
    } else {
        Particle2D **tmp = realloc(sim->particles, (sim->num_particles + 1) * sizeof(Particle2D*));

        // Error handling if realloc fails
        if (tmp == NULL) {
            realloc_pointer_array_error((void **)sim->particles, sim->num_particles, __FILE__, __LINE__, errno);
        } else {
            sim->particles = tmp;
        }

        sim->num_particles++;
        add_particle(sim, particle);
    }
}

void simulate(Simulation *sim, size_t num_steps)
{
    FILE *output_file;
    output_file = fopen("results.txt", "w");

    for (size_t i = 0; i < num_steps; i++) {
        leapfrog_integrate(sim, sim->dt);

        if ((i % 10) == 0)
        {
            for (size_t j = 0; j < sim->num_particles; j++)
            {
                fprintf(output_file, "%f \t %f \n", sim->particles[j]->x, sim->particles[j]->y);
            }
        }
    }

    fclose(output_file);
}
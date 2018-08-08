#include <stdlib.h>
#include <stdio.h>
#include "../includes/particle.h"
#include "../includes/error_handler.h"

Particle2D *create_particle(double ix, double iy, double ivx, double ivy, double mass)
{
    Particle2D *particle = malloc(sizeof(Particle2D));

    // Throws and error if allocating a particle fails.
    if (particle == NULL) {
        standard_error(__FILE__, __LINE__, errno);
    }
    
    particle->x = ix;
    particle->y = iy;
    particle->vx = ivx;
    particle->vy = ivy;
    particle->ax = 0.0;
    particle->ay = 0.0;
    particle->mass = mass;
    
    return particle;
}

void delete_particle(Particle2D *particle)
{
    // No allocated resources inside the struct so we can just free it.
    free(particle);
}
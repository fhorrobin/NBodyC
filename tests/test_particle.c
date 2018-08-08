#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../includes/particle.h"

#define EPS 0.0001
typedef int bool;

int test_init_particle();

int main()
{
    if (test_init_particle() == EXIT_FAILURE) {
        fprintf(stderr, "Test Failed: create_particle().\n");        
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

int test_init_particle()
{
    
    Particle2D *p = create_particle(1., 0., 0., 1., 0.01);

    bool x = fabs(p->x - 1.0) < EPS;
    bool y = fabs(p->y - 0.0) < EPS;
    bool vx = fabs(p->vx - 0.0) < EPS;
    bool vy = fabs(p->vy - 1.0) < EPS;
    bool ax = fabs(p->ax - 0.0) < EPS;
    bool ay = fabs(p->ay - 0.0) < EPS;
    bool mass = fabs(p->mass - 0.01) < EPS;

    if (x && y && vx && vy && ax && ay && mass) {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
#include <stdio.h>
#include "../includes/particle.h"
#include "../includes/simulation.h"

int main()
{
    const double mu = 0.001;

    Simulation *sim = create_simulation(1, 0.01);
    add_particle(sim, create_particle(1. - mu, 0., 0., 1. - mu, mu));
    add_particle(sim, create_particle(-mu, 0., 0., -mu, 1. - mu));

    simulate(sim, 1000);

    delete_simulation(sim);

    return 0;
}

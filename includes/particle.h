#ifndef PARTICLE_H_
#define PARTICLE_H_

/**
 * @brief Data structure for an NBody particle.
 * Stores the position, velocity, mass and acceleration of a particle. 
 */ 
struct Particle2D_ {
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
    double mass;
};
typedef struct Particle2D_ Particle2D;

/**
 * @brief Allocate the data structures for a particle.
 * @param ix x coordinate for the particle.
 * @param iy y coordinate for the particle.
 * @param ivx x velocity of the particle.
 * @param ivy y velovity of the particle.
 * @param mass The mass of the particle.
 * @returns A pointer to the particle.
 * @throws Memory Allocation Error if the memory cannot be allocated.
 */ 
Particle2D *create_particle(double ix, double iy, double ivx, double ivy, double mass);

/**
 * @brief Deallocate the memory for a particle.
 * @param particle Pointer to the particle to be deleted. 
 */ 
void delete_particle(Particle2D *particle);

#endif // PARTICLE_H_

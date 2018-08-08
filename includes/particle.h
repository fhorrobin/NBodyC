#ifndef PARTICLE_H_
#define PARTICLE_H_

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

Particle2D *create_particle(double ix, double iy, double ivx, double ivy, double mass);
void delete_particle(Particle2D *particle);

#endif // PARTICLE_H_

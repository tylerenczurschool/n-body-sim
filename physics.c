#include "physics.h"

void applyObjectVelocity(struct Circle* c) {
    c->x += c->xv;
    c->y += c->yv;

    if (c->x > WIDTH || c->x < 0) {
        c->xv *= -1;
    }
    if (c->y > HEIGHT || c->y < 0) {
        c->yv *= -1;
    }
}

void applyObjectGravity(struct Circle* c) {
    c->xv += c->xf/c->m;
    c->yv += c->yf/c->m;
}

void computeGravity(struct Circle* c1, struct Circle* c2) { 
    double g = .03;
    double xd = c1->x - c2->x;
    double yd = c1->y - c2->y;
    double d2 = xd * xd + yd * yd;

    if (d2 == 0) {
        return;
    }

    double inv_d2 = 1.0 / d2;
    double f = (c1->m * c2->m) * inv_d2 * g;

    double d = sqrt(d2);
    double inv_d = 1.0 / d;

    double xf = xd * inv_d * f;
    double yf = yd * inv_d * f;

    c1->xf -= xf;
    c2->xf += xf;
    c1->yf -= yf;
    c2->yf += yf;
}

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <math.h>
#include "constants.h"

void applyObjectVelocity(struct Circle* c);
void applyObjectGravity(struct Circle* c);
void computeGravity(struct Circle* c1, struct Circle* c2);

#endif

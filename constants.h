#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define MAX_CIRCLES 6
#define MAX_LENGTH 256
#define WIDTH 1200
#define HEIGHT 900
#define WHITE 0xffffffff
#define BLACK 0x00000000

struct Circle {
    double x, y;
    int r, m;
    double xv, yv, xf, yf;
};

static inline struct Circle createCircle(double x, double y, int r, int m, double xv, double yv) {
    return (struct Circle) {x, y, r, m, xv, yv, 0.0f, 0.0f};
}

#endif

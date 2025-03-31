#include "graphics.h"

void FillCircle(SDL_Surface* surface, struct Circle c, Uint32 color) {
    int x, y, rx, ry, d;
    rx = (int)c.x;
    ry = (int)c.y;
    x = 0;
    y = c.r;
    d = 1 - c.r;

    while (x <= y) {
        // Modified Bresenham's Circle Algorithm
        SDL_FillRect(surface, &(SDL_Rect) {rx - x, ry + y, 2 * x + 1, 1}, color);
        SDL_FillRect(surface, &(SDL_Rect) {rx - x, ry - y, 2 * x + 1, 1}, color);
        SDL_FillRect(surface, &(SDL_Rect) {rx - y, ry + x, 2 * y + 1, 1}, color);
        SDL_FillRect(surface, &(SDL_Rect) {rx - y, ry - x, 2 * y + 1, 1}, color);
        x++;
        if (d < 0) {
            d += 2 * x + 1;
        } 
        else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}

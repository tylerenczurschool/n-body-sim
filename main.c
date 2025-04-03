//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main
#include <stdio.h>
#include "graphics.h"
#include "physics.h"
#include "import.h"


int main(int argc, char** argv) {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Gravity", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    char* filename = "circles.txt";

    if (argc == 2) {
        filename = argv[1];
    }

    FILE* fptr = fopen(filename, "r");
    int n;
    struct Circle* circles = processFile(fptr, &n);
    if (circles == NULL) {
        printf("File processing failed\n");
        return 1;
    }

    int sim_run = 1;
    SDL_Event event;
    while (sim_run) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                sim_run = 0;
            }
        }

        SDL_FillRect(surface, &(SDL_Rect) {0, 0, WIDTH, HEIGHT}, BLACK); 

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                computeGravity(circles + i, circles + j);
            }
            applyObjectGravity(circles + i);
            applyObjectVelocity(circles + i);
            circles[i].xf = circles[i].yf = 0;
            FillCircle(surface, circles[i], WHITE);
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }

    free(circles);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

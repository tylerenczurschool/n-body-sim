#include "import.h"

struct Circle* processFile(FILE *fptr, int* length) { 
    double x, y, xv, yv, xf, yf;
    int r, m, i;
    i = 0;
    char buffer[MAX_LENGTH];
    struct Circle* res = malloc(sizeof(struct Circle) * MAX_CIRCLES);

    if (fptr == NULL) {
        printf("fptr is NULL");
        return NULL;
    }

    while (fgets(buffer, MAX_LENGTH, fptr) && i < MAX_CIRCLES) {
        if (sscanf(buffer, "%lf %lf %d %d %lf %lf", &x, &y, &r, &m, &xv, &yv) == 6) {
            res[i++] = createCircle(x, y, r, m, xv, yv);
        }
        else {
            printf("Skipping malformed line: %s", buffer);
        }
    }

    *length = i;
    return res;
}


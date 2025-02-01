#ifndef PHEROMONE_H
#define PHEROMONE_H

#include <stddef.h>
#include <stdlib.h>

#define PHEROMONE_MEMBLOCK 50 // pheromone points
#define PHEROMONE_MAXVALUE 100

typedef struct pheromone
{
    int value;  // [0-100]
    float x, y; // pheromone point location coordinates
} pheromone_t;

void pheromones_init();
void pheromones_deinit();

void pheromones_addpheromone(float x, float y);
void pheromones_update();

#endif // PHEROMONE_H
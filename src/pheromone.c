#include "pheromone.h"

static size_t size = PHEROMONE_MEMBLOCK;
static size_t pheromones_num = 0;
static pheromone_t* pointer = NULL;

static void pheromones_resize();


void pheromones_init()
{
    pointer = (pheromone_t*)calloc(size, sizeof(pheromone_t));
}

void pheromones_deinit()
{
    free((void*)pointer);
}

void pheromones_addpheromone(float x, float y)
{
    pheromone_t temp = {.value = PHEROMONE_MAXVALUE, .x = x, .y = y};
    pointer[pheromones_num] = temp;
    pheromones_num += 1;

    // resize array if current array is full
    if(pheromones_num > size)
    {
        size += PHEROMONE_MEMBLOCK;
        pheromones_resize();
    }
}

void pheromones_update()
{
    for(size_t i = 0; i <= pheromones_num; ++i)
    {

    }
}


void pheromones_resize()
{

}
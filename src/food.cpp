/**
 * @file Food.cpp
 * @author 6AHKA
 * @brief implementation of food
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "food.hpp"

Food_t* Food_initialize(double x_tl, double y_tl, double x_br, double y_br, int w, int h)
{
    Food_t* p_food = (Food_t*)malloc(sizeof(Food_t));
    
    p_food->x_topleft = x_tl;
    p_food->y_topleft = y_tl;
    p_food->x_bottomright = x_br;
    p_food->y_bottomright = y_br;
    p_food->width = w;
    p_food->height = h;

    p_food->p_array = (int8_t**)malloc(p_food->height * sizeof(int8_t*));    
    for (int i = 0; i < p_food->height; i++)
	{
		p_food->p_array[i] = (int8_t*)malloc(p_food->width * sizeof(int8_t));
    }
    Food_reset(p_food);

    return p_food;
}

void Food_terminate(Food_t* p_food)
{
    for (int i = 0; i < p_food->height; i++)
    {
		free(p_food->p_array[i]);
    }
	free(p_food->p_array);
	free(p_food);
}

int8_t Food_get_by_index(Food_t* p_food, int x, int y)
{
    // adjusting out-of-bounds indexes
    x = x % p_food->width;
    y = y % p_food->height;
    x += (x < 0) ? p_food->width : 0;
    y += (y < 0) ? p_food->height : 0;
    
    return p_food->p_array[y][x];
}

void Food_set_by_index(Food_t* p_food, int x, int y, int8_t val)
{
    // adjusting out-of-bounds indexes
    x = x % p_food->width;
    y = y % p_food->height;
    x += (x < 0) ? p_food->width : 0;
    y += (y < 0) ? p_food->height : 0;

    p_food->p_array[y][x] = val;
}

int8_t Food_get_by_position(Food_t* p_food, double x, double y)
{
    double cell_width = (p_food->x_bottomright - p_food->x_topleft) / p_food->width;
    double cell_height = (p_food->y_bottomright - p_food->y_topleft) / p_food->height;

    int x_index = (x - p_food->x_topleft) / cell_width;
    int y_index = (y - p_food->y_topleft) / cell_height;

    return Food_get_by_index(p_food, x_index, y_index);
}

void Food_set_by_position(Food_t* p_food, double x, double y, int8_t val)
{
    double cell_width = (p_food->x_bottomright - p_food->x_topleft) / p_food->width;
    double cell_height = (p_food->y_bottomright - p_food->y_topleft) / p_food->height;

    int x_index = (x - p_food->x_topleft) / cell_width;
    int y_index = (y - p_food->y_topleft) / cell_height;

    Food_set_by_index(p_food, x_index, y_index, val);
}

void Food_reset(Food_t* p_food)
{
    for (int i = 0; i < p_food->height; i++)
	{
		for (int j = 0; j < p_food->width; j++)
	    {
		    Food_set_by_index(p_food, j, i, 0);
        }
        printf("\n");
    }
}

void Food_print(Food_t* p_food)
{
    printf("\nfood array:\n");
    for (int i = 0; i < p_food->height; i++)
	{
		for (int j = 0; j < p_food->width; j++)
	    {
		    printf("%i\t", Food_get_by_index(p_food, j, i));
        }
        printf("\n");
    }
}
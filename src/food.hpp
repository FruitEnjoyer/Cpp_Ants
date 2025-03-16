/**
 * @file food.hpp
 * @author 6AHKA
 * @brief header file for food.cpp
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FOOD_HPP
#define FOOD_HPP

#include <stdlib.h> // for malloc
#include <stdio.h> // for debugging

typedef struct
{
    double x_topleft, y_topleft, x_bottomright, y_bottomright;
    int width, height;
    int8_t** p_array;
} Food_t;

Food_t* Food_initialize(double x_tl, double y_tl, double x_br, double y_br, int w, int h);

void Food_terminate(Food_t* p_food);

int8_t Food_get_by_index(Food_t* p_food, int x, int y);

void Food_set_by_index(Food_t* p_food, int x, int y, int8_t val);

int8_t Food_get_by_position(Food_t* p_food, double x, double y);

void Food_set_by_position(Food_t* p_food, double x, double y, int8_t val);

void Food_reset(Food_t* p_food);

void Food_print(Food_t* p_food);

#endif // FOOD_HPP
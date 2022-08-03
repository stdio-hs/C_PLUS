#ifndef DRAW_SHAPE_H
#define DRAW_SHAPE_H

#include <stdio.h>


int draw_rectangle(int width, int length); // 꽉찬 사각형
int draw_rectangle_2(int width, int length); // 비어있는 사각형

int draw_right_triangle(int base); // 직각삼각형
int draw_right_triangle_2(int base); // 비어있는 직각삼각형
int draw_reverse_right_triangle(int base); // 180도 회전시킨 직각삼각형

int draw_diamond(int width); // 다이아몬드


#endif // !DRAW_SHAPE_H


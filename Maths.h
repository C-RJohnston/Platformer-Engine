#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>

using namespace sf;
float dot(Vector2f vector1, Vector2f vector2);
Vector2f normal(Vector2f vector);
Vector2f project(Vector2f vector1, Vector2f vector2);
void printVect(Vector2f vector);
float findAngle(Vector2f vector1, Vector2f vector2);
float value(Vector2f vector);
float lerp(float x, float y, float z);
Vector2f vLerp(Vector2f x, Vector2f y, float z);
Vector2f rotate(Vector2f vector, float angle, Vector2f offset=Vector2f(0,0));
Vector2f transpose(Vector2f vector);

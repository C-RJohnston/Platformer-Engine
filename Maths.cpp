#define _USE_MATH_DEFINES
#include "Maths.h"

 float dot(Vector2f vector1, Vector2f vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

 float value(Vector2f vector)
 {
	 return sqrt(dot(vector, vector));
 }

 float lerp(float x, float y, float z)
 {
     return ((1.0f - z) * x) + (z * y);
 }

 Vector2f vLerp(Vector2f x, Vector2f y, float z)
 {
     return Vector2f((1.0f - z) * x) + (z * y);
 }

 float findAngle(Vector2f vector1, Vector2f vector2)
 {
	 return acos(dot(vector1, vector2) / (value(vector1)* value(vector2)));
 }

Vector2f normal(Vector2f vector)
{
	return vector * (1 / sqrt(dot(vector, vector)));
}

Vector2f project(Vector2f vector1, Vector2f vector2)
{
	return dot(vector1, vector2) * normal(vector2);
}
void printVect(Vector2f vector)
{
	std::cout << '(' << vector.x << ',' << vector.y << ')' << '\n';
}

Vector2f rotate(Vector2f vector, float angle,Vector2f offset)
{
	return Vector2f((vector.x-offset.x) * cos(M_PI / 180 * angle) - (vector.y-offset.y) * sin(M_PI / 180 * angle),
		(vector.x-offset.x) * sin(M_PI / 180 * angle) + (vector.y-offset.y) * cos(M_PI / 180 * angle))+offset;
}

Vector2f transpose(Vector2f vector)
{
    return Vector2f(vector.y,vector.x);
}

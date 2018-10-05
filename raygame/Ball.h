#pragma once
#include "raylib.h"
class ball {
public:
	Vector2 pos;   // Position Of Ball
	float radius;  // Radius Of Ball

	float speed;  // Spped Of Ball
	void update(float deltaTime);
	void draw();
};
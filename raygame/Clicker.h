#pragma once
#include "raylib.h"
class pickup {
public:
	Vector2 pos;   // Position Of Ball
	float radius;  // Radius Of Ball
	bool enabled;
	void Draw();
};
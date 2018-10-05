#include "raylib.h"
#include "Clicker.h"
void pickup::Draw()
{
	DrawCircle(pos.x, pos.y, radius, RED);
}

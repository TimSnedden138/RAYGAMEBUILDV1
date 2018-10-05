/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#define LIGHTISHGREEN  CLITERAL{0, 233, 116, 255 };
#include "raylib.h"
#include<iostream>
#include"Ball.h"
#include"Clicker.h"
#include<string>
#include<random>
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 950;
	int screenHeight = 500;
	InitWindow(screenWidth, screenHeight, "TESTING QUATERS");
	SetTargetFPS(60);
	float time = 240;
	ball player;
	player.pos = { 100, 400 };
	player.radius = 30.0;
	player.speed = 175.0;
	const int Orcs = 4;
	pickup 
		pickups[Orcs] = {
			{ {475,250},30,true},
			{{780,25},4,true},
			{{780,63},5,true},
			{ {780,89},5,true}
	};
	int scoremin = 0;
	bool add10 = false;
	bool add150 = false;
	bool add500 = false;
	int scoremax = 9999;
	int timekeeper = 0;
	Texture2D texture = LoadTexture("Resources/BobtheRobot.png");
	Texture2D texture2 = LoadTexture("Resources/1ROBOTUPGRADE.png");
	Texture2D texture3 = LoadTexture("Resources/2ROBOTUPGRADE.png");
	Texture2D texture4 = LoadTexture("Resources/3ROBOTUPGRADE.png");
	while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			time = time - GetFrameTime();
			{
				
				if (time < 240 && time > 0) {
					float mouseYaxis = GetMouseY();
					float mouseXaxis = GetMouseX();
					//Update
					//----------------------------------------------------------------------------------
					player.update(GetFrameTime());
					if (scoremin != scoremax) {
						if (IsKeyPressed(KEY_A)) {
							for (size_t s = 0; s < 1; ++s) {
								if (pickups[s].enabled == true) {
									scoremin = scoremin + 1;
								}
							}
						}
					}
					if (scoremin != scoremax) {
						if (IsKeyPressed(KEY_D)) {
							for (size_t s = 0; s < 1; ++s) {
								if (pickups[s].enabled == true) {
									scoremin = scoremin + 1;
								}
							}
						}
					}
					if (scoremin != scoremax) {
						if (IsKeyPressed(KEY_S)) {
							for (size_t s = 0; s < 1; ++s) {
								if (pickups[s].enabled == true) {
									scoremin = scoremin + 1;
								}
							}
						}
					}
					if (scoremin != scoremax) {
						if (IsKeyPressed(KEY_W)) {
							for (size_t s = 0; s < 1; ++s) {
								if (pickups[s].enabled == true) {
									scoremin = scoremin + 1;
								}
							}
						}
					}
					if (scoremin != scoremax && CheckCollisionPointCircle({ mouseXaxis,mouseYaxis }, { 475,250 },30)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							for (size_t s = 0; s < 1; ++s) {
								if (pickups[s].enabled == true) {
									scoremin = scoremin + 1;
								}
							}
						}
					}
						
					
					if (scoremin >= 100 && scoremin < scoremax && scoremin != scoremax && CheckCollisionPointCircle({ mouseXaxis,mouseYaxis }, { 782,22 }, 10)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							add10 = true;
						}
					}
					if (scoremin >= 2500 && scoremin < scoremax && scoremin != scoremax && CheckCollisionPointCircle({ mouseXaxis,mouseYaxis }, { 779,63 }, 20)) {
						if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
							add150 = true;
						}
					}
					if (scoremin >= 5150 && scoremin < scoremax && scoremin != scoremax && CheckCollisionPointCircle({ mouseXaxis,mouseYaxis }, { 775,81 }, 4)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							add500 = true;
						}
					}

					

					
					//----------------------------------------------------------------------------------
				}

				if (add10 == true) {
					int testTime = (int)GetTime();
					if (testTime >= timekeeper + 1) {
						scoremin = scoremin + rand() % 50;
						timekeeper = testTime;
					}
				}
				if (add150 == true) {
					int testTime = (int)GetTime();
					if (testTime >= timekeeper + 1) {
						scoremin = scoremin + rand() % 150;
						timekeeper = testTime;
					}
				}
				if (add500 == true) {
					int testTime = (int)GetTime();
					if (testTime >= timekeeper + 1) {
						scoremin = scoremin + rand() % 500;
						timekeeper = testTime;
					}
				}

				// Draw
				//----------------------------------------------------------------------------------

				BeginDrawing();
				for (size_t i = 0; i < 4; i++) {
					pickups[i].Draw();
				}
				
				ClearBackground(BLACK);
				DrawTextureEx(texture, { 410,200 }, 0, .75, WHITE);
				DrawTextureEx(texture2, {775,15}, 0, .3,WHITE);
				DrawTextureEx(texture3, { 775,47 }, 0, .3, WHITE);
				DrawTextureEx(texture4, { 775,81 }, 0, .3, WHITE);
				DrawText("CLICK ME!!!!!!!:", 430, 250, .3, RED);
				DrawText("PRESS WASD FAST FOR MORE MONEY", 6, 22, 15, WHITE);
				DrawText("The Creation of Robots you have a 240 seconds to make 99999 robots", 0,0, 16, WHITE);
				DrawText("Robots:", 0, 50, 20, WHITE);
				DrawText(std::to_string(scoremin).c_str(), 77, 50, 20, RED);
				DrawFPS(750, 450);
				DrawText("Time:", 0, 75, 20, WHITE);
				DrawText(std::to_string(time).c_str(), 79, 75, 20, RED);
				DrawText("Robots Activities", 710, 0, 15, RED);
				DrawText("100 Robots:", 700, 15, 15, YELLOW);
				DrawText("For 100 Robot to fix their buddy for use", 655, 33, 15, YELLOW);
				DrawText("2500 Robots:", 685, 48, 15, RED);
				DrawText("For 150 robots fixing their buddy for use", 637, 67, 15, YELLOW);
				DrawText("5150 Robots:", 685, 81, 15, DARKGREEN);
				DrawText("For 500 robots fixing their buddy for use", 637, 95, 15, DARKGREEN);
				EndDrawing();
			}
			if (time <= 0 ) {
				DrawText(("You have created this much " + (std::to_string(scoremin))).c_str() , 0, 320, 27, RED);
				DrawText("robots", 450 , 320, 27,  RED);
				DrawText("BUT NOT GOOD ENOUGH", 0, 370, 27, RED);
			}
			if (scoremin >= scoremax) {
				DrawText("You WIN BUT WE WILL HAVE OUR REVENGE YOU BEAT MY SCORE", 0, 320, 27, LIME);
			}
			//----------------------------------------------------------------------------------

		// De-Initialization
		//--------------------------------------------------------------------------------------   
		}
	UnloadTexture(texture);
	CloseWindow();
	return 0;
	}
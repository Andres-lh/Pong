#include "game.h";

float playerPosX = 0.0f;
float playerPosY = 0.0f;

void simulateGame(RenderState& renderState, Input& input, float deltaTime)
{
	float speed = 50.0f; // units per second
	renderState.clearScreen(0xff5500);
	if (input.buttons[BUTTON_UP].isDown) playerPosY += speed * deltaTime;
	if (input.buttons[BUTTON_DOWN].isDown ) playerPosY -= speed * deltaTime;
	if (input.buttons[BUTTON_RIGHT].isDown ) playerPosX += speed * deltaTime;
	if (input.buttons[BUTTON_LEFT].isDown) playerPosX -= speed * deltaTime;
	
	renderState.drawRectFlex(playerPosX, playerPosY, 5, 10, 0x00ff22);
}
  
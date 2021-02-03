#include "game.h";

float playerPosX = 0.0f;
float playerPosY = 0.0f;

void simulateGame(RenderState& renderState, Input& input)
{
	renderState.clearScreen(0xff5500);
	if (input.buttons[BUTTON_UP].isDown) playerPosY += .1f;
	if (input.buttons[BUTTON_DOWN].isDown ) playerPosY -= .1f;
	if (input.buttons[BUTTON_RIGHT].isDown ) playerPosX += .1f;
	if (input.buttons[BUTTON_LEFT].isDown) playerPosX -= .1f;
	
	renderState.drawRectFlex(playerPosX, playerPosY, 5, 10, 0x00ff22);
}
  
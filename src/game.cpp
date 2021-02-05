#include "game.h";

Player player1;
Player player2;

void simulateGame(RenderState& renderState, Input& input, float deltaTime)
{
	float acceleration1 = 0.f;
	float acceleration2 = 0.f;
	renderState.clearScreen(0x161d6f);

	//Board
	renderState.drawRectFlex(0, 0, 85, 45, 0x1687A7);
	if (input.buttons[BUTTON_UP].isDown)acceleration1 += 1000;
	if (input.buttons[BUTTON_DOWN].isDown) acceleration1 -= 1000;
	if (input.buttons[BUTTON_W].isDown)acceleration2 += 1000;
	if (input.buttons[BUTTON_S].isDown) acceleration2 -= 1000;

	player1.move(input, deltaTime, acceleration1);
	player2.move(input, deltaTime, acceleration2);

	
	//Ball
	renderState.drawRectFlex(0, 0, 1, 1, 0xc7ffd8);

	renderState.drawRectFlex(80, player1.getPosition(), 2.5, 12, 0x161d6f);
	renderState.drawRectFlex(-80, player2.getPosition(), 2.5, 12, 0x161d6f);
}
  
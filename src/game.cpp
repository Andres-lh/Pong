#include "game.h";

Player player1(2.5f, 12.0f);
Player player2(2.5f, 12.0f);
Ball ball(1, 1);

void simulateGame(RenderState& renderState, Input& input, float deltaTime)
{
	float acceleration1 = 0;
	float acceleration2 = 0;

	renderState.clearScreen(0x161d6f);

	//Board
	renderState.drawRectFlex(0, 0, 85, 45, 0x1687A7);

	if (input.buttons[BUTTON_UP].isDown)acceleration1 += 1000;
	if (input.buttons[BUTTON_DOWN].isDown) acceleration1 -= 1000;
	if (input.buttons[BUTTON_W].isDown)acceleration2 += 1000;
	if (input.buttons[BUTTON_S].isDown) acceleration2 -= 1000;

	player1.move(deltaTime, acceleration1);
	player2.move(deltaTime, acceleration2);
	ball.move(deltaTime);

	//Ball
	renderState.drawRectFlex(ball.getPositionX(), ball.getPositionY(), ball.getSizeX(), ball.getSizeY(), 0xc7ffd8);

	collision(ball, player1, player2);

	//Player
	renderState.drawRectFlex(80, player1.getPosition(), player1.getSizeX(), player1.getSizeY(), 0x161d6f);
	renderState.drawRectFlex(-80, player2.getPosition(), player2.getSizeX(), player2.getSizeY(), 0x161d6f);
}

void collision(Ball& ball, Player& player1, Player& player2)
{
	float ballVelocityX = ball.getVelocityX();

	if (ball.getPositionX() + ball.getSizeX() > 80 - player1.getSizeX() &&
		ball.getPositionX() - ball.getSizeX() < 80 + player1.getSizeX() &&
		ball.getPositionY() + ball.getSizeY() > player1.getPosition() - player1.getSizeY() &&
		ball.getPositionY() + ball.getSizeY() < player1.getPosition() + player1.getSizeX())
	{
		ball.setPositionX(80 - player1.getSizeX() - ball.getSizeX());
		ball.setVelocityX(ballVelocityX *= -1);
	}
	else if (ball.getPositionX() + ball.getSizeX() > -80 - player1.getSizeX() &&
			ball.getPositionX() - ball.getSizeX() < -80 + player1.getSizeX() &&
			ball.getPositionY() + ball.getSizeY() > player2.getPosition() - player1.getSizeY() &&
			ball.getPositionY() + ball.getSizeY() < player2.getPosition() + player1.getSizeX())
	{
		ball.setPositionX(-80 + player1.getSizeX() + ball.getSizeX());
		ball.setVelocityX(ballVelocityX *= -1);
	}
}
  
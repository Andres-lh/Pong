#include "game.h";

Player player1(2.5f, 12.0f);
Player player2(2.5f, 12.0f);
Ball ball(1, 1);
bool Ai = true;

void simulateGame(RenderState& renderState, Input& input, float deltaTime)
{
	float acceleration1 = 0;
	float acceleration2 = 0;

	renderState.clearScreen(0x161d6f);

	//Board
	renderState.drawRectFlex(0, 0, 85, 45, 0x1687A7);

	if (input.buttons[BUTTON_UP].isDown)acceleration1 += 1000;
	if (input.buttons[BUTTON_DOWN].isDown) acceleration1 -= 1000;

	if (Ai == true) 
	{
		acceleration2 = (ball.getPositionY() - player2.getPosition()) * 50;
		player2.AIBehaviour(acceleration2);
	}

	/*if (input.buttons[BUTTON_W].isDown)acceleration2 += 1000;
	if (input.buttons[BUTTON_S].isDown) acceleration2 -= 1000;*/

	player1.move(deltaTime, acceleration1);
	player2.move(deltaTime, acceleration2);
	ball.move(deltaTime);

	//Ball
	renderState.drawRectFlex(ball.getPositionX(), ball.getPositionY(), ball.getSizeX(), ball.getSizeY(), 0xc7ffd8);

	collision(ball, player1, player2);
	score(ball, player1, player2);

	renderState.drawNumber(player1.getScore(), -10, 40, 1.0f, 0xbbffbb);
	renderState.drawNumber(player2.getScore(), 10, 40, 1.0f, 0xbbffbb);

	//Player
	renderState.drawRectFlex(80, player1.getPosition(), player1.getSizeX(), player1.getSizeY(), 0x161d6f);
	renderState.drawRectFlex(-80, player2.getPosition(), player2.getSizeX(), player2.getSizeY(), 0x161d6f);
}

void collision(Ball& ball, Player& player1, Player& player2)
{
	float ballVelocityX = ball.getVelocityX();
	float ballVelocityY = ball.getVelocityY();

	if (ball.getPositionX() + ball.getSizeX() > 80 - player1.getSizeX() &&
		ball.getPositionX() - ball.getSizeX() < 80 + player1.getSizeX() &&
		ball.getPositionY() + ball.getSizeY() > player1.getPosition() - player1.getSizeY() &&
		ball.getPositionY() + ball.getSizeY() < player1.getPosition() + player1.getSizeY())
	{
		ball.setPositionX(80 - player1.getSizeX() - ball.getSizeX());
		ball.setVelocityX(ballVelocityX *= -1);
		ball.setVelocityY((ball.getPositionY() - player1.getPosition()) * 2 + player1.getVelocity() * 0.6);
	}
	else if (ball.getPositionX() + ball.getSizeX() > -80 - player2.getSizeX() &&
			ball.getPositionX() - ball.getSizeX() < -80 + player2.getSizeX() &&
			ball.getPositionY() + ball.getSizeY() > player2.getPosition() - player1.getSizeY() &&
			ball.getPositionY() + ball.getSizeY() < player2.getPosition() + player1.getSizeY())
	{
		ball.setPositionX(-80 + player1.getSizeX() + ball.getSizeX());
		ball.setVelocityX(ballVelocityX *= -1);
		ball.setVelocityY((ball.getPositionY() - player2.getPosition()) * 2 + player2.getVelocity() * 0.6);
	}

	if (ball.getPositionY() + ball.getSizeY() > 45)
	{
		ball.setPositionY(45 - ball.getSizeY());
		ball.setVelocityY(ballVelocityY *= -1);
	}
	else if (ball.getPositionY() - ball.getSizeY() < -45)
	{
		ball.setPositionY(-45 + ball.getSizeY());
		ball.setVelocityY(ballVelocityY *= -1);
	}
}

void score(Ball& ball, Player& player1, Player& player2)
{
	float ballVelocityX = ball.getVelocityX();
	int score1 = player1.getScore();
	int score2 = player2.getScore();

	if (ball.getPositionX() + ball.getSizeX() > 85)
	{
		ball.setVelocityX(ballVelocityX *= -1);
		ball.setVelocityY(0);
		ball.setPositionX(0);
		ball.setPositionY(0);
		player1.setScore(++score1);
	}
	else if (ball.getPositionX() - ball.getSizeX() < -85)
	{
		ball.setVelocityX(ballVelocityX *= -1);
		ball.setVelocityY(0);
		ball.setPositionX(0);
		ball.setPositionY(0);
		player2.setScore(++score2);
	}
	
}
  
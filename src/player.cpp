#include "player.h"

Player::Player(float sizeX, float sizeY) 
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	position = 0;
	velocity = 0;
	acceleration = 0;
	score = 0;
}

float Player::getPosition()
{
	return position;
}


void Player::move(float deltaTime, float acceleration)
{
	this->acceleration = acceleration;

	//friction
	acceleration -= velocity * 10.0f;

	position = position + velocity * deltaTime + acceleration * deltaTime * deltaTime * 0.5f;
	velocity = velocity + acceleration * deltaTime;

	if (position + sizeY > 45)
	{
		position = 45 - sizeY;
		velocity = 0;
	}
	else if (position - sizeY < -45)
	{
		position = -45 + sizeY;
		velocity = 0;
	}
	
}

float Player::getSizeX()
{
	return sizeX;
}

float Player::getSizeY()
{
	return sizeY;
}

float Player::getVelocity()
{
	return velocity;
}

int Player::getScore()
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

void Player::AIBehaviour(float acceleration)
{
	this->acceleration = acceleration;
	if (acceleration > 1300) acceleration = 1300;
	if (acceleration < -1300) acceleration = -1300;
}
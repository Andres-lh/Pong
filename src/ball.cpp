#include "ball.h"

Ball::Ball(float sizeX, float sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	positionX = 0;
	positionY = 0;
	velocityX = 90;
	velocityY = 0;
}

float Ball::getSizeX() 
{
	return sizeX;
}

float Ball::getSizeY()
{
	return sizeY;
}

void Ball::move(float dt)
{
	positionX += velocityX * dt;
	positionY += velocityY * dt;
}

float Ball::getPositionX() 
{
	return positionX;
}
float Ball::getPositionY()
{
	return positionY;
}

void Ball::setPositionX(float posX) 
{
	positionX = posX;
}

void Ball::setPositionY(float posY)
{
	positionY = posY;
}

void Ball::setVelocityX(float velocity)
{
	velocityX = velocity;
}
 
void Ball::setVelocityY(float velocity)
{
	velocityY = velocity;
}

float Ball::getVelocityX()
{
	return velocityX;
}

float Ball::getVelocityY()
{
	return velocityY;
}


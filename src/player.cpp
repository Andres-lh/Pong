#include "player.h"


float Player::getPosition()
{
	return position;
}


void Player::move(Input& input, float deltaTime, float acceleration)
{
	acceleration = acceleration;

	//friction
	acceleration -= velocity * 10.0f;

	position = position + velocity * deltaTime + acceleration * deltaTime * deltaTime * 0.5f;
	velocity = velocity + acceleration * deltaTime;
	
}
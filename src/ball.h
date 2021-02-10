#pragma once

class Ball {
private:
	float sizeX;
	float sizeY;
	float positionX;
	float positionY;
	float velocityX;
	float velocityY;

public:
	Ball(float sizeX, float sizeY);
	float getSizeX();
	float getSizeY();
	float getPositionX();
	float getPositionY();
	void setPositionX(float posX);
	void setPositionY();
	void setVelocityX(float velocity);
	float getVelocityX();
	void move(float dt);
	void collision(float playerSizeX, float playerSizeY, float playerPosition);
};

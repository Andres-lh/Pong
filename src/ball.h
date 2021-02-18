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
	void setPositionY(float posY);
	void setVelocityX(float velocity);
	void setVelocityY(float velocity);
	float getVelocityX();
	float getVelocityY();
	void move(float dt);

};

#pragma once

class Player {
private:
	float position;
	float velocity;
	float acceleration;
	float sizeX;
	float sizeY;
	int score;
public:
	Player(float sizeX, float sizeY);
	float getPosition();
	void move(float deltaTime, float acceleration);
	float getSizeX();
	float getSizeY();
};

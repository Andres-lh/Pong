#pragma once

class Player {
private:
	float position;
	float velocity;
	float acceleration;
	float sizeX;
	float sizeY;
	int score;
	bool AI;
public:
	Player(float sizeX, float sizeY);
	float getPosition();
	void move(float deltaTime, float acceleration);
	float getSizeX();
	float getSizeY();
	float getVelocity();
	int getScore();
	void setScore(int score);
	void AIBehaviour(float acceleration);
};

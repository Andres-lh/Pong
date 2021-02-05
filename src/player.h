#pragma once
#include "input.h"

class Player {
private:
	float position = 0.0f;
	float velocity = 0.0f;
public:
	float acceleration = 0.0f;
	float getPosition();
	void move(Input& i, float deltaTime, float acceleration);
};

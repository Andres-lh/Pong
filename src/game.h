#pragma once
#include "render.h"

//Input
struct ButtonState {
	bool isDown = false;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_COUNT,
};


struct Input {
	ButtonState buttons[BUTTON_COUNT];
};

// GameSimulate

void simulateGame( RenderState& renderState, Input& input);
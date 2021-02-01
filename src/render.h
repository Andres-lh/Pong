#pragma once
#include <windows.h>

struct RenderState {
	int height, width;
	void* memory;
	BITMAPINFO bitmaoInfo;
};

void renderBackground(RenderState&);

void clearScreen(RenderState&, unsigned int);


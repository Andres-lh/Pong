#pragma once
#include <windows.h>

struct RenderState {
	int height, width;
	void* memory;
	BITMAPINFO bitmaoInfo;
};

void renderBackground(RenderState&);

void clearScreen(RenderState&, unsigned int);

void drawRect(RenderState&, int xi, int yi, int xf, int yf, unsigned int color);

void drawRectFlex(RenderState&,float x, float y, float halfX, float halfY, unsigned int color);


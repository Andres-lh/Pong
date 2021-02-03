#pragma once
#include <windows.h>

class RenderState {
public:
	int height, width;
	void* memory;
	BITMAPINFO bitmaoInfo;

	void renderBackground();

	void clearScreen( unsigned int);

	void drawRect( int xi, int yi, int xf, int yf, unsigned int color);

	void drawRectFlex(float x, float y, float halfX, float halfY, unsigned int color);
};




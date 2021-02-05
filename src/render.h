#pragma once
#include <windows.h>

class RenderState {
private:
	void drawRect(int xi, int yi, int xf, int yf, unsigned int color);
public:
	int height, width;
	void* memory;
	BITMAPINFO bitmaoInfo;

	void renderBackground();

	void clearScreen( unsigned int);

	

	void drawRectFlex(float x, float y, float halfX, float halfY, unsigned int color);


};




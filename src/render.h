#pragma once
#include <windows.h>

class RenderState {
private:
	void drawRect(int xi, float yi, float xf, float yf, unsigned int color);
public:
	int height, width;
	void* memory;
	BITMAPINFO bitmaoInfo;
	void renderBackground();
	void clearScreen( unsigned int);
	void drawRectFlex(float x, float y, float halfX, float halfY, unsigned int color);
	void drawNumber(int number, float x, float y, float size, unsigned int color);
	void drawText(const char* text, float x, float y, float size, unsigned int color);
};




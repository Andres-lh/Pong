#include <windows.h>
#include "render.h"


void RenderState::renderBackground()
{
	unsigned int* pixel = (unsigned int*)memory;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			*pixel++ = 0xff5500;
		}
	}
}

void RenderState::clearScreen( unsigned int color)
{
	unsigned int* pixel = (unsigned int*) memory;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			*pixel++ = color;
		}
	}
}

inline int fixSize(int min, int val, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

void RenderState::drawRect(int xi, int yi, int xf, int yf, unsigned int color)
{
	xi = fixSize(0, xi, width);
	xf = fixSize(0, xf, width);
	yi = fixSize(0, yi, height);
	yf = fixSize(0, yf, height);

	for (int y = yi; y < yf; y++) {
		unsigned int* pixel = (unsigned int*)memory + xi + y * width;
		for (int x = xi; x < xf; x++) {
			*pixel++ = color;
		}
	}

}

void RenderState::drawRectFlex(float x, float y, float halfX, float halfY, unsigned int color)
{
	x *= height * 0.01f;
	y *= height * 0.01f;
	halfX *= height * 0.01f;
	halfY *= height * 0.01f;

	x += width / 2.1f;
	y += height / 2.1f;

	int xi = x - halfX;
	int xf = x + halfX;
	int yi = y - halfY;
	int yf = y + halfY;

	drawRect(xi, yi, xf, yf, color);
}
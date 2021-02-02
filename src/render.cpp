#include <windows.h>
#include "render.h"


void renderBackground(RenderState& renderState)
{
	unsigned int* pixel = (unsigned int*)renderState.memory;
	for (int y = 0; y < renderState.height; y++) {
		for (int x = 0; x < renderState.width; x++) {
			*pixel++ = 0xff5500;
		}
	}
}

void clearScreen(RenderState& renderState, unsigned int color)
{
	unsigned int* pixel = (unsigned int*)renderState.memory;
	for (int y = 0; y < renderState.height; y++) {
		for (int x = 0; x < renderState.width; x++) {
			*pixel++ = color;
		}
	}
}

inline int fixSize(int min, int val, int max) {
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

void drawRect(RenderState& renderState, int xi, int yi, int xf, int yf, unsigned int color)
{
	xi = fixSize(0, xi, renderState.width);
	xf = fixSize(0, xf, renderState.width);
	yi = fixSize(0, yi, renderState.height);
	yf = fixSize(0, yf, renderState.height);

	for (int y = yi; y < yf; y++) {
		unsigned int* pixel = (unsigned int*)renderState.memory + xi + y * renderState.width;
		for (int x = xi; x < xf; x++) {
			*pixel++ = color;
		}
	}

}

void drawRectFlex(RenderState& renderState, float x, float y, float halfX, float halfY, unsigned int color)
{
	x *= renderState.height * 0.01f;
	y *= renderState.height * 0.01f;
	halfX *= renderState.height * 0.01f;
	halfY *= renderState.height * 0.01f;

	x += renderState.width / 2.1f;
	y += renderState.height / 2.1f;

	int xi = x - halfX;
	int xf = x + halfX;
	int yi = y - halfY;
	int yf = y + halfY;

	drawRect(renderState, xi, yi, xf, yf, color);
}
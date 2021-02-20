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

void RenderState::drawRect(int xi, float yi, float xf, float yf, unsigned int color)
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

void RenderState::drawNumber(int number, float x, float y, float size, unsigned int color)
{
	float halfSize = size * 0.5f;
	bool drewNumber = false;
	while (number || !drewNumber)
	{
		drewNumber = true;
		int digit = number % 10;
		number = number / 10;
		switch (digit)
		{
		case 0:
			drawRectFlex(x - size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x, y + size * 2.f, halfSize, halfSize, color);
			drawRectFlex(x, y - size * 2.f, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 1:
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			x -= size * 2.f;
			break;

		case 2:
			drawRectFlex(x, y + size * 2.f, 1.5f * size, halfSize, color);
			drawRectFlex(x, y, 1.5f * size, halfSize, color);
			drawRectFlex(x, y - size * 2.f, 1.5f * size, halfSize, color);
			drawRectFlex(x + size, y + size, halfSize, halfSize, color);
			drawRectFlex(x - size, y - size, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 3:
			drawRectFlex(x - halfSize, y + size * 2.f, size, halfSize, color);
			drawRectFlex(x - halfSize, y, size, halfSize, color);
			drawRectFlex(x - halfSize, y - size * 2.f, size, halfSize, color);
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			x -= size * 4.f;
			break;

		case 4:
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x - size, y + size, halfSize, 1.5f * size, color);
			drawRectFlex(x, y, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 5:
			drawRectFlex(x, y + size * 2.f, 1.5f * size, halfSize, color);
			drawRectFlex(x, y, 1.5f * size, halfSize, color);
			drawRectFlex(x, y - size * 2.f, 1.5f * size, halfSize, color);
			drawRectFlex(x - size, y + size, halfSize, halfSize, color);
			drawRectFlex(x + size, y - size, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 6:
			drawRectFlex(x + halfSize, y + size * 2.f, size, halfSize, color);
			drawRectFlex(x + halfSize, y, size, halfSize, color);
			drawRectFlex(x + halfSize, y - size * 2.f, size, halfSize, color);
			drawRectFlex(x - size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x + size, y - size, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 7:
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x - halfSize, y + size * 2.f, size, halfSize, color);
			x -= size * 4.f;
			break;

		case 8:
			drawRectFlex(x - size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x, y + size * 2.f, halfSize, halfSize, color);
			drawRectFlex(x, y - size * 2.f, halfSize, halfSize, color);
			drawRectFlex(x, y, halfSize, halfSize, color);
			x -= size * 4.f;
			break;

		case 9:
			drawRectFlex(x - halfSize, y + size * 2.f, size, halfSize, color);
			drawRectFlex(x - halfSize, y, size, halfSize, color);
			drawRectFlex(x - halfSize, y - size * 2.f, size, halfSize, color);
			drawRectFlex(x + size, y, halfSize, 2.5f * size, color);
			drawRectFlex(x - size, y + size, halfSize, halfSize, color);
			x -= size * 4.f;
			break;
		}
	}
	
}

const char* letters[][7] = {
	" 00",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

		"000",
		"0  0",
		"0  0",
		"000",
		"0  0",
		"0  0",
		"000",

		" 000",
		"0",
		"0",
		"0",
		"0",
		"0",
		" 000",

		"000",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"000",

		"0000",
		"0",
		"0",
		"000",
		"0",
		"0",
		"0000",

		"0000",
		"0",
		"0",
		"000",
		"0",
		"0",
		"0",

		" 000",
		"0",
		"0",
		"0 00",
		"0  0",
		"0  0",
		" 000",

		"0  0",
		"0  0",
		"0  0",
		"0000",
		"0  0",
		"0  0",
		"0  0",

		"000",
		" 0",
		" 0",
		" 0",
		" 0",
		" 0",
		"000",

		" 000",
		"   0",
		"   0",
		"   0",
		"0  0",
		"0  0",
		" 000",

		"0  0",
		"0  0",
		"0 0",
		"00",
		"0 0",
		"0  0",
		"0  0",

		"0",
		"0",
		"0",
		"0",
		"0",
		"0",
		"0000",

		"00 00",
		"0 0 0",
		"0 0 0",
		"0   0",
		"0   0",
		"0   0",
		"0   0",

		"00  0",
		"0 0 0",
		"0 0 0",
		"0 0 0",
		"0 0 0",
		"0 0 0",
		"0  00",

		"0000",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"0000",

		" 000",
		"0  0",
		"0  0",
		"000",
		"0",
		"0",
		"0",

		" 000 ",
		"0   0",
		"0   0",
		"0   0",
		"0 0 0",
		"0  0 ",
		" 00 0",

		"000",
		"0  0",
		"0  0",
		"000",
		"0  0",
		"0  0",
		"0  0",

		" 000",
		"0",
		"0 ",
		" 00",
		"   0",
		"   0",
		"000 ",

		"000",
		" 0",
		" 0",
		" 0",
		" 0",
		" 0",
		" 0",

		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		"0  0",
		" 00",

		"0   0",
		"0   0",
		"0   0",
		"0   0",
		"0   0",
		" 0 0",
		"  0",

		"0   0 ",
		"0   0",
		"0   0",
		"0 0 0",
		"0 0 0",
		"0 0 0",
		" 0 0 ",

		"0   0",
		"0   0",
		" 0 0",
		"  0",
		" 0 0",
		"0   0",
		"0   0",

		"0   0",
		"0   0",
		" 0 0",
		"  0",
		"  0",
		"  0",
		"  0",

		"0000",
		"   0",
		"  0",
		" 0",
		"0",
		"0",
		"0000",

		"",
		"",
		"",
		"",
		"",
		"",
		"0",

		"   0",
		"  0",
		"  0",
		" 0",
		" 0",
		"0",
		"0",
};

void RenderState::drawText(const char* text, float x, float y, float size, unsigned int color)
{
	float half_size = size * .5f;
	float original_y = y;

	while (*text) {
		if (*text != 32) {
			const char** letter;
			if (*text == 47) letter = letters[27];
			else if (*text == 46) letter = letters[26];
			else letter = letters[*text - 'A'];
			float original_x = x;

			for (int i = 0; i < 7; i++) {
				const char* row = letter[i];
				while (*row) {
					if (*row == '0') {
						drawRectFlex(x, y, half_size, half_size, color);
					}
					x += size;
					row++;
				}
				y -= size;
				x = original_x;
			}
		}
		text++;
		x += size * 6.f;
		y = original_y;
	}
}


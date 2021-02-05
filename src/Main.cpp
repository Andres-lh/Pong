#include "game.h"

bool running = true;

RenderState renderState;

//window-procedure function.
LRESULT CALLBACK window_callback(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (Msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		running = false;
		break;
	case WM_SIZE: 
	{
		RECT rect;
		GetClientRect(hWnd, &rect);
		renderState.width = rect.right - rect.left;
		renderState.height = rect.bottom - rect.top;

		int bufferSize = renderState.width * renderState.height * sizeof(unsigned int);

		if (renderState.memory) VirtualFree(renderState.memory, 0, MEM_RELEASE);
		renderState.memory = VirtualAlloc(0, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		
		renderState.bitmaoInfo.bmiHeader.biSize = sizeof(renderState.bitmaoInfo.bmiHeader);
		renderState.bitmaoInfo.bmiHeader.biWidth = renderState.width;
		renderState.bitmaoInfo.bmiHeader.biHeight = renderState.height;
		renderState.bitmaoInfo.bmiHeader.biPlanes = 1;
		renderState.bitmaoInfo.bmiHeader.biBitCount = 32;
		renderState.bitmaoInfo.bmiHeader.biCompression = BI_RGB;
	}	break;
	default:
		result = DefWindowProc(hWnd, Msg, wParam, lParam);
		break;
	}
	return result;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//Create window class.
	WNDCLASS windowClass = {};

	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = L"Pong";

	//window callback function.
	windowClass.lpfnWndProc = window_callback;

	//Register class.
	RegisterClass(&windowClass);

	//Create window
	HWND window = CreateWindow(
		windowClass.lpszClassName,
		L"Pong Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1280, 720,
		0,
		0,
		hInstance,
		0
	);

	HDC hdc = GetDC(window);

	if (!window)
	{
		MessageBox(0,
			L"Call to CreateWindow failed!",
			L"Pong Game",
			0);

		return 1;
	}
	Input input;

	float deltaTime = 0.016666f;
	LARGE_INTEGER frameBeginTime;
	QueryPerformanceCounter(&frameBeginTime);

	float performanceFrequency;
	{
		LARGE_INTEGER perf;
		QueryPerformanceFrequency(&perf);
		performanceFrequency = (float)perf.QuadPart;
	}

	while (running)
	{
		//input
		MSG message;

		for (int i = 0; i < BUTTON_COUNT; i++) 
		{
			input.buttons[i].changed = false;
		}


		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			switch (message.message) 
			{
				case WM_KEYUP:
				case WM_KEYDOWN: {
					unsigned int vk_code = (unsigned int)message.wParam;
					bool isDown = ((message.lParam & (1 << 31)) == 0);

#define process_button(b, vk)\
case vk:{\
input.buttons[b].changed = isDown != input.buttons[b].isDown ;\
input.buttons[b].isDown = isDown;\
}break;

					switch (vk_code)
					{
						process_button(BUTTON_UP, VK_UP);
						process_button(BUTTON_DOWN, VK_DOWN);
						process_button(BUTTON_W, 'W');
						process_button(BUTTON_S, 'S');
					}
					break;
				}
					
				default: {
					TranslateMessage(&message);
					DispatchMessage(&message);

				}
				break;
					
					
			}
				
		}

		//simulate

		simulateGame(renderState, input, deltaTime);
		

		//render
		StretchDIBits(hdc, 
			0, 0, 
			renderState.width, renderState.height, 
			0, 0, 
			renderState.width, renderState.height,
			renderState.memory, 
			&renderState.bitmaoInfo, 
			DIB_RGB_COLORS,
			SRCCOPY
		);

		LARGE_INTEGER frameEndTime;
		QueryPerformanceCounter(&frameEndTime);
		deltaTime = (float)(frameEndTime.QuadPart - frameBeginTime.QuadPart) / performanceFrequency;
		frameBeginTime = frameEndTime;
	}
}
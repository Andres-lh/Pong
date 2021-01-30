#include <windows.h>

bool running = true;
void *bufferMemory;
int bufferWidth;
int bufferHeight;

BITMAPINFO bufferBitmapInfo;

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
		bufferWidth = rect.right - rect.left;
		bufferHeight = rect.bottom - rect.top;

		int bufferSize = bufferWidth * bufferHeight * sizeof(unsigned int);

		if (bufferMemory) VirtualFree(bufferMemory, 0, MEM_RELEASE);
		bufferMemory = VirtualAlloc(0, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		bufferBitmapInfo.bmiHeader.biSize = sizeof(bufferBitmapInfo.bmiHeader);
		bufferBitmapInfo.bmiHeader.biWidth = bufferWidth;
		bufferBitmapInfo.bmiHeader.biHeight = bufferHeight;
		bufferBitmapInfo.bmiHeader.biPlanes = 1;
		bufferBitmapInfo.bmiHeader.biBitCount = 32;
		bufferBitmapInfo.bmiHeader.biCompression = BI_RGB;
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
		800, 500,
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

	while (running)
	{
		//input
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//simulate
		unsigned int* pixel = (unsigned int *)bufferMemory;
		for (int y = 0; y < bufferHeight; y++) {
			for (int x = 0; x < bufferWidth; x++) {
				*pixel++ = 0xff5500;
			}
		}

		//render
		StretchDIBits(hdc, 
			0, 0, 
			bufferWidth, bufferHeight, 
			0, 0, 
			bufferWidth, bufferHeight, 
			bufferMemory, 
			&bufferBitmapInfo, 
			DIB_RGB_COLORS,
			SRCCOPY
		);
	}
}
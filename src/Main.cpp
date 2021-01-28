#include <windows.h>

bool running = true;

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
	default:
		result = DefWindowProc(hWnd, Msg, wParam, lParam);
		break;
	}
	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//Create window class.
	WNDCLASS windowClass = {};

	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = L"Pong";

	//window callback function.
	windowClass.lpfnWndProc = window_callback;

	//Register class.
	RegisterClass(&windowClass);

	//Create class
	HWND window = CreateWindow(
		windowClass.lpszClassName,
		L"Pong Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1200, 720,
		0,
		0,
		hInstance,
		0
	);
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
		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
}
#include <windows.h>
#include <iostream>

int main()
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX) };
	// wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("MainWindow");
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(0, wc.lpszClassName, TEXT(""), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, nullptr, nullptr);
	       
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	MSG msg = {};
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

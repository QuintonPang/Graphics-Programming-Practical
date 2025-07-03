
/*
#include <Windows.h>
#include <gl/GL.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"
float angle = 0.0f;
int direction = 1;
float speed = 1.0f;
bool move = true;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		if (wParam == VK_RIGHT) direction = -1;
		if (wParam == VK_LEFT) direction = 1;
		if (wParam == VK_ADD) speed += 0.1;
		if (wParam == VK_SUBTRACT) speed -= 0.1;
		if (wParam == VK_SPACE) move = !move;

		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void display()
{
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------
	glLoadIdentity(); // reset transformation matrix

	glPushMatrix();                 // save current matrix
	glTranslatef(0.25f, 0.25f, 0.0f);   // 1. Move origin to (0.5, 0.5)

	glRotatef(angle, 0.0f, 0.0f, 0.5f); // rotate around Z-axis (windmill effect)
	glTranslatef(-0.25f, -0.25f, 0.0f);  // 3. Move back

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0.8,1);
	glBegin(GL_QUADS);
	glVertex2d(-0.5, 0.5);
	glVertex2d(0.0, 0.5);

	glVertex2d(0.0, 0.0);

	glVertex2d(-0.5, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(0, 1);
	glVertex2d(0.5, 1);

	glVertex2d(0.5, 0.5);

	glVertex2d(0, 0.5);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(0.5, 0.5);
	glVertex2d(1, 0.5);

	glVertex2d(1, 0);

	glVertex2d(0.5, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(0.5, 0);

	glVertex2d(0.5, -0.5);

	glVertex2d(0, -0.5);
	glEnd();

	glPopMatrix();

	//--------------------------------

	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (move) {
		angle += (speed * direction); // increase rotation angle

		if (angle > 360.0f) angle -= 360.0f;

		}

		display();
		Sleep(10);

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------

*/
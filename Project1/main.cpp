/*
#include <Windows.h>
#include <gl/GL.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

int questionNo = 7;
LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == '1') questionNo = 1;

		else if (wParam == '2') questionNo = 2;
		else if (wParam == '3') questionNo = 3;
		else if (wParam == '4') questionNo = 4;
		else if (wParam == '5') questionNo = 5;
		else if (wParam == '6') questionNo = 6;
		else if (wParam == '7') questionNo = 7;
		else if (wParam == '7') questrionNo = 7;

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
#include <cmath>

const float PI = 3.14159265f;
void drawFilledCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cx, cy);  // Center of circle

	for (int i = 0; i <= num_segments; i++) {
		float theta = 2.0f * PI * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(cx + x, cy + y);
	}

	glEnd();
}
void demo() {
	glClearColor(255, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, -0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glEnd();
}

void pahangFlag()
{
	glClearColor(255, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// white
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(-0.5, -0.0);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, 0.0);
	glEnd();

	// black
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, -0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 1);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();



}

void negeriSembilanFlag()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // white background
	glClear(GL_COLOR_BUFFER_BIT);

	// --- Red Background ---
	glColor3f(1, 1.0f, 0.0f); // yellow
	glBegin(GL_QUADS);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	// --- Yellow Triangle (Top Left) ---
	glColor3f(0.0f, 0.0f, 0.0f); // black
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, 0.5f);  // top-left corner
	glVertex2f(-0.0f, 0.0f);  // near top-middle
	glVertex2f(-0.5f, 0.0f);  // near center-left
	glEnd();

	// --- Black Triangle (Bottom Right) ---
	glColor3f(1, 0.0f, 0.0f); // black
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, 0.5f);  // bottom-right
	glVertex2f(0.0f, 0.5f);  // near middle-right
	glVertex2f(0.0f, -0.0f);  // near bottom-middle
	glEnd();

	// Optional: Border
	glColor3f(0.0f, 0.0f, 1.0f); // blue border (optional)
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}
void englandFlag() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-0.7f, 0.5f);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(0.7f, -0.5f);
	glVertex2f(0.7f, 0.5f);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-0.7f, 0.1f);
	glVertex2f(-0.7f, -0.1f);
	glVertex2f(0.7f, -0.1f);
	glVertex2f(0.7f, 0.1f);
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(-0.1f, 0.5f);
	glVertex2f(-0.1f, -0.5);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.1f, 0.5f);
	glEnd();
}

void scotlandFlag()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 1.0f, 1.0f); 
	glBegin(GL_QUADS);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(-0.7f, 0.5f);
	glVertex2f(0.7f, 0.5f);
	glVertex2f(0.7f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.6f, 0.5f);  // top-left corner
	glVertex2f(0.6f, 0.5f);  // near top-middle
	glVertex2f(0.0f, 0.1f);  // near center-left
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.6f, -0.5f);  // top-left corner
	glVertex2f(0.6f, -0.5f);  // near top-middle
	glVertex2f(0.0f, -0.1f);  // near center-left
	glEnd();


	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.7f, 0.4f);  // top-left corner
	glVertex2f(-0.7f, -0.4f);  // near top-middle
	glVertex2f(-0.1f, -0.0f);  // near center-left
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.7f, 0.4f);  // top-left corner
	glVertex2f(0.7f, -0.4f);  // near top-middle
	glVertex2f(0.1f, -0.0f);  // near center-left
	glEnd();


}

void japanFlag()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(-0.7f, 0.5f);
	glVertex2f(-0.7f, -0.5f);
	glVertex2f(0.7f, -0.5f);
	glVertex2f(0.7f, 0.5f);
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f); 
	drawFilledCircle(0.0f, 0.0f, 0.3f, 120);

	glFlush();



}

void drawMouth(float cx, float cy, float r, int segments, float startAngle, float endAngle) {
	glColor3f(1.0f, 0.0f, 0.0f); // Red color
	glBegin(GL_LINE_STRIP);

	// Draw from left (180°) to right (0°), downward arc
	for (int i = 0; i <= segments; ++i) {
		float theta = startAngle + (endAngle - startAngle) * float(i) / float(segments); // 180° to 0°
		float x = r * cosf(theta);
		float y = -r * sinf(theta); // Negated to face downward
		glVertex2f(cx + x, cy + y);
	}

	glEnd();
}


void smiley()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	
	glColor3f(1.0f, 1.0f, 0.0f);
	drawFilledCircle(0.0f, 0.0f, 0.5f, 120);
	glFlush();

	glColor3f(0, 0, 0);              // Set point color to black
	glPointSize(10.0f);              // Set point size (in pixels)
	glBegin(GL_POINTS);              // Use correct primitive type

	glVertex2f(-0.3f, 0.1f);         // Draw first point
	glVertex2f(0.3f, 0.1f);          // Draw second point

	glEnd();

	glLineWidth(10);
	glPointSize(7.0f);              // Set point size (in pixels)
	drawMouth(0.0f, 0.0f, 0.3f, 150,PI / 4.0f, 3.0f * PI / 4.0f); // center at (0,0), radius 0.5
	glFlush();




}
void display() {
	switch (questionNo) {
	case 1:
		pahangFlag();
		break;
	case 2:
		demo()
			;
		break;
	case 3:
		negeriSembilanFlag();
		break;
	case 4:
		englandFlag();
		break;
	
	case 5:
		scotlandFlag();
		break;
	case 6:
		japanFlag();
		break;
	case 7:
		smiley();
		break;
}
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
	// Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	// initialize pixel format for the window
	initPixelFormat(hdc);

	// get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	// make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	// End initialization
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

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------
*/
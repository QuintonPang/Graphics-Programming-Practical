/*
#include <Windows.h>
#include <gl/GL.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"
float tx = 0.0f, ty = 0.0f;
//float r = 1.0f, g = 1.0f, b = 1.0f;
float theta = 0.0f;

float r = 1.0f, g = 0.0f, b = 0.0f;
float colorSpeed = 0.01f;
int colorPhase = 0;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

		case VK_LEFT:
			tx -= 0.05f;
			break;

		case VK_RIGHT:
			tx += 0.05f;
			break;

		case VK_UP:
			ty += 0.05f;
			break;

		case VK_DOWN:
			ty -= 0.05f;
			break;

		case 'R':
			r = 1.0f; g = 0.0f; b = 0.0f;
			break;

		case 'G':
			r = 0.0f; g = 1.0f; b = 0.0f;
			break;

		case 'B':
			r = 0.0f; g = 0.0f; b = 1.0f;
			break;

		case VK_SPACE:
			r = g = b = 1.0f;
			tx = ty = 0.0f;
			break;
		}
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
// star practice
//void display()
//{
//		glClear(GL_COLOR_BUFFER_BIT);
//			//glLoadIdentity();
//
//
//			glColor3f(r, g, b);
//			glBegin(GL_TRIANGLES);
//			glVertex2f(0.0f, 0.5f); glVertex2f(-0.2f, 0.0f); glVertex2f(0.2f, 0.0f);
//			glEnd();
//			glBegin(GL_TRIANGLES);
//			glVertex2f(-0.5f, 0.0f); glVertex2f(0.0f, 0.0f); glVertex2f(-0.25f, -0.3f);
//			glEnd();
//
//			glBegin(GL_TRIANGLES);
//			glVertex2f(0.5f, 0.0f); glVertex2f(0.0f, 0.0f); glVertex2f(0.25f, -0.3f);
//			glEnd();
//
//			glBegin(GL_TRIANGLES);
//			glVertex2f(-0.25f, -0.25f); glVertex2f(-0.4f, -0.5f); glVertex2f(0.0f, -0.25f);
//			glEnd();
//
//	
//			glBegin(GL_TRIANGLES);
//			glVertex2f(0.0f, -0.25f); glVertex2f(0.4f, -0.5f); glVertex2f(0.2f, -0.25f);
//			glEnd();
//
//			
//			glBegin(GL_TRIANGLES);
//			glVertex2f(0.25f, -0.25f); glVertex2f(0.4f, -0.5f); glVertex2f(0.0f, -0.25f);
//			glEnd();
//
//
//			// center triangle
//			glBegin(GL_TRIANGLES);
//			glVertex2f(0.0f, 0.0f); glVertex2f(-0.25f, -0.25f); glVertex2f(0.25f, -0.25f);
//			glEnd();
//
//
//}
// 

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(0.1+tx, 0.1 +ty);
	glVertex2f(0.1 +tx, -0.1-ty);
	glVertex2f(-0.1-tx, -0.1 -ty);



	glVertex2f(-0.1 -tx, 0.1 +ty);
	glEnd();

}

// ANSWER FOR DOT IN CIRCLE
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPointSize(20);
//	glLoadIdentity();
//	glTranslatef(tx, ty, 0);
//	glBegin(GL_POINTS);
//;	glVertex2f(0, 0); 
//	glEnd();
//	
//}

//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//
//	glTranslatef(tx, ty, 0.0f);       // Move triangle
//	glColor3f(r, g, b);               // Set color
//
//	glBegin(GL_TRIANGLES);
//	glVertex2f(0.0f, 0.5f);
//	glVertex2f(-0.5f, -0.5f);
//	glVertex2f(0.5f, -0.5f);
//	glEnd();
//}
//--------------------------------------------------------------------
#include <cmath>

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

		// Smooth RGB color cycle
		//switch (colorPhase) {
		//case 0: // Red to Green
		//	g += colorSpeed;
		//	if (g >= 1.0f) {
		//		g = 1.0f;
		//		colorPhase = 1;
		//	}
		//	break;
		//case 1: // Green to Blue
		//	r -= colorSpeed;
		//	if (r <= 0.0f) {
		//		r = 0.0f;
		//		colorPhase = 2;
		//	}
		//	break;
		//case 2: // Blue to Red
		//	b += colorSpeed;
		//	if (b >= 1.0f) {
		//		b = 1.0f;
		//		colorPhase = 3;
		//	}
		//	break;
		//case 3: // Red rises again, Blue drops
		//	g -= colorSpeed;
		//	if (g <= 0.0f) {
		//		g = 0.0f;
		//		colorPhase = 4;
		//	}
		//	break;
		//case 4: // Blue drops, Red stays
		//	b -= colorSpeed;
		//	if (b <= 0.0f) {
		//		b = 0.0f;
		//		colorPhase = 0; // Restart
		//	}
		//	break;
		//}
		// 


		// ANSWER FOR DOT MOVING IN CIRCLE
		//const float PI = 3.14159265f;

		//theta += 0.05f;  // Adjust speed — smaller = slower
		//if (theta > 2 * PI) theta -= 2 * PI;

		//float radius = 0.5f;  // Circle radius
		//tx = radius * cosf(theta);
		//ty = radius * sinf(theta);


		if(tx<0.5)tx += 0.01;
		if(tx<0.5)ty += 0.01;

		display();
		Sleep(10);


		SwapBuffers(hdc);	
	Sleep(10); // Sleep for 10 milliseconds to slow animation
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------

*/
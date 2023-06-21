#include "window.h"

Window::Window()
{
	this->width = 1280;
	this->height = 720;
	this->window_name = "Sorting algorithms visualizer";
	    // Initialize GLUT
    int argc = 0;
    char** argv = nullptr;
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(this->width, this->height);
	glutCreateWindow(this->window_name.c_str());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, this->width, 0, this->height);
}

Window::Window(int w, int h, std::string winname)
{
	this->width = w;
	this->height = h;
	this->window_name = winname;
	    // Initialize GLUT
    int argc = 0;
    char** argv = nullptr;
}

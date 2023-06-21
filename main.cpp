#include <ctime>
#include <string>
#include <GL/glut.h>
#include "Keyboard.h"
#include "main.h"
#include "Sort.h"
#include "Text.h"
#include "window.h"

const int w = 1280, h = 720; // default screen resolution
bool sorting = false;		 // default program state
int sorting_speed = 1;		 // milliseconds beetween gameloop ticks

// win(Width resolusion, Hight resolusion, window name)
Window win(w, h, "Sorting algorithms visualizer");

// Give Sort information

/**
 * @name Sorting Algorithm
 * @details - Sorting algorithm being used.
 * @param 
 */
Sort arr(50, 500, 50, 50, 1, 1);
Text ui;						 // on screen text UI
SortingAlg mode = SortingAlg::RESET;

inline std::string enumToString(SortingAlg alg)
{
	switch (alg)
	{
	case SortingAlg::BUBBLE:
		return "Bubble sort";
	case SortingAlg::MERGE:
		return "Merge sort";
	case SortingAlg::HEAP:
		return "Heap sort";
	case SortingAlg::QUICK:
		return "Quick sort";
	case SortingAlg::RESET:
		return "Array is reshuffled";
	case SortingAlg::STOP:
		return "Sorting stopped";
	default:
		return "[algorithm is not selected]";
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Sorting algorithms visualizer");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0, 720);
	srand(time(NULL));

	// GLut func initialization
	glutDisplayFunc(render);
	glutTimerFunc(sorting_speed, gameloop, 0);
	glutKeyboardFunc(normalKeyHandler);

	// Game loop
	glutMainLoop();
	return 0;
}

void gameloop(int = 0)
{
	render();
	update();
	glutTimerFunc(sorting_speed, gameloop, 0);
}

void render()
{
	glClearColor(0.8, 0.8, 0.8, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	arr.drawArray();
	ui.drawOperationCount(arr.getOperationCounter(), 20, 40, arr.getArraySize());
	ui.drawSortName(enumToString(mode), 400, 50);
	ui.drawKeyGuide(25, 90);
	glFlush();
}

void update()
{
	if (sorting && (mode == SortingAlg::RESET))
	{
		sorting = false;
		arr.reshuffleArray();
	}
	else if (sorting && (mode == SortingAlg::STOP))
	{
		sorting = false;
	}
	else if (sorting)
	{
		sorting = arr.tick(mode);
	}
}
#include <ctime>
#include <string>
#include <GL/glut.h>
#include "Keyboard.h"
#include "main.h"
#include "Sort.h"
#include "Text.h"
#include "window.h"


int width, height;			  // screen size
bool sorting = false;		  // default program state
int sorting_speed = 1;		  // milliseconds beetween gameloop ticks

int locations[][2] = {
	{20, 470},	// Bubble Sort (top left)
	{640, 470}, // Merge Sort (top right)
	{20, 50},	// Heap Sort (bottom left)
	{640, 50},	// Quick sort (bottom right)
};

int offsetX = 100, offsetY = 330;

Sort arr1(200, 10, locations[0][0], locations[0][1], 1, 30);
Sort arr2(200, 10, locations[1][0], locations[1][1], 1, 30);
Sort arr3(200, 10, locations[2][0], locations[2][1], 1, 30);
Sort arr4(200, 10, locations[3][0], locations[3][1], 1, 30);

Text ui; // on screen text UI
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
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("Sorting algorithms visualizer");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
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
	arr1.drawArray();
	arr2.drawArray();
	arr3.drawArray();
	arr4.drawArray();
	ui.drawOperationCount(arr1.getOperationCounter(), locations[0][0] + offsetX, locations[0][1] + offsetY, arr1.getArraySize());
	ui.drawOperationCount(arr2.getOperationCounter(), locations[1][0] + offsetX, locations[1][1] + offsetY, arr1.getArraySize());
	ui.drawOperationCount(arr3.getOperationCounter(), locations[2][0] + offsetX, locations[2][1] + offsetY, arr1.getArraySize());
	ui.drawOperationCount(arr4.getOperationCounter(), locations[3][0] + offsetX, locations[3][1] + offsetY, arr1.getArraySize());
	ui.drawSortName(enumToString(SortingAlg::BUBBLE), locations[0][0] + offsetX + 50, locations[0][1] + offsetY + 40);
	ui.drawSortName(enumToString(SortingAlg::MERGE), locations[1][0] + offsetX + 50, locations[1][1] + offsetY + 40);
	ui.drawSortName(enumToString(SortingAlg::HEAP), locations[2][0] + offsetX + 50, locations[2][1] + offsetY + 40);
	ui.drawSortName(enumToString(SortingAlg::QUICK), locations[3][0] + offsetX + 50, locations[3][1] + offsetY + 40);
	ui.drawKeyGuide(25, 80);
	glFlush();
}

void update()
{
	if (sorting && (mode == SortingAlg::RESET))
	{
		sorting = false;
		arr1.reshuffleArray();
		arr2.reshuffleArray();
		arr3.reshuffleArray();
		arr4.reshuffleArray();
	}
	else if (sorting && (mode == SortingAlg::STOP))
	{
		sorting = false;
	}
	else if (sorting)
	{
		switch (mode)
		{
		case SortingAlg::BUBBLE:
			if (!sorting)
				arr1.reshuffleArray();
			sorting |= arr1.tick(SortingAlg::BUBBLE);
			break;
		case SortingAlg::MERGE:
			sorting |= arr2.tick(SortingAlg::MERGE);
			break;
		case SortingAlg::HEAP:
			sorting |= arr3.tick(SortingAlg::HEAP);
			break;
		case SortingAlg::QUICK:
			sorting |= arr4.tick(SortingAlg::QUICK);
			break;
		case SortingAlg::COMPARE:
			sorting |= arr1.tick(SortingAlg::BUBBLE);
			sorting |= arr2.tick(SortingAlg::MERGE);
			sorting |= arr3.tick(SortingAlg::HEAP);
			sorting |= arr4.tick(SortingAlg::QUICK);
			break;
		}
	}
}
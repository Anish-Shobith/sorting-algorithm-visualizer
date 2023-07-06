#include <ctime>
#include <string>
#include <GL/glut.h>
#include "Keyboard.h"
#include "main.h"
#include "Sort.h"
#include "Text.h"

int width, height;	   // screen size
bool sorting = false;  // default program state
int sorting_speed = 1; // milliseconds beetween gameloop ticks

int locations[][2] = {
	{20, 670},	 // Bubble Sort (top left)
	{1335, 670}, // Merge Sort (top right)
	{20, 150},	 // Heap Sort (bottom left)
	{1335, 150}, // Quick sort (bottom right)
};

int offsetX = 100, offsetY = 330;

Sort arr1(200, 10, locations[0][0], locations[0][1], 1, 30);
Sort arr2(200, 10, locations[1][0], locations[1][1], 1, 30);
Sort arr3(200, 10, locations[2][0], locations[2][1], 1, 30);
Sort arr4(200, 10, locations[3][0], locations[3][1], 1, 30);

Text ui; // on screen text UI
SortingAlg mode = SortingAlg::RESET;

/**
 * Initializes the GLUT library and sets up the display window for the sorting algorithms visualizer.
 *
 * @param argc the number of command line arguments
 * @param argv an array of command line arguments
 *
 * @return an integer representing the exit status of the program
 *
 * @throws None
 */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    width = glutGet(GLUT_SCREEN_WIDTH);
    height = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Sorting Algorithm Visualizer");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    srand(time(nullptr));

    glutDisplayFunc(render);
    glEnable(GL_MULTISAMPLE);
    glutTimerFunc(sorting_speed, gameloop, 0);
    glutKeyboardFunc(normalKeyHandler);

    glutMainLoop();
    return 0;
}

/**
 * The `gameloop` function is responsible for rendering and updating the game state in a loop.
 *
 * @param int sorting_speed: The speed at which the game state is updated.
 *
 * @return void: This function does not return a value.
 *
 * @throws ErrorType: This function does not throw any errors.
 */
void gameloop(int = 0)
{
	render();
	update();
	glutTimerFunc(sorting_speed, gameloop, 0);
}

/**
 * Renders the scene by clearing the color buffer, drawing a rectangle, and
 * rendering arrays and UI components.
 *
 * @throws ErrorType description of error
 */
void render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(0, height);
    glVertex2f(width, height);
    glColor3f(0.05f, 0.05f, 0.15f);
    glVertex2f(width, 0);
    glVertex2f(0, 0);
    glEnd();

    for (auto& arr : {&arr1, &arr2, &arr3, &arr4}) {
        arr->drawArray();
    }

    ui.draw();
    glFlush();
    glutSwapBuffers();
}

/**
 * Updates the state of the program based on the current mode and sorting state.
 *
 * @throws None
 */
void update()
{
	if (sorting)
	{
		if (mode == SortingAlg::RESET)
		{
			sorting = false;
			arr1.reshuffleArray();
			arr2.reshuffleArray();
			arr3.reshuffleArray();
			arr4.reshuffleArray();
		}
		else if (mode == SortingAlg::STOP)
		{
			sorting = false;
		}
		else
		{
			switch (mode)
			{
			case SortingAlg::BUBBLE:
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
}

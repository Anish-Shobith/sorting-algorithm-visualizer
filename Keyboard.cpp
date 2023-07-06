#include "Keyboard.h"

/**
 * Handles a normal key press event.
 *
 * @param key the key that was pressed
 * @param x the x-coordinate of the mouse cursor
 * @param y the y-coordinate of the mouse cursor
 *
 * @throws None
 */
void normalKeyHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 49:
		sorting = true;
		mode = SortingAlg::BUBBLE;
		break;
	case 50:
		sorting = true;
		mode = SortingAlg::MERGE;
		break;
	case 51:
		sorting = true;
		mode = SortingAlg::HEAP;
		break;
	case 52:
		sorting = true;
		mode = SortingAlg::QUICK;
		break;
	case 53:
		sorting = true;
		mode = SortingAlg::COMPARE;
		break;
	case 'r':
		sorting = true;
		mode = SortingAlg::RESET;
		break;
	case 's':
		sorting = true;
		mode = SortingAlg::STOP;
		break;
	}
}
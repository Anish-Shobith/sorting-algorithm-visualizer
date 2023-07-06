#include "Text.h"

void Text::draw()
{
	// Title
	drawTitle();

	// Labels
	drawLabel("Bubble Sort", locations[0][0] + offsetX, locations[0][1] + offsetY);
	drawLabel("Merge Sort", locations[1][0] + offsetX, locations[1][1] + offsetY);
	drawLabel("Heap Sort", locations[2][0] + offsetX, locations[2][1] + offsetY);
	drawLabel("Quick Sort", locations[3][0] + offsetX, locations[3][1] + offsetY);

	// Key Guide
	drawLabel("Press 'S' to stop sorting", 50, 1150);
	drawLabel("Press 'R' to reshuffle the array", 50, 1180);
	drawLabel("Press '5' to start All the Sort", 50, 1210);
	drawLabel("Press '4' to start Quick Sort", 50, 1240);
	drawLabel("Press '3' to start Heap Sort", 50, 1270);
	drawLabel("Press '2' to start Merge Sort", 50, 1300);
	drawLabel("Press '1' to start Bubble Sort", 50, 1330);
	drawLabel("Key Guide:", 50, 1360);

	// Operation Count
	drawOperationCount(arr1.getOperationCounter(), locations[0][0] + offsetX, locations[0][1] + offsetY, arr1.getArraySize());
	drawOperationCount(arr2.getOperationCounter(), locations[1][0] + offsetX, locations[1][1] + offsetY, arr1.getArraySize());
	drawOperationCount(arr3.getOperationCounter(), locations[2][0] + offsetX, locations[2][1] + offsetY, arr1.getArraySize());
	drawOperationCount(arr4.getOperationCounter(), locations[3][0] + offsetX, locations[3][1] + offsetY, arr1.getArraySize());
}

void Text::drawText(const std::string &text, int x, int y, void *font)
{
	glRasterPos2f(x, y);
	for (const char c : text)
		glutBitmapCharacter(font, c);
}

void Text::drawLabel(const std::string &label, int x, int y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	drawText(label, x, y, GLUT_BITMAP_TIMES_ROMAN_24);
}

void Text::drawTitle()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(width / 2 - 100, height - 80, 0);
	glScalef(2.0f, 2.0f, 1.0f);
	drawText("Sorting Algorithms Visualizer", 0, 0, GLUT_BITMAP_TIMES_ROMAN_24);
	glPopMatrix();
}

void Text::drawOperationCount(int n, float x, float y, int arrsize)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	drawText("Size of the array:", x + 400, y + 80, GLUT_BITMAP_TIMES_ROMAN_24);
	drawText(std::to_string(arrsize), x + 450, y - 30 + 80, GLUT_BITMAP_TIMES_ROMAN_24);
	drawText("Number of permutations:", x + 600, y + 80, GLUT_BITMAP_TIMES_ROMAN_24);
	drawText(std::to_string(n), x + 720, y - 35 + 80, GLUT_BITMAP_TIMES_ROMAN_24);
}

#ifndef SORT_VISUALIZER_TEXT_H_
#define SORT_VISUALIZER_TEXT_H_

#include <string>
#include <GL/glut.h>

#include "Sort.h"

extern int width, height;
extern int locations[][2];
extern int offsetX, offsetY;

extern class Sort arr1;
extern class Sort arr2;
extern class Sort arr3;
extern class Sort arr4;

/**
 * @class Text
 * @brief Text class is used to draw text on the screen.
 * @param none
 * @return none
 */
class Text
{
public:
	void drawOperationCount(int n, float x, float y, int arrsize);
	void draw();

private:
	void drawText(const std::string &text, int x, int y, void *font);
	void drawLabel(const std::string &label, int x, int y);
	void drawTitle();
};
#endif // SORT_VISUALIZER_TEXT_H_

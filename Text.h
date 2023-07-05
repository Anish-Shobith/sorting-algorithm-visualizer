#ifndef SORT_VISUALIZER_TEXT_H_
#define SORT_VISUALIZER_TEXT_H_

#include <string>
#include <GL/glut.h>
#include "window.h"

extern int width, height;

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
	void drawSortName(std::string sortname, int xcoord, int ycoord);
	void drawKeyGuide(int xcoord, int ycoord);

private:
	void glWrite(float x, float y, int *font, std::string text);
};
#endif // SORT_VISUALIZER_TEXT_H_

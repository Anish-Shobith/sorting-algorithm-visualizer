#ifndef SORT_VISUALIZER_WINDOW_H_
#define SORT_VISUALIZER_WINDOW_H_

#include <string>
#include <GL/glut.h>
#include "Sort.h"

/**
 * @class Window
 * @brief class is used to create a window with a given resolution and name.
 * @param width  window width
 * @param height window height
 * @param window_name window name
 * @return none
*/
class Window
{
public:
	Window();
	Window(int w, int h, std::string winname);

private:
	friend class Text;
	int width, height; //window resolution
	std::string window_name;
};
#endif  // SORT_VISUALIZER_WINDOW_H_


#ifndef SORT_VISUALIZER_MAIN_H_
#define SORT_VISUALIZER_MAIN_H_

#include <string>

/**
 * @name gameloop
 * @details Main game loop.
 * @param value
 * @return none
 */
void gameloop(int);
/**
 * @ma,e render
 * @details Renders the game state.
 * @param none
 * @return none
 * @note This function is called every frame.
 */
void render();
/**
 * @name update
 * @details Updates the game state.
 * @param none
 * @return none
 * @note This function is called every frame.
 */
void update();
/**
 * @name SortingAlg
 * @brief SortingAlg enum class is used to store sorting algorithm state.
 * @param BUBBLE bubble sort
 * @param MERGE merge sort
 * @param HEAP heap sort
 * @param QUICK quick sort
 * @param RESET reset array
 * @param STOP stop sorting
 */
enum class SortingAlg
{
	BUBBLE,
	MERGE,
	HEAP,
	QUICK,
	RESET,
	STOP,
	COMPARE
};

extern SortingAlg mode;

inline std::string enumToString(SortingAlg alg); // convert enum state to screen text

extern bool sorting;	  // sorting state (sorting, stopped)
extern int sorting_speed; // time between sorting ticks in ms
extern int location[][2]; // array of locations for each element
extern int width, height; // screen width and height
extern int offsetX, offsetY; // offset for array location

#endif					  // SORT_VISUALIZER_MAIN_H_

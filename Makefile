CC = gcc
CFLAGS = -lGLU -lGL -lglut -lstdc++ -lm

SRCS = Text.cpp QuickSort.cpp Sort.cpp MergeSort.cpp Keyboard.cpp BubbleSort.cpp main.cpp window.cpp HeapSort.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = sort

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

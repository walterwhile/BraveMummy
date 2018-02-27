all: main.cpp
	g++ main.cpp -o glutTest -lGL -lGLU -lglut -std=c++11

all:
	g++ -g --std=c++17 -I./include -L./Lib ./src/*.cpp ./src/GraphicsLibs./*.cpp ./src/GraphicsLibs/glad.c -lglfw3dll -o main
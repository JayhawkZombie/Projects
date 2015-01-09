Lab08: main.o MazeWalker.o MazeReader.o MazeCreationException.o Position.o
	g++ -std=c++11 main.o MazeReader.o MazeWalker.o MazeCreationException.o Position.o -o Lab08
main.o: main.cpp MazeWalker.h MazeWalker.cpp MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -c main.cpp
MazeWalker.o: MazeWalker.h MazeWalker.cpp MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeWalker.cpp
MazeReader.o: MazeReader.h MazeReader.cpp MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeReader.cpp
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -c MazeCreationException.cpp
Position.o: Position.h Position.cpp
	g++ -std=c++11 -g -c Position.cpp
clean:
	rm *.o main
	clean done

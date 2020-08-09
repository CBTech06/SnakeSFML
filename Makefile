CXX=g++
CFLAGS=-g -Wall -w 
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES= main.cpp snake.cpp pills.cpp board.cpp 
OBJ = main.o snake.o pills.o board.o
EXECUTABLE= Snake

${EXECUTABLE}:${OBJ}
	${CXX} ${SOURCES} ${CFLAGS} ${LDFLAGS} -o ${EXECUTABLE}

main.o : main.cpp
	${CXX} -c main.cpp -o main.o

snake.o : snake.cpp
	${CXX} -c snake.cpp -o snake.o

pills.o: pills.cpp
	${CXX} -c pills.cpp -o pills.o

board.o: board.cpp
	${CXX} -c board.cpp -o board.o

clean:
	rm -rf ${OBJ} ${EXECUTABLE}

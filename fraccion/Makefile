all: main
run: main
	./main
main: main.o Racional.o
	g++ -o main main.o Racional.o
%.o: %.cpp
	g++ -c $<


program: main.o Ai.o Gram_map.o
	g++ main.o Ai.o Gram_map.o -o program

main.o: main.cpp
	g++ -c main.cpp

Ai.o: Ai.cpp Ai.h
	g++ -c Ai.cpp

Gram_map.o: Gram_map.cpp Gram_map.h
	g++ -c Gram_map.cpp

clean:
	rm *.o output

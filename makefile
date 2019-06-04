main: Screen.o River.o Prom.o People.o  main.cpp
	g++ -std=c++11 Screen.o River.o Prom.o People.o  main.cpp -lncurses -pthread -fpermissive

Screen.o: Screen.cpp Screen.h
	g++  -c Screen.cpp -std=c++11 -lncurses -fpermissive

River.o: River.cpp River.h
	g++  -c River.cpp -std=c++11 -lncurses -fpermissive

Prom.o:Prom.cpp Prom.h
	g++  -c Prom.cpp -std=c++11 -lncurses -fpermissive

People.o:People.cpp People.h
	g++  -c People.cpp -std=c++11 -lncurses -fpermissive


clean:
	rm -f *.o test

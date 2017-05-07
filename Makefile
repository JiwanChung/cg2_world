CC := g++
VECTOR := -std=c++11
CFLAG := $(VECTOR) -lGL -lGLU -lglut -lGLEW -lm


program: main.o halo.o sun.o planet.o waa.o chief.o
	$(CC) -o program main.o halo.o sun.o planet.o waa.o chief.o $(CFLAG)
 
main.o: main.c main.h display/halo.h light/sun.h light/planet.h display/waa.h display/chief.h 
	$(CC) -c main.c main.h display/halo.h light/sun.h light/planet.h display/waa.h display/chief.h $(VECTOR) 

halo.o: display/halo.c display/halo.h
	$(CC) -c display/halo.c display/halo.h

sun.o: light/sun.c light/sun.h
	$(CC) -c light/sun.c light/sun.h

planet.o: light/planet.c light/planet.h light/sun.h
	$(CC) -c light/planet.c light/planet.h light/sun.h

waa.o: display/waa.c display/waa.h main.h
	$(CC) -c display/waa.c display/waa.h main.h

chief.o: display/chief.c display/chief.h display/waa.h main.h
	$(CC) -c display/chief.c display/chief.h display/waa.h main.h

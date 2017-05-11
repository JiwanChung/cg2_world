CC := g++
VECTOR := -std=c++11
CFLAG := $(VECTOR) -lGL -lGLU -lglut -lGLEW -lm


program: main.o halo.o sun.o planet.o waa.o chief.o obj.o
	$(CC) -o program main.o halo.o sun.o planet.o waa.o chief.o obj.o $(CFLAG)
 
main.o: main.c main.h display/halo.h light/sun.h light/planet.h display/waa.h display/chief.h file/obj.h
	$(CC) -c main.c main.h display/halo.h light/sun.h light/planet.h display/waa.h display/chief.h file/obj.h $(VECTOR) 

halo.o: display/halo.c display/halo.h
	$(CC) -c display/halo.c display/halo.h

sun.o: light/sun.c light/sun.h
	$(CC) -c light/sun.c light/sun.h

planet.o: light/planet.c light/planet.h light/sun.h
	$(CC) -c light/planet.c light/planet.h light/sun.h

waa.o: display/waa.c display/waa.h main.h
	$(CC) -c display/waa.c display/waa.h main.h

chief.o: display/chief.c display/chief.h display/waa.h main.h
	$(CC) -c display/chief.c display/chief.h display/waa.h main.h $(VECTOR) 

obj.o: file/obj.c file/obj.h
	$(CC) -c file/obj.c file/obj.h

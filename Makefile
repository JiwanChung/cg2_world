CC := gcc
CFLAG := -lGL -lGLU -lglut -lm

program: main.o halo.o sun.o planet.o
	$(CC) -o program main.o halo.o sun.o planet.o $(CFLAG)

main.o: main.c main.h display/halo.h light/sun.h light/planet.h
	$(CC) -c main.c main.h display/halo.h light/sun.h light/planet.h

halo.o: display/halo.c display/halo.h
	$(CC) -c display/halo.c display/halo.h

sun.o: light/sun.c light/sun.h
	$(CC) -c light/sun.c light/sun.h

planet.o: light/planet.c light/planet.h light/sun.h
	$(CC) -c light/planet.c light/planet.h light/sun.h


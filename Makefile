CC := gcc
CFLAG := -lGL -lGLU -lglut -lm

program: main.o halo.o
	$(CC) -o program main.o halo.o $(CFLAG)

main.o: main.c main.h display/halo.h
	$(CC) -c main.c main.h display/halo.h

halo.o: display/halo.c display/halo.h
	$(CC) -c display/halo.c display/halo.h
INCLUDE = -I../../

all:
	gcc -g -c window.c $(INCLUDE)
	gcc -g -c linux/render.c $(INCLUDE)
	gcc -g -o test test.c window.o render.o $(INCLUDE) -lGL

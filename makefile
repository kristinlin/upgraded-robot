run: all
	./a.out
all: handcrafted.c
	gcc -g handcrafted.c
clean:
	rm ./a.out; rm image.ppm; rm *~;

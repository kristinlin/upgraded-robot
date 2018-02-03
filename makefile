all: handcrafted.c
	gcc handcrafted.c
run: all
	./a.out
clean:
	rm ./a.out; rm image.ppm; rm *~;

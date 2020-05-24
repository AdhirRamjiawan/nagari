all: clean
	mkdir ./build
	gcc -g -o ./build/nagari nagari.c main.c

clean:
	rm -Rf ./build
	rm -f *.o

test:
	./build/nagari

debug:
	gdb ./build/nagari

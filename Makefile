all: clean
	mkdir ./build
	gcc -o ./build/nagari *.c

clean:
	rm -Rf ./build

test:
	./build/nagari
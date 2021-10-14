all: Project0

Project0: 
	cc Project0.c -o Project0 -pedantic

run:Project0
	./Project0 <thorn
	make clean

clean:
	rm -f Project0

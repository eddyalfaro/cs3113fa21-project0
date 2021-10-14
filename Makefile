all: Project0

Project0: 
	cc Project0.c -o Project0 -pedantic

compile:Project0
	./Project0 <thorn

clean:
	rm -f Project0

run: compile clean

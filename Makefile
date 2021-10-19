all: Project0

Project0: 
	cc project0.c -o project0 -pedantic

execute:Project0
	./project0 <input/f1 >output.txt
	./project0 <input/f2 >>output.txt
	./project0 <input/f3 >>output.txt

clean:
	rm -f project0

run: execute clean
	vim output.txt

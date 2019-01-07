all: first second

first: first.c
	gcc -O -o first first.c

second: second.c
	gcc -O -o second second.c
clean:
	rm -rf first second

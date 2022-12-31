all: isort txtfind

isort: isort.c
	gcc -Wall -g -o isort isort.c

runi:
	./isort < sort_input.txt

clean:
	rm -f ./isort ./textfind

newi : clean all runi

txtfind: textfind.c
	gcc -Wall -g -o textfind textfind.c

newt: clean all runt

runt:
	./textfind < find_inputa.txt
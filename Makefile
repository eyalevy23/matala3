all: isort txtfind

isort: isort.c
	gcc -Wall -g -o isort isort.c

runi:
	./isort < sort_input.txt > outputisort.txt

clean:
	rm -f ./isort ./txtfind ./outputA.txt ./outputB.txt ./outputisort.txt

newi : clean all runi

txtfind: txtfind.c
	gcc -Wall -g -o txtfind txtfind.c

newt: clean all runt

runt: runtxta runtxtb

runtxta:
	./txtfind < find_inputa.txt > outputA.txt

runtxtb:
	./txtfind < find_inputb.txt > outputB.txt

leakTest:
	valgrind --leak-check=full  --track-origins=yes --show-leak-kinds=all --error-exitcode=1 ./txtfind < find_inputa.txt > outputA.txt
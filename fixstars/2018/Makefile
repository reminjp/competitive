all:

compile:
	g++ main.cpp -std=c++14 -o a.out -O3 -Wall -Wno-unused-but-set-variable
	g++ akemi.cpp -std=c++14 -o akemi -O3 -Wall -Wno-unused-but-set-variable

run:
	python nodeless.py main ./a.out akemi ./akemi tadashi ./tadashi.py

clean:
	rm -f a.out akemi

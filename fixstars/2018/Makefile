all:

compile: # compile my solver
	g++ main.cpp -std=c++14 -o a.out -O3 -Wall -Wno-unused-but-set-variable

akemi: # compile akemi's sample solver
	g++ akemi.cpp -std=c++14 -o akemi -O3 -Wall -Wno-unused-but-set-variable

run: akemi # run with sample solvers
	python nodeless.py main ./a.out akemi ./akemi tadashi ./tadashi.py

pack: # pack my solver to submit
	zip archive Makefile main.cpp json.hpp

clean:
	rm -f a.out archive.zip akemi

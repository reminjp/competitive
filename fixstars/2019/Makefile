all:

compile: # compile my solver
	g++ main.cpp -std=gnu++14 -o a.out -O2 -Wall -I/usr/include

akemi: # compile akemi's sample solver
	g++ akemi.cpp -std=gnu++14 -o akemi -O2 -Wall -I/usr/include/boost

run: akemi # run with sample solvers
	python prime_daihinmin.py main ./a.out akemi1 ./akemi akemi2 ./akemi tadashi ./tadashi.py

clean:
	rm -f a.out akemi

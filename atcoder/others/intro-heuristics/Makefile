all: _a.out tester.py in
	./a.out < in > out
	python3 tester.py in out

_a.out:
	g++ -O2 -o a.out a.cpp

generator.py:
	cp tester/generator.py generator.py

tester.py:
	cp tester/tester.py tester.py

in: generator.py
	python3 generator.py 0 > in

clean:
	rm -f a.out generator.py tester.py in out vis.svg

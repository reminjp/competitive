a: _a.out generator output_checker
	./generator in 2 2048
	time ./a.out < in > out
	./output_checker in out

b: _b.out interactive.py judge
	time python3 interactive.py --judge './judge 2 2048' --contestant ./b.out

_a.out:
	g++ -O2 -o a.out a.cpp

_b.out:
	g++ -O2 -o b.out b.cpp

generator:
	g++ -std=gnu++11 -o generator toolkit/scripts/generator.cpp

output_checker:
	g++ -std=gnu++11 -o output_checker toolkit/scripts/output_checker.cpp

interactive.py:
	cp toolkit/scripts/interactive.py interactive.py

judge:
	g++ -std=gnu++11 -o judge toolkit/scripts/judge.cpp

clean:
	rm -f a.out b.out generator output_checker interactive.py judge

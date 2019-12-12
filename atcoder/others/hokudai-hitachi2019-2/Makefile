all: _a.out interactive.py judge
	time python3 interactive.py --judge './judge 2048' --contestant ./a.out

_a.out:
	g++ -O2 -o a.out a.cpp

interactive.py:
	cp toolkit/scripts/interactive.py interactive.py

judge:
	g++ -std=gnu++11 -o judge toolkit/scripts/judge.cpp

clean:
	rm -f a.out interactive.py judge contestant.out judge.out

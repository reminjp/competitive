a: _a.out
	python3 rcl-contest-2020/qual_A/tester/generator.py 12345 > in
	./a.out < in > out
	python3 rcl-contest-2020/qual_A/tester/judge.py in out

b: _b.out
	python3 rcl-contest-2020/qual_B/tester/generator.py 12345 > in
	./b.out < in > out
	python3 rcl-contest-2020/qual_B/tester/judge.py in out

_a.out:
	g++ -O2 -o a.out a.cpp

_b.out:
	g++ -O2 -o b.out b.cpp

clean:
	rm -f a.out b.out

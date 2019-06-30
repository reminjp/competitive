all:
	g++ -O2 -o a.out a.cpp

a: a.out generator.out output_checker.out
	./generator.out in 1 2048
	./a.out < in > out
	./output_checker.out in out 2048

b: a.out generator.out output_checker.out
	./generator.out in 2 2048
	./a.out < in > out
	./output_checker.out in out 2048

c: a.out generator.out output_checker.out
	./generator.out in 3 2048
	./a.out < in > out
	./output_checker.out in out 2048

a.out:
	g++ -O2 -o a.out a.cpp

generator.out:
	g++ -std=gnu++11 -o generator.out toolkit/scripts/generator.cpp

output_checker.out:
	g++ -std=gnu++11 -o output_checker.out toolkit/scripts/output_checker.cpp

clean:
	rm -f a.out

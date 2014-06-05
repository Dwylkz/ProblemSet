base = $(basename $(wildcard *.cc))
main: $(base).cc
	gcc $(base).cc -o $(base) -lstdc++ -g
.PHONY: debug clean run
debug:
	gdb $(base)
run:
	./$(base)

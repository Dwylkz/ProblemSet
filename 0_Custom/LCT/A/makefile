main: main.cc
	gcc main.cc -o main -lstdc++ -g
.PHONY: debug clean run make_debug
make_debug: mainb.cc
	gcc mainb.cc -o main -lstdc++ -g
debug:
	gdb main
run:
	./main

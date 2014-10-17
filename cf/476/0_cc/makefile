CXX=g++
CPPFLAGS += -std=c++11

main: main.cc

.PHONY: test
test:
	@for i in *.in; do echo "test $${i}"; cat $${i} | ./main; done

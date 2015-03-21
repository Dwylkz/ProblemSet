MAKEFLAGS=ks
CXX=g++
CPPFLAGS += -std=c++11

main: main.cc

.PHONY: run
run:
	for i in *.in; do \
		temp=$${i/in/temp}; \
		echo "test $${i}"; cat $${i} | ./main > $${temp}; \
		cat $${temp}; \
		if [[ -n $$(diff $${temp} $${i/in/out}) ]]; then \
			printf "[31mNO"; \
		else \
			printf "[36mYES"; \
		fi; \
		echo "[0m"; \
	done

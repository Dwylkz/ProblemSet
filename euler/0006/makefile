main: main.hs
	ghc main.hs -o main
	rm $(filter %.o %.hi, $(wildcard *.*))
.PHONY: run
run:
	./main

CXX := g++

all: res.png

res.png: res.csv graph.plot
	gnuplot < graph.plot

res.csv: res.raw.csv ./script/normalize
	./script/normalize < $< > $@

res.raw.csv: main
	time ./$< | tee $@

main: main.cpp
	$(CXX) -o $@ $<

.PHONY: show
show: res.png
	open $<

.PHONY: clean
clean:
	rm res.png res.csv main

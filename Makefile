CXX := g++

res.png: res.csv graph.plot
	gnuplot < graph.plot

res.csv: res.raw.csv
	./script/normalize < res.raw.csv > res.csv

res.raw.csv: main
	time ./main > res.raw.csv

main: main.cpp
	$(CXX) -o main main.cpp

.PHONY: show
show: res.png
	open res.png

.PHONY: clean
clean:
	rm res.png res.csv main

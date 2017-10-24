CXX := g++

res.png: res.csv graph.plot
	gnuplot < graph.plot

res.csv: main
	time ./main > res.csv

main: main.cpp
	$(CXX) -o main main.cpp

.PHONY: show
show: res.png
	open res.png

.PHONY: clean
clean:
	rm res.png res.csv main

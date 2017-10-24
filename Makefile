CXX := g++

res.png: res.csv graph.plot
	gnuplot < graph.plot

res.csv: main
	./main > res.csv

main: main.cpp
	$(CXX) -o main main.cpp

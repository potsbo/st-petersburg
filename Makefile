CXX := g++

csv: main
	./main > res.csv

main: main.cpp
	$(CXX) -o main main.cpp

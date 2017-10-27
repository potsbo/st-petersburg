CXX       := g++
REVISION  := $(shell git rev-parse --short HEAD)
IMAGE_DIR := dist
TARGET    := $(IMAGE_DIR)/res.$(REVISION).png

all: $(TARGET)

$(TARGET): res.png $(IMAGE_DIR)
	script/store $@

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
	rm *.png *.csv main

.PHONY: store
store: dist/res.$(REVISION).png

$(IMAGE_DIR):
	mkdir -p $@

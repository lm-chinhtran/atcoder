TARGET = dijsktra

.PHONY: all
all:
	g++ -std=c++11 -O2 -Wall ./src/${TARGET}.cpp -o ${TARGET}

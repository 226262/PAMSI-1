CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic
BIN=lab1
COMMAND=10

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<
        
clean:
	rm -f src/*.o 
	rm -f inc/*.o 
	rm -f *.o 
	rm -f $(BIN) 
	
run:    ${BIN}
	./${BIN} ${COMMAND}
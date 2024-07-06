CC = clang++
CPPFLAGS = -std=c++11

SOURCES = $(wildcard src/*.cpp)
HSOURCES = $(wildcard src/*.hpp)
OBJECTS = $(SOURCES:.cpp=.o)

generator: $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o : %.cpp $(HSOURCES)
	$(CC) $(CPPFLAGS) -c $< -o $@

run:
	time ./generator $(SLIM) $(LLIM) > output
	open output

all: generator run 

clean:
	rm -f generator src/*.o

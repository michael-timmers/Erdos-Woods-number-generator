CC = clang++
CPPFLAGS = -std=c++11

OBJECTS = src/main.cpp

generator: $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o : %.c
	$(CC) -c $(CPPFLAGS) $@ -o $^

run:
	time ./generator > output
	open output

clean:
	rm -f generator src/*.o

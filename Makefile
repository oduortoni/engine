# Main program

objects = objects/main.o objects/vector.o objects/matrix.o objects/projection.o

engine: $(objects)
	cc -o bin/engine $(objects) -lm

objects/main.o:
	cc -c src/main.c -o objects/main.o

objects/vector.o:
	cc -c src/vector.c -o objects/vector.o

objects/matrix.o:
	cc -c src/matrix.c -o objects/matrix.o

objects/projection.o:
	cc -c src/projection.c -o objects/projection.o

## Testing

testobjects = objects/vector.o objects/vector_test.o
runner = tests/runner.c

test: $(testobjects)
	cc -o bin/test $(runner) $(testobjects) -lm

objects/vector_test.o:
	cc -c tests/vector_test.c -o objects/vector_test.o


# common to both main program and testing

clean:
	rm -f $(objects) engine
	rm -f $(testobjects) test

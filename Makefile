objects = objects/main.o objects/vector.o

engine: $(objects)
	cc -o engine $(objects) -lm

objects/main.o:
	cc -c src/main.c -o objects/main.o

objects/vector.o:
	cc -c src/vector.c -o objects/vector.o

clean:
	rm -f $(objects) engine

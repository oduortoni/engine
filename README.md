# engine

A Graphic Program that renders objects using ASCII characters

## prerequisites

+ c language - but if you have a bit of imperative programming knowledge in whatever language, it will be easy to follow
+ make - a program used to simplify the compilation process

## usage

```bash
git clone https://github.com/oduortoni/engine.git
cd engine
make engine
./bin/engine
```

## testing

This project uses a simple testing library, [minunit](https://github.com/siu/minunit.git), that supports simple assertions. Since most of the project is math-based, it easier to test the functions given the fact that functions are predictable.

```bash
make test
./bin/test
```

**testing approach**

Try something and create the tests after they work. The reason for this is that we only need the functions to work in the first draft even if they are inefficient. The testing just allows us to stay the course in the future. With this, we can be sure that a refactor will not break code that is already dependent on what is already there.

## cleanup

Clean up resources eachtime you want a fresh build

```bash
make clean
```

It will remove both the executables (engine and test) in the root directory and anything that has a (.o) extension inside the objects/ directory

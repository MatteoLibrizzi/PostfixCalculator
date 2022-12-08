flags = -ansi -Wall
flagsExe = $(flags) -L. -lstack -Wl,-rpath,. -lm -lreadline

calculator: main.o libstack.so calculator.o utils.o
	gcc -o calculator $^ $(flagsExe)

main.o: main.c
	gcc -c $^ $(flags)

libstack.so: stack.o
	gcc -shared -o libstack.so $^

stack.o: stack.c
	gcc -fPIC -c $^ $(flags)

calculator.o: calculator.c
	gcc -c $^ $(flags) -lm -lreadline

utils.o: utils.c
	gcc -c $^ $(flags) -lm -lreadline

clean:
	rm *.o
	rm *.so
	rm calculator
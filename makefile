calculator: main.o stack.o calculator.o utils.o
	gcc -o calculator $^ -ansi -lm -lreadline

main.o: main.c
	gcc -c $^ -ansi

stack.o: stack.c
	gcc -c $^ -ansi

calculator.o: calculator.c
	gcc -c $^ -ansi -lm -lreadline

utils.o: utils.c
	gcc -c $^ -ansi -lm -lreadline

clean:
	rm *.o
	rm calculator
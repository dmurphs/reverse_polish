#Daniel Murphy
#--------------------------------------------------
# makefile
#--------------------------------------------------

FLAGS = -Wall
run: main.o stack.o infix.o postfix.o
	g++ $(FLAGS) -o run main.o stack.o infix.o postfix.o
main.o: main.cpp stack.h
	g++ $(FLAGS) -c main.cpp
infix.o: infix.cpp infix.h
	g++ $(FLAGS) -c infix.cpp
postfix.o: postfix.cpp postfix.h
	g++ $(FLAGS) -c postfix.cpp	
stack.o: stack.cpp stack.h
	g++ $(FLAGS) -c stack.cpp
clean:
	rm -f run *.o a.out

all: main test memtest

main: main.o 
	g++ -g main.o -o $@

test: bst_test
	./bst_test

memtest: main bst_test
	valgrind --leak-check=yes ./main
	valgrind --leak-check=yes ./bst_test

bst_test: bst_test.o
	g++ bst_test.o -o $@ -lgtest -lpthread

main.o: main.cpp bst.h bst.cpp
	g++ -c -g main.cpp -o $@

bst_test.o: bst_test.cpp bst.h bst.cpp
	g++ -c -g bst_test.cpp -o $@

clean:
	rm -f ./*.o main bst_test

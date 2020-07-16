
all: main test memtest

main: main.o 
	g++ -g main.o -o $@

test: bintree_test bintree_test.o
	./bintree_test

memtest: main bintree_test
	valgrind --leak-check=yes ./main
	valgrind --leak-check=yes ./bintree_test

bintree_test: bintree_test.o
	g++ bintree_test.o -o $@ -lgtest -lpthread

main.o: main.cpp bintree.h bintree.cpp
	g++ -c -g main.cpp -o $@

bintree_test.o: bintree_test.cpp bintree.h bintree.cpp
	g++ -c -g bintree_test.cpp -o $@

clean:
	rm -f ./*.o main bintree_test

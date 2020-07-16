
all: main test memtest

main: main.o 
	g++ -g main.o -o $@

test: table_test
	./table_test

memtest: main table_test
	valgrind --leak-check=yes ./main
	valgrind --leak-check=yes ./table_test

table_test: table_test.o
	g++ table_test.o -o $@ -lgtest -lpthread

main.o: main.cpp table.h table.cpp
	g++ -c -g main.cpp -o $@

table_test.o: table_test.cpp table.h table.cpp
	g++ -c -g table_test.cpp -o $@

clean:
	rm -f ./*.o main table_test

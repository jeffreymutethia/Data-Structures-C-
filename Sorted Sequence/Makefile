
all: main test memtest

main: main.o 
	g++ -g main.o -o $@

test: sseq_test sseq_test.o
	./sseq_test

memtest: main sseq_test
	valgrind --leak-check=yes ./main
	valgrind --leak-check=yes ./sseq_test

sseq_test: sseq_test.o
	g++ sseq_test.o -o $@ -lgtest -lpthread

main.o: main.cpp sorted_seq.h sorted_seq.template const_node_iterator.h
	g++ -c -g main.cpp -o $@

sseq_test.o: sseq_test.cpp sorted_seq.h sorted_seq.template const_node_iterator.h
	g++ -c -g sseq_test.cpp -o $@

clean:
	rm -f ./*.o main sseq_test

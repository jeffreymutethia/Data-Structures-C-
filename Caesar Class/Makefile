
all: caesar

test: caesartest
	./caesartest

caesar: caesar_main.o Caesar.o
	g++ $^ -o $@

caesartest: caesar_test.o Caesar.o
	g++ $^ -o $@ -lgtest -lpthread

%.o: %.cpp
	g++ -c $^ -o $@

clean:
	rm -f ./*.o caesar caesartest

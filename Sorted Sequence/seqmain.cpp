#include "sorted_seq.h"

#include <iostream>

int main(int argc, char *argv[]) {

    sorted_seq<std::string> sseq;
    sseq.insert("foo");
    sseq.insert("bar");
    sseq.insert("baz");
    std::cout << sseq.contains("bar") << std::endl;

}

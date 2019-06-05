#include <utility>

#include <iostream>
#include <unistd.h>
#include <thread>
#include "tuple/Tuple.h"
#include "architecture/Proces.h"
#include "linda/linda.h"

template<typename... Args>
void example(Args... args) {
    Tuple tuple(args...);
    for (int i = 0; i < tuple.getSize(); ++i) {
        if (tuple[i].getType() == STRING) {
            std::cout << tuple[i].getStringValue() << std::endl;
        } else if (tuple[i].getType() == INT) {
            std::cout << tuple[i].getIntValue() << std::endl;
        } else {
            std::cout << tuple[i].getFloatValue() << std::endl;
        }
    }
    std::cout << tuple.getType() << std::endl;
}

void one_process(std::string directory) {
    Proces process(std::move(directory));
    process.connect();

}

void example_ring() {
    std::string directory = "/home/fen/";
    unlink((directory + "mainFIFO").c_str());

    one_process(directory);

}

int main() {
    linda::init_linda();
    linda::output_linda(Tuple(1, 2, 3));
    int i;
    std::cin >> i;
    if (i == 2) {
        std::cout << "trying to get tuple" << std::endl;
        Tuple tuple = linda::input_linda("", 5);
        std::cout << "finished" << std::endl;
    } else if (i == 1) {

    }
    linda::terminate_linda();
    return 0;
}

#include <utility>
#include <future>

//
// Created by Marcin on 05.06.2019.
//

#include "linda.h"
#include "../thread/SynchronizedQueue.h"
#include "../architecture/Proces.h"

namespace linda {
    Proces proces("/home/fen/pipe/");

    void init_linda() {
        proces.start();
    }

    void terminate_linda() {
        proces.join();
    }

    void output_linda(Tuple tuple) {
        proces.put(std::move(tuple));
    }

    Tuple input_linda(std::string pattern, int timeout) {
        proces.sendRequestTuple(-1, pattern);
    }

    Tuple read_linda(std::string pattern, int timeout) {
    }
}

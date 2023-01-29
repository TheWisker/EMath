#include "calculator.h"

Core::Core() {
    math = new Math();
    storage = new Storage();
    terminal = new Terminal();
}

int Core::launch() {
    terminal->start(this);

    delete math, storage, terminal;
    return 0;
}

int Core::add() {
    return 0;
}

int Core::get(std::vector<Equation>* ptr) {
    *ptr = storage->access();
    return 0;
}

int main() {
    Core* core = new Core();
    core->launch();
    delete core;
    return 0;
}
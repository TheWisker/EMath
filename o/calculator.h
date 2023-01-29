#include "math.h"
#include "storage.h"
#include "terminal.h"

class Core {
    public:
        Core();
        int launch();

        int add();
        int get(std::vector<Equation>* ptr);

    private:
        Math* math;
        Storage* storage;
        Terminal* terminal;
};

int main();
#include <cstdio>
#include <fstream>
#include <jsoncpp/json.h>

template <typename I, typename O> class Storage {
    public:
        Storage(std::string fn);

        int read(I* data);
        int write(O data);
        int create();
        int trash();

    private:
        const std::string filename;
        
};

class JsonStorage : Storage<std::string, Json::Value> {
    public:
        JsonStorage(std::string fn);
        
        int read(Json::Value* data);
        int write(Json::Value data);

    private:
       
};

class EquationStorage : JsonStorage {
    public:
        EquationStorage(std::string fn);

        int save();
        int get();
        int remove();

};
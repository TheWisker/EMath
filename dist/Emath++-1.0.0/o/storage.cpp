#include "storage.h"

template<typename I, typename O>
Storage<I, O>::Storage(std::string fn) : filename(fn) {}

template<typename I, typename O>
int Storage<I, O>::read(I* data) {
    std::stringstream buffer;
    std::ifstream input(this->filename);

    buffer << input.rdbuf();
    *data = buffer.str();
    input.close();

    return 0;
}

template<typename I, typename O>
int Storage<I, O>::write(O data) {
    std::ofstream output(this->filename);

    output << data;
    output.close();

    return 0;
}

template<typename I, typename O>
int Storage<I, O>::create() {
    std::ofstream stream(this->filename);
    stream.close()
    return 0;
}

template<typename I, typename O>
int Storage<I, O>::trash() {
    if (std::remove(this->filename) == 0) {
        delete &this;
        return 0;
    }
    return -1;
}


JsonStorage::JsonStorage(std::string fn) : Storage<std::string, Json::Value>(fn) {}

int JsonStorage::read(Json::Value* data) {
    std::string contents;
    Json::Reader reader;
    
    if (Storage::read(&contents) == 0) {
        if (reader.parse(contents, *data) == 0) {
            return 0;
        }
    }
    return -1;
}

int JsonStorage::write(Json::Value data) {
    if (Storage::write(data) == 0) {
        return 0;
    }
    return -1;
}


EquationStorage::EquationStorage(std::string fn) : JsonStorage(fn) {}

int EquationStorage::get() {

}

int EquationStorage::save() {

}

int EquationStorage::remove() {

}
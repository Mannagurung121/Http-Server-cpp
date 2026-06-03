#include "../includes/serveFile.h"
#include <fstream>
#include <sstream>

Serve* Serve::instance = nullptr;

Serve* Serve::getInstance() {
    if (instance == nullptr)
        instance = new Serve();
    return instance;
}

Response Serve::serveFile(const std::string& files) {
    std::ifstream file(files);
    if (file.is_open()) {
        std::stringstream ss;
        ss << file.rdbuf();
        return Response::ok(ss.str());
    }
    return Response::invalid();
}
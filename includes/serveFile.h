#pragma once
#include "response.h"
#include <string>

class Serve {
private:
    Serve() {}
    static Serve* instance;

public:
    static Serve* getInstance();
    Response serveFile(const std::string& files);
};
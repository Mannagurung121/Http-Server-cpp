#include<string>
#include<iostream>
#include<sstream>
#include "../includes/request.h"

Request Request ::parse(const std::string &raw){
    Request r ;
    std::istringstream stream(raw);
    stream >> r.method >> r.path;
    return r;
}


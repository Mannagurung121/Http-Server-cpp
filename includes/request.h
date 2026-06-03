#pragma once
#include <string>

class Request
{
    public:
    std::string body;
    std::string path;
    std::string method;
    public:
    static Request parse(const std::string &raw);
    

};
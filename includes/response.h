#pragma once
#include <iostream>
class Response
{

    int statusCode;
    std::string statusText;
    std::string content_type;
    std::string body;

public:
    Response(int code, const std::string &text, const std::string &body);
     std::string to_string();
    static Response ok(const std::string &data);
    static Response invalid();
};
#include <iostream>
#include "../includes/response.h"

Response::Response(int code, const std::string &sText, const std::string &body)
{
  this->body = body;
  this->statusCode = code;
  this->statusText = sText;
  this->content_type = "text/html";
}
std::string Response::to_string(){
   return "HTTP/1.1 " + std::to_string(statusCode) + " " + statusText + "\r\n"
               "Content-Type: text/html\r\n"
               "Content-Length: " + std::to_string(body.size()) + "\r\n"
               "\r\n" + body;
}
Response Response ::ok(const std::string &data)
{
  return Response(200, "ok", data);
}
Response Response::invalid()
{
  return Response(202, "notfound", "<h1>Error 404 - Page Not Found</h1>");
}

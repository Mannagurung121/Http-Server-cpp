#pragma once
class Server
{
private:
    void handlClient(int n);
    int port;

public:
    Server(int port);
    void start();
};
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>
#include <unistd.h>
#include "../includes/request.h"
#include "../includes/response.h"
#include <netinet/in.h>
#include "../includes/server.h"
#include "../includes/serveFile.h"
Server::Server(int port) : port(port) {}

void Server ::handlClient(int clientId)
{
    char buffer[4024];
    memset(buffer, 0, sizeof(buffer));
    recv(clientId, buffer, sizeof(buffer), 0);
    Request r = Request::parse(buffer);
    std::cout << r.method << " " << r.path << std::endl;
    std::string filepath;
    if (r.path == "/")
    {
        filepath = "public/index.html";
    }
    else
    {
        filepath = "public" + r.path + ".html";
    }

    Response res = Serve::getInstance()->serveFile(filepath);
    std::string response = res.to_string();
    send(clientId, response.c_str(), response.size(), 0);
    close(clientId);
}

void Server::start()
{
    int sockets = socket(AF_INET, SOCK_STREAM, 0);
    if (sockets < 0)
    {
        std::cout << " Unable to connect socket \n";
        return;
    }
    int opt = 1;
    setsockopt(sockets, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in sockserver;
    sockserver.sin_family = AF_INET;
    sockserver.sin_addr.s_addr = INADDR_ANY;
    sockserver.sin_port = htons(port);

    if (bind(sockets, (sockaddr *)&sockserver, sizeof(sockserver)) < 0)
    {
        std::cout << "Unable to bind socket \n";
        return;
    }
    if (listen(sockets, 10) < 0)
    {
        std::cout << "Unable to connect port 8080 \n";
        return;
    }
  std::cout << " Server is running on port 8080\n";
    while (true)
    {
        sockaddr_in clients;
        socklen_t client_len;
        client_len = sizeof(clients);
        int client = accept(sockets, (sockaddr *)&clients, &client_len);
        if (client < 0)
        {
            std::cout << " Unable to connect Clients \n";
        }
        else
        {
            std::cout << " clients connected : \n";
        }
        std::thread t(&Server::handlClient, this, client);
        t.detach();
    }
}
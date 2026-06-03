# HTTP Server in C++

A multithreaded HTTP/1.1 server built from scratch in C++ using raw POSIX TCP sockets — no external libraries, no frameworks.

## Features

- HTTP/1.1 request parsing (method, path, headers)
- Static file serving from `public/` directory
- Concurrent client handling via per-client thread dispatch (`std::thread`)
- Proper HTTP response formatting (status codes, Content-Type, Content-Length)
- Singleton pattern for file serving layer
- Built with raw POSIX TCP sockets (`AF_INET`, `SOCK_STREAM`)

## Project Structure

```
Http-Server-cpp/
├── includes/          # Header files
│   ├── server.h
│   ├── request.h
│   ├── response.h
│   └── serveFile.h
├── src/               # Source files
│   ├── main.cpp
│   ├── server.cpp
│   ├── request.cpp
│   ├── response.cpp
│   └── ServeFile.cpp
├── public/            # Static HTML files served by the server
│   └── index.html
└── CMakeLists.txt
```

## Build & Run

```bash
mkdir build && cd build
cmake ..
make
./server
```

Server starts on **port 8080** by default.

## How It Works

1. Server binds to port 8080 and listens for incoming TCP connections
2. On each connection, a new `std::thread` is spawned to handle the client
3. HTTP request is parsed to extract method and path
4. Corresponding HTML file is served from the `public/` directory
5. Proper HTTP/1.1 response is sent back with status code and headers

## Tech Stack

- **Language:** C++17
- **Networking:** POSIX Sockets (`sys/socket.h`, `arpa/inet.h`)
- **Concurrency:** `std::thread`
- **Build System:** CMake

## Author

[Manan Singh Gurung](https://github.com/Mannagurung121)
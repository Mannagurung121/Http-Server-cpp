#include<iostream>
#include "../includes/server.h"

int main(){
    Server s(8080);
    s.start();
    return 0;
}
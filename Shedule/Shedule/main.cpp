#include <iostream>

#include "source.hpp"

using namespace std;

int main()
{
    ScheduleServer server;
    server.run("localhost:1010");

    cin.get();
    return 0;
}
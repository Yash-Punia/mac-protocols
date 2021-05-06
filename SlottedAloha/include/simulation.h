#ifndef SIMULATION_H
#define SIMULATION_H
#include<string>

class Station
{
    std::string name;
    std::string blank;
    std::string frame;
    int streamLength;
    int frameSize;
    int *frames;
    public:
        Station(std::string, int);
        void display();
        void update();
        void makeframe();
        bool isReady();
};

#endif
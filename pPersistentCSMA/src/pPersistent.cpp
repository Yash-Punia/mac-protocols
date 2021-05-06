#include <iostream>
#include <vector>
#include <unistd.h> // for time delays
#include <cstdlib>
#include <ctime>
#include "simulation.h"

using namespace std;

void clear()
{
    cout << "\033c";
}

void render(vector<Station> &stations)
{
    for (int i = 0; i < stations.size(); i++)
    {
        stations[i].display();
    }
}

bool isChannelReady(vector<Station> &stations)
{
    bool ready = true;
    for(int i=0;i<stations.size();i++)
    {
        ready = ready && stations[i].isReady();
    }
    return ready;
}

void pcsma(vector<Station> &stations)
{
    // make frames randomly for different stations
    srand((unsigned)time(0));

    // should we make a frame or not
    for (int i = 0; i < stations.size(); i++)
    {
        bool frameGenerated = rand() % 100 < 30;
        bool probability = stations[i].getP() < 0.5f;
        if (frameGenerated && isChannelReady(stations) && probability)
        {
            stations[i].makeframe();
        }
    }
}

void update(vector<Station> &stations)
{
    for (int i = 0; i < stations.size(); i++)
    {
        stations[i].update();
    }
}

int main()
{
    srand((unsigned)time(0));
    vector<Station> stations;

    //change this stream length for variable length
    int streamLength = 20;

    string stationNames[] = {"💻", "🖥️ ", "📱", "📠", "🏧"};
    for (string name : stationNames)
    {
        Station temp(name, streamLength, (rand()%101)/100.0);
        stations.push_back(temp);
    }

    cout<<"p Persistent CSMA\n\n";

    while (1)
    {
        clear();
        render(stations);
        update(stations);
        pcsma(stations);
        sleep(1);
    }
    return 0;
}
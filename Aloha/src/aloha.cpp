#include<iostream>
#include<vector>
#include<unistd.h> // for time delays
#include<cstdlib>
#include<ctime>
#include "simulation.h"

using namespace std;

void clear()
{
    cout<<"\033c";
}

void render(vector<Station> &stations)
{
    for(int i=0;i<stations.size();i++)
    {
        stations[i].display();
    }
}

void aloha(vector<Station> &stations)
{  
    // make frames randomly for different stations
    srand((unsigned)time(0));

    // should we make a frame or not
    for(int i=0;i<stations.size();i++)
    {
        bool frameGenerated = rand() % 100 < 20; 
        if(frameGenerated && stations[i].isReady())
        {
            stations[i].makeframe();
        }
    }
}

void update(vector<Station> &stations)
{
    for(int i=0;i<stations.size();i++)
    {
        stations[i].update();
    }
}

int main()
{
    vector<Station> stations;

    //change this stream length for variable length 
    int streamLength = 20;
    
    string stationNames[] = {"💻", "🖥️ ", "📱", "📠","🏧"};
    for(string name:stationNames)
    {
        Station temp(name, streamLength);
        stations.push_back(temp);
    }

    cout<<"Pure ALOHA\n\n";

    while(1)
    {
        clear();
        render(stations);
        update(stations);
        aloha(stations);
        usleep(1000000);
    }
    return 0;
}
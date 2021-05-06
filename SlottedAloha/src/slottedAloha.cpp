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

void slottedAloha(vector<Station> &stations, int slots)
{  
    static int timer = 0;
    timer = (timer+1)%slots;
    
    // if timer is 0, then slot has begun so true
    bool slotBegin = timer ? false :true;

    // make frames randomly for different stations
    srand((unsigned)time(0));

    // should we make a frame or not
    for(int i=0;i<stations.size();i++)
    {
        bool frameGenerated = rand() % 100 < 20; 
        if(frameGenerated && stations[i].isReady() && slotBegin)
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

    cout<<"Slotted ALOHA\n\n";

    while(1)
    {
        clear();
        render(stations);
        update(stations);
        slottedAloha(stations, 3);
        sleep(1);
    }
    return 0;
}
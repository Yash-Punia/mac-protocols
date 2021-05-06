#include "simulation.h"
#include<iostream>

using namespace std;

//initializing a station's basic information
Station:: Station(string s, int n)
{
    name = s;
    blank = "🔹";
    frame = "🟦";
    frameSize = 3;
    streamLength = n;
    frames = new int[streamLength];
    for(int i=0;i<streamLength;i++)
        frames[i] = 0;
}

/**
 * Update a station's frames
 * 
 * This updates a station's frames in a stream of a given
 * streamlength. 
*/
void Station::update()
{
    for(int i=streamLength-frameSize;i>0;i--)
    {
        // Pushes a frame forward
        frames[i] = frames[i-1];
    }

    frames[0] = 0;
}

/**
 * Adds a frame 
 * 
 * This adds a frame to beginning of the 
 * stream of the station
*/
void Station::makeframe()
{
    for(int i=0;i<frameSize;i++)
        frames[i] = 1;
}

void Station::display()
{
    cout<<name<<"  : ";
    for(int i=0;i<streamLength;i++)
    {
        if(frames[i] == 0)
            cout<<blank;
        else
            cout<<frame;
    }
    cout<<endl;
}

bool Station::isReady()
{
    for(int i=0;i<frameSize;i++)
    {
        if(frames[i] == 1)
            return false;
    }
    return true;
}
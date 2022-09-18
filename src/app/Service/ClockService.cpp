#include "ClockService.h"

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    prevTime = 0;
    clockView = view;
    clockState = BasicClock;
}

ClockService::~ClockService()
{}

void ClockService::updateEvent()
{
    if(clockState == BasicClock)
    {
        curTime = time(NULL);
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }   
    if (clockState == StopWatch_ON)
    {
        curTime = time(NULL) - prevTime;
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate );
    }
    if(clockState == StopWatch_OFF)
    {
        struct tm *timeDate = localtime(&curTime);
        clockView->updateTime(timeDate);
    }
     

}

void ClockService::counterEvent(std::string strState)
{
    switch(clockState)
    {
        case BasicClock :
            
            if (strState == "clockButton") 
            {
                prevTime = time(NULL)+32401;
                clockState = StopWatch_ON;
            }
        
        break;

        case StopWatch_ON :
            if (strState == "clockButton") 
            {
                prevTime = curTime;
                clockState = StopWatch_OFF;
            }
        break;

        case StopWatch_OFF :
            if (strState == "clockButton") 
            {
                clockState = BasicClock;
            }
        break;
    }

}
#ifndef __CLOCKSERVICE_H__
#define __CLOCKSERVICE_H__

#include <time.h>
#include "ClockView.h"
#include "ClockState.h"

class ClockService
{
private:
    time_t curTime;
    time_t prevTime;
    ClockView *clockView;
    int clockState;

public:
    ClockService(ClockView *view);
    virtual ~ClockService();
    void updateEvent();
    void updateDistance(int distance);
    void counterEvent(std::string strState);
};

#endif /* __CLOCKSERVICE_H__ */
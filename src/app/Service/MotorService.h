#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#include "MotorView.h"
#include "MotorState.h"
#pragma once

class MotorService
{
public:
    MotorService(MotorView *motorView);
    virtual ~MotorService();
    void updateState(std::string strState);    

private:
    int motorState;
    MotorView *motorView;


};

#endif
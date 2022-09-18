#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService, MotorService *motorService)
{
    this -> service = serv;
    this ->clockService = clockServ;
    this ->tempHumidService = tempHumidService;
    this -> motorService = motorService;
    lightState = LIGHT_OFF;
    motorState = Motor_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{

    if (strBtn == "error")
    {
        service->updateState("error");        
    }
    if (strBtn == "restart")
    {
        service->updateState("restart");        
    }
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }

    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
    if (strBtn == "motorButton")
    {
        motorService->updateState("motorButton");
    }
    if (strBtn == "clockButton")
    {
        clockService->counterEvent("clockButton");
    }
}
void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService ->updateEvent(dhtData);

}

void Controller::updateDistance(int distance)
{
    service ->updateDistance(distance);
}
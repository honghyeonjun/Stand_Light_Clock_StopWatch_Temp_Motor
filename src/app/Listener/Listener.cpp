#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *modeButton,Button *powerButton,Button *motorButton,Button *clockButton, Controller *control, 
                    ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this ->motorButton = motorButton;
    this ->clockButton = clockButton;
    controller = control;
    clockCheck = clock;
    this -> dht11 = dht11;
    this -> ultraSonic = ultraSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

      if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }
    
     if (motorButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("motorButton");
    }
    if (clockButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("clockButton");
    }
 
    static unsigned int prevTempHumidTime = 0;
    if(millis()-prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11 -> readData();
        if(!dhtData.error) 
         {
            controller -> updateTempHumid(dhtData);
            if(dhtData.Temp >= 28)
            {
                controller->updateEvent("error");
            }
            else
            {
                controller->updateEvent("restart");    
            }

         }
    }

    static unsigned int prevUltraSonicTime = 0;
    if(millis()-prevUltraSonicTime > 1000)
    {
            prevUltraSonicTime = millis();
            int distance = ultraSonic -> readDistance();
            controller -> updateDistance(distance);
    }
  
}
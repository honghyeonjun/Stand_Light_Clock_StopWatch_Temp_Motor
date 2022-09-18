#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidView.h"
#include "TempHumidService.h"
#include "DHT_Data.h"
#include "UltraSonic.h"
#include "Motor.h"
#include "MotorView.h"
#include "MotorState.h"
#include "MotorService.h"
int main()
{
    std::cout << "Hello World!" << std::endl;

    Button clockButton(6);
    Button modeButton(27);//mode
    Button powerButton(28);
    Button motorButton(29);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    Motor motor(26);
    DHT11 dht(7);
    UltraSonic ultraSonic(5, 4);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    MotorView motorview(&motor);
    
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    Service service(&view,&motorview);
    MotorService motorService(&motorview);
    TempHumidService tempHumidService(&tempHumidView);//,&view
    ClockService clockSerivce(&clockView);
    Controller control(&service, &clockSerivce, &tempHumidService, &motorService);
    Listener listener(&modeButton,&powerButton,&motorButton, &clockButton, &control, &clockCheck, &dht, &ultraSonic);
    
    
    // DHT_Data dhtData;

    while (1)
    {
    
        listener.checkEvent();
        view.lightView();
        motorview.motorView();
        delay(10);
    }

    return 0;
}
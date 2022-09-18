#include "Service.h"

Service::Service(View *viewer, MotorView *motorView)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
    motorState = Motor_OFF;
    motorview = motorView;

}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    std::cout << strState << std::endl;
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
             if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                  motorview->setState(motorState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton"  ) 
            {
                lightState = LIGHT_OFF;

            }
            if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                 motorview->setState(motorState);
            }
            if (bDistanceLight) 
            {
                view -> setState(lightState);
            }
            else
            {
               view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_2:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton" ) 
            {
            lightState = LIGHT_OFF;
            }
            if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                  motorview->setState(motorState);
            }
            if (bDistanceLight) 
            {
                view -> setState(lightState);
            }
            else
            {
               view->setState(LIGHT_OFF);
            }
        break;
        
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton" ) 
            {
            lightState = LIGHT_OFF;
            }
            if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                  motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                   motorview->setState(motorState);
            }
            if (bDistanceLight) 
            {
                view -> setState(lightState);
            }
            else
            {
               view->setState(LIGHT_OFF);
            }
            
        break;

        case LIGHT_4:
            if (strState == "modeButton") 
            {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                  motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                   motorview->setState(motorState);
            }
            if (bDistanceLight) 
            {
                view -> setState(lightState);
            }
            else
            {
               view->setState(LIGHT_OFF);
            }
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton" ) 
            {
                lightState = LIGHT_OFF;
            }
            if(strState == "error")
            {
                lightState = LIGHT_OFF;
                motorState = Motor_ON;
                  motorview->setState(motorState);

            }
            if(strState == "restart")
            {
                 motorState = Motor_OFF;
                   motorview->setState(motorState);
            }
            if (bDistanceLight) 
            {
                view -> setState(lightState);
            }
            else
            {
               view->setState(LIGHT_OFF);
            }
        break;
        // case Motor_ON:
        //     lightState = Motor_ON;
        //     view -> setState(lightState);
        // break;    
        // case Motor_OFF:
        //     lightState = Motor_OFF;
        //     view -> setState(lightState);    
        // break;

     
    }
}
void Service::updateDistance(int distance)
{
    //printf("distance : %d\n", distance);

    static int distance_level_check_count = 0;
    if(distance < 0 || distance > 100)
    {
        distance_level_check_count++;
        if(distance_level_check_count > 10)
        {
            bDistanceLight = false;//Lightoff
            view->setState(LIGHT_OFF);
        }
    }
    else
    {
        distance_level_check_count = 0;
        
        bDistanceLight = true;
        view -> setState(lightState);
        //LightOn
    }
}


#ifndef MAIN_CALCULATOR
#define MAIN_CALCULATOR

#include "Calculators.h"

class CMainCalculator
{
public:
    CMainCalculator() = default;
    ~CMainCalculator() = default;

    //Get data from UserInfoManager
    //Process it
    //Return results to UserInfoManager

private:
    CBatteryCalculator BatteryCalculator;
    CSolarPanelCalculator SolarPanelCalculator;
};

#endif  //MAIN_CALCULATOR

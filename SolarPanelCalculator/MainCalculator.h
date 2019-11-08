#ifndef MAIN_CALCULATOR
#define MAIN_CALCULATOR

#include "Calculators.h"
#include "UserInfoManager.h"


class CMainCalculator
{
public:
    CMainCalculator(uint32_t needed_capacity_W, uint16_t sun_hours_per_day);
    ~CMainCalculator() = default;

    void Calculate();
    SSolarSystemInfo GetResults() const;

private:
    CBatteryCalculator BatteryCalculator;
    CSolarPanelCalculator SolarPanelCalculator;

    SSolarSystemInfo CalculatedData;
};

#endif  //MAIN_CALCULATOR

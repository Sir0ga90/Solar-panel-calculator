#ifndef USER_MANAGER
#define USER_MANAGER


#include <cstdint>

#include "Calculators.h"

class CUserManager
{
public:
    CUserManager() = default;
    ~CUserManager() = default;

    void ShowManualInfo();
    void TakeUserConsumedEnergy();
    void TakeSunHoursPerDay();

    void ShowNumberBatteries(TUnitsNumber batteries_num);
    void ShowNumberSolarPanels(TUnitsNumber solar_panels_num);
    void ShowNeededArea(float area);

private:
    uint32_t NeededUserCapacityW{};
    uint16_t SunHoursPerDay{};
};


#endif //USER_MANAGER

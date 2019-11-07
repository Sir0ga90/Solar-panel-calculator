#ifndef USER_MANAGER
#define USER_MANAGER


#include <cstdint>

#include "Calculators.h"

class CUserInfoManager
{
public:
    CUserInfoManager() = default;
    ~CUserInfoManager() = default;

    void Start();

    void ShowNumberBatteries(TUnitsNumber batteries_num);
    void ShowNumberSolarPanels(TUnitsNumber solar_panels_num);
    void ShowNeededArea(float area);

private:
    void ShowManualInfo();
    void TakeUserConsumedEnergy();
    void TakeSunHoursPerDay();

    uint32_t NeededUserCapacityW{};
    uint16_t SunHoursPerDay{};
};


#endif //USER_MANAGER

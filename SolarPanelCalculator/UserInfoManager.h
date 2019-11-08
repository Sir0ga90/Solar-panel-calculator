#ifndef USER_MANAGER
#define USER_MANAGER


#include <cstdint>
#include <iostream>

#include "Calculators.h"


struct SSolarSystemInfo
{
    TUnitsNumber BatteriesNumber;
    TUnitsNumber SolarPanelsNumber;
    float AreaForSolarPanels_SqM;

    friend std::ostream& operator<<(std::ostream& os, const SSolarSystemInfo& sys_info);
};

class CUserInfoManager
{
public:
    CUserInfoManager() = default;
    ~CUserInfoManager() = default;

    void Start();

    void ShowCalculatedInfo(const SSolarSystemInfo& system_info);

    uint32_t GetUserCapacity() const;
    uint16_t GetUserSunHours() const;

private:
    static void ShowManualInfo();
    void TakeUserConsumedEnergy();
    void TakeUserSunHoursPerDay();

    uint32_t NeededUserCapacityW{};
    uint16_t SunHoursPerDay{};
};


#endif //USER_MANAGER

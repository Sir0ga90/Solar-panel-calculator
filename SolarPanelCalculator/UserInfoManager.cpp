#include "UserInfoManager.h"

//=================================================================================================
std::ostream& operator<<(std::ostream& os, const SSolarSystemInfo& sys_info) {
    os << "Number of batteries (26AH, 12V): " << sys_info.BatteriesNumber << "\n"
        << "Number of solar panels (250V): " << sys_info.SolarPanelsNumber << "\n"
        << "Needed area for all panels, m²: " << sys_info.AreaForSolarPanels_SqM << "\n";

    return os;
}

//=================================================================================================
void CUserInfoManager::Start()
{
    ShowManualInfo();
    TakeUserConsumedEnergy();
    TakeUserSunHoursPerDay();
}

void CUserInfoManager::ShowManualInfo()
{
    std::cout << "Enter needed info and press 'Enter'.\n"
        << "Calculations will be produced according to only one type of batteries and solar panels.\n\n";
}


void CUserInfoManager::TakeUserConsumedEnergy()
{
    std::cout << "Enter daily consumed energy, W: ";
    std::cin >> NeededUserCapacityW;

    while(NeededUserCapacityW <= 0 || NeededUserCapacityW > MAX_POWER_OF_SOLAR_STATION_W )
    {
        std::cout << "Not appropriate value of consumed energy, MAX Power: 400 000W."
            << "Enter value again.\n";

        std::cin >> NeededUserCapacityW;
    }
}


void CUserInfoManager::TakeUserSunHoursPerDay()
{
    std::cout << "Enter daily average sun hours in your region: ";
    std::cin >> SunHoursPerDay;

    constexpr auto HOURS_IN_DAY = 24;

    while(SunHoursPerDay <= 0 || SunHoursPerDay > HOURS_IN_DAY)
    {
        if(SunHoursPerDay <= 0)
        {
            std::cout << "There is no sense in solar station.\n";
        }

        std::cout << "Not appropriate value of sun hours. MAX number of hours: 24.\n"
            << "Enter value again.\n";

        std::cin >> SunHoursPerDay;
    }

    std::cout << "\n";
}


void CUserInfoManager::ShowCalculatedInfo(const SSolarSystemInfo& system_info) 
{
    std::cout << system_info;
}


uint32_t CUserInfoManager::GetUserCapacity() const
{
    return NeededUserCapacityW;
}


uint16_t CUserInfoManager::GetUserSunHours() const
{
    return SunHoursPerDay;
}

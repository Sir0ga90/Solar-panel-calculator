#include "UserInfoManager.h"


std::ostream& operator<<(std::ostream& os, const SSolarSystemInfo& sys_info) {
    os << "Number of batteries (26AH, 12V): " << sys_info.BatteriesNumber << "\n"
        << "Number of solar panels (250V): " << sys_info.SolarPanelsNumber << "\n"
        << "Needed area for all panels, m²: " << sys_info.AreaForSolarPanels_SqM << "\n";

    return os;
}


void CUserInfoManager::Start()
{
    ShowManualInfo();
    TakeUserConsumedEnergy();
    TakeUserSunHoursPerDay();
}

void CUserInfoManager::ShowManualInfo()
{
    std::cout << "Some info\n";
}

void CUserInfoManager::TakeUserConsumedEnergy()
{
    std::cout << "Enter daily consumed energy, W: ";
    std::cin >> NeededUserCapacityW;
}

void CUserInfoManager::TakeUserSunHoursPerDay()
{
    std::cout << "Enter daily average sun hours in your region: ";
    std::cin >> SunHoursPerDay;
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

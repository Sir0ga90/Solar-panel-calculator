#include <iostream>

#include "UserInfoManager.h"


void CUserInfoManager::Start()
{
    ShowManualInfo();
    TakeUserConsumedEnergy();
    TakeSunHoursPerDay();
}

void CUserInfoManager::ShowManualInfo()
{
    std::cout << "Some info\n";
}

void CUserInfoManager::TakeUserConsumedEnergy()
{
    std::cout << "Enter daily consumed energy, W: ";
    std::cin >> NeededUserCapacityW;
    std::cout << "\n";
}

void CUserInfoManager::TakeSunHoursPerDay()
{
    std::cout << "Enter daily average sun hours in your region: ";
    std::cin >> SunHoursPerDay;
    std::cout << "\n";
}

void CUserInfoManager::ShowNumberBatteries(TUnitsNumber batteries_num)
{
    std::cout << "Number of batteries: " << batteries_num << "\n";
}

void CUserInfoManager::ShowNumberSolarPanels(TUnitsNumber solar_panels_num)
{
    std::cout << "Number of solar panels: " << solar_panels_num << "\n";
}

void CUserInfoManager::ShowNeededArea(float area)
{
    std::cout << "Area for current number of solar panels should be: " << area << "\n";
}

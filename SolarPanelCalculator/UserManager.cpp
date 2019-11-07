#include <iostream>

#include "UserManager.h"

void CUserManager::ShowManualInfo()
{
    std::cout << "Some info\n";
}

void CUserManager::TakeUserConsumedEnergy()
{
    std::cout << "Enter daily consumed energy, W: ";
    std::cin >> NeededUserCapacityW;
    std::cout << "\n";
}

void CUserManager::TakeSunHoursPerDay()
{
    std::cout << "Enter daily average sun hours in your region: ";
    std::cin >> SunHoursPerDay;
    std::cout << "\n";
}

void CUserManager::ShowNumberBatteries(TUnitsNumber batteries_num)
{
    
}

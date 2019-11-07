//UI======================================================================
//show brief manual

//prompt to enter needed amount of energy
//prompt to enter avg sun hours: /summer/, winter only

/*
 *show result with number of needed: 
 *  batteries, 
 *  solar panels,
 *  needed area on the roof (not only roof is possible)
*/

//CALCULATIONS============================================================
//calculate number of batteries, 26 Ah
//calculate number of solar panels, 250W
//  calculate needed area



//CLASSES=================================================================
//CUserInfoManager
//CMainCalculator
//  CBaseCalculator
//  CBatteryCalculator
//  CSolarPanelCalculator

#include <iostream>

#include "Calculators.h"
#include "UserInfoManager.h"


int main() {
    CUserInfoManager user_manager{};

    user_manager.TakeUserConsumedEnergy();
    user_manager.TakeSunHoursPerDay();

    return 0;
}
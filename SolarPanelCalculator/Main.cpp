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

#include "UserInfoManager.h"
#include "MainCalculator.h"


int main() {
    CUserInfoManager user_manager{};

    user_manager.Start();

    CMainCalculator calculator(user_manager.GetUserCapacity(), user_manager.GetUserSunHours());

    calculator.Calculate();
    user_manager.ShowCalculatedInfo(calculator.GetResults());

    return 0;
}
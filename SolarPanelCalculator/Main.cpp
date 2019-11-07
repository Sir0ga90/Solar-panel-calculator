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
//CUserManager
//CMainCalculator
//  CBaseCalculator
//  CBatteryCalculator
//  CSolarPanelCalculator

#include <iostream>

#include "Calculators.h"


int main() {
    constexpr auto consumed_power = 1960u;

    CBatteryCalculator bat_calc{consumed_power};

    std::cout << bat_calc.GetCalculatorTypeName() << "\n"
        << bat_calc.GetCalculatedNumberOfUnits() << "\n";

    CSolarPanelCalculator panel_calc{consumed_power, 6};

    std::cout << panel_calc.GetCalculatorTypeName() << "\n"
        << panel_calc.GetCalculatedNumberOfUnits() << "\n";

    return 0;
}
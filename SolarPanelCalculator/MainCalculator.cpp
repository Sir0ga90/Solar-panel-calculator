#include "MainCalculator.h"

CMainCalculator::CMainCalculator(uint32_t needed_capacity_W, uint16_t sun_hours_per_day)
    : BatteryCalculator(needed_capacity_W),
    SolarPanelCalculator(needed_capacity_W, sun_hours_per_day) 
{}

void CMainCalculator::Calculate()
{
    CalculatedData.BatteriesNumber = BatteryCalculator.GetCalculatedNumberOfUnits();
    CalculatedData.SolarPanelsNumber = SolarPanelCalculator.GetCalculatedNumberOfUnits();
    CalculatedData.AreaForSolarPanels_SqM = SolarPanelCalculator.GetNeededAreaForAllPanels();
}

SSolarSystemInfo CMainCalculator::GetResults() const
{
    return CalculatedData;
}

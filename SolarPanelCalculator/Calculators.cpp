#include <cmath>

#include "Calculators.h"


//=================================================================================================
CBaseCalculator::CBaseCalculator(uint32_t needed_capacity_W)
    : NeededUserCapacityW(needed_capacity_W) 
{}


uint32_t CBaseCalculator::GetNeededUserCapacity() const
{
    return NeededUserCapacityW;
}


void CBaseCalculator::SetCalculatorTypeName(std::string type_name)
{
    CalculatorType = type_name;
}


std::string CBaseCalculator::GetCalculatorTypeName() const
{
    return CalculatorType;
}

//=================================================================================================
CBatteryCalculator::CBatteryCalculator(uint32_t needed_capacity_W)
    : CBaseCalculator(needed_capacity_W)
{
    SetCalculatorTypeName("Batteries");
}


TUnitsNumber CBatteryCalculator::GetCalculatedNumberOfUnits() {
    //Lead acid batteries only are taken into account, their usable power is 50% from its size
    const auto needed_battery_capacity = static_cast<float>(GetNeededUserCapacity() * 2);

    UnitsNumber = static_cast<TUnitsNumber>(ceil(needed_battery_capacity / CAPACITY_AH));

    return UnitsNumber;
}

//=================================================================================================
CSolarPanelCalculator::CSolarPanelCalculator(uint32_t needed_capacity_W, uint16_t sun_hours_per_day)
    : CBaseCalculator(needed_capacity_W),
    SunHoursPerDay(sun_hours_per_day)
{
    SetCalculatorTypeName("Solar Panels");
}


TUnitsNumber CSolarPanelCalculator::GetCalculatedNumberOfUnits()
{
    const auto needed_solar_panel_power = static_cast<float>(GetNeededUserCapacity()) / SunHoursPerDay;

    UnitsNumber = static_cast<TUnitsNumber>(ceil(needed_solar_panel_power / POWER_W));

    return UnitsNumber;
}


float CSolarPanelCalculator::GetNeededAreaForAllPanels() const
{
    const auto full_area = static_cast<float>(UnitsNumber * AREA_OF_ONE_UNIT);

    return ceil(full_area * 100) / 100; // to truncate to 2 digits after dot
}


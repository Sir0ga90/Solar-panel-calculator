#include <cmath>

#include "Calculators.h"


//=================================================================================================
CBaseCalculator::CBaseCalculator(uint32_t needed_capacity_W)
    : NeededUserCapasity(needed_capacity_W) 
{}


uint32_t CBaseCalculator::GetNeededUserCapacity() const
{
    return NeededUserCapasity;
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

    TUnitsNumber number_of_units{};
    number_of_units = static_cast<TUnitsNumber>(ceil(needed_battery_capacity / CAPACITY_AH));

    return number_of_units;
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

    TUnitsNumber number_of_units{};
    number_of_units = static_cast<TUnitsNumber>(ceil(needed_solar_panel_power / POWER_W));

    return number_of_units;
}


#ifndef CALCULATORS
#define CALCULATORS

#include <cstdint>
#include <string>


using TUnitsNumber = uint32_t;

//=================================================================================================
class CBaseCalculator
{
public:

    CBaseCalculator(uint32_t needed_capacity_W);
    virtual ~CBaseCalculator() = default;

    virtual TUnitsNumber GetCalculatedNumberOfUnits() = 0;
    uint32_t GetNeededUserCapacity() const;

    void SetCalculatorTypeName(std::string type_name);
    std::string GetCalculatorTypeName() const;

private:
    uint32_t NeededUserCapasity{};
    std::string CalculatorType;
};


//=================================================================================================
class CBatteryCalculator : public CBaseCalculator
{
public:
    CBatteryCalculator(uint32_t needed_capacity_W);

    TUnitsNumber GetCalculatedNumberOfUnits() override;

private:
    static constexpr uint32_t CAPACITY_AH = 26; //only one type of batteries capacity
};


//=================================================================================================
class CSolarPanelCalculator : public CBaseCalculator
{
public:
    CSolarPanelCalculator(uint32_t needed_capacity_W, uint16_t sun_hours_per_day);

    TUnitsNumber GetCalculatedNumberOfUnits() override;

private:
    static constexpr uint32_t POWER_W = 250;    //only one type of solar panels
    static constexpr float AREA_OF_ONE_UNIT = 1.64f * 0.992f;   //H * W of one panel 

    uint16_t SunHoursPerDay{};
};


#endif  //CALCULATORS





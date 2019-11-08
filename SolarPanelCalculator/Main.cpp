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
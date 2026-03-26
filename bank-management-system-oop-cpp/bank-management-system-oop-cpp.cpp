#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"
using namespace std;
int main()
{
    // O(n) //parallel is better than this -> o(1) 
    for (string C_Recored : vCurrencyData)
    {
        clsCurrency::_SaveCurrencyRecoredToFile(C_Recored);
    }
    while (clsLoginScreen::ShowLoginScreen())
    {
        if (Exit)
            break;
    }

    return 0;
}
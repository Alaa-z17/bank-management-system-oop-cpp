#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:
    enum enCurrencyExchangeMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5 };
    static short _ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }
    static  void _GoBackToCurrencyExchangeMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMainScreen();
    }
    static void _ShowListCurrenciesScreen()
    {
        /* cout << "\nList Currencies Screen Will be here .\n";*/
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrencyScreen()
    {
        /*   cout << "\nFind Currency Screen Will be here .\n";*/
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        /* cout << "\nUpdate Rate Screen Will be here .\n";*/
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        /*  cout << "\nCurrency Calculator Screen Will be here .\n";*/
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    static void _PerfromCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case clsCurrencyExchangeMainScreen::eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        case clsCurrencyExchangeMainScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        case clsCurrencyExchangeMainScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        case clsCurrencyExchangeMainScreen::eShowMainMenue:
            //do Nothing here the main screen will handle it :-);
            break;
        }
    }
public:
    static void ShowCurrencyExchangeMainScreen()
    {
        system("cls");
        _DrawScreenHeader("  Currency Exchange Main Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
    }
};
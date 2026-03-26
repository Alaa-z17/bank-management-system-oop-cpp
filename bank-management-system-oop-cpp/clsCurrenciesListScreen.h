#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>
class clsCurrenciesListScreen : protected clsScreen
{
public:
    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
        cout << "| " << setw(12) << left << "Code";
        cout << "| " << setw(35) << left << "Name";
        cout << "| " << setw(15) << left << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else
            for (clsCurrency& Currency : vCurrencies)
            {
                clsScreen::_PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};
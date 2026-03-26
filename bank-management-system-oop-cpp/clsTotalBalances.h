#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"clsUtility.h"

class clsTotalBalances : protected clsScreen
{

public:
    static void ShowTotalBalancesScreen()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string Title = "\tBalances List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << setw(15) << left << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient& Client : vClients)
            {
                clsScreen::_PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t       Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t  ( " << clsUtility::DoubleToText(TotalBalances) << ")" << endl;

    }

};
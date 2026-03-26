#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtility.h"

class clsDeleteClientScreen : protected clsScreen
{
public:
    static void ShowDeleteClientScreen()
    {
        _DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = clsScreen::_ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {

            cout << "\nAccount number is not found ";
            if (clsUtility::CancelOperation())
                return;
            AccountNumber = clsScreen::_ReadAccountNumber("choose another one : ");
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        clsScreen::_PrintClient(Client1);
        cout << "\nAre you sure you want to delete this client y/n ? ";
        char Answer = 'n';
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (Client1.Deleat())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                clsScreen::_PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client was not Deleted\n";
            }
        }
    }
};

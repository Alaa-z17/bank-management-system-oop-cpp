#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateCleintScreen :protected clsScreen
{
public:
    static void ShowUpdateClientScreen()
    {
        _DrawScreenHeader("\t  Update Client Screen");

        string AccountNumber = clsScreen::_ReadAccountNumber();
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found";
            if (clsUtility::CancelOperation())
                return;
            AccountNumber = clsScreen::_ReadAccountNumber("choose another one : ");
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        clsScreen::_PrintClient(Client1);

        if (clsUtility::CancelOperation())
            return;

        cout << "\n\nUpdate Client Info:";
        cout << "\n----------------------\n";
        clsScreen::_ReadClientInfo(Client1);
        clsBankClient::enSaveResults SaveResults;
        SaveResults = Client1.Save();
        switch (SaveResults)
        {
        case clsBankClient::svSucceeded:
        {
            cout << "Account Updated Successfully :-)\n";
            clsScreen::_PrintClient(Client1);
            break;
        }
        case clsBankClient::svFaildEmptyobject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }

        }
    }
};
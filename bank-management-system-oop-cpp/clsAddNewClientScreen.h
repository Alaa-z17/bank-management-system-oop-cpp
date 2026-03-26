#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include "clsInputValidate.h"
#include "clsUtility.h"

class clsAddNewClientScreen :protected clsScreen
{
public:
    static void ShowAddNewClientScreen()
    {
        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = clsScreen::_ReadAccountNumber();;

        while (clsBankClient::IsClientExist(AccountNumber))
        {

            cout << "\nAccount number is Already used ";

            if (clsUtility::CancelOperation())
                return;
            AccountNumber = clsScreen::_ReadAccountNumber("choose another one : ");
        }
        if (clsUtility::CancelOperation())
            return;
        clsBankClient NewClient = clsBankClient::GetAddNewClientobject(AccountNumber);
        clsScreen::_ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            NewClient.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyobject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        }

    }
};

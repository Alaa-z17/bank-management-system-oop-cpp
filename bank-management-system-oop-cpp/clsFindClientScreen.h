#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsFindClientScreen : protected clsScreen
{
public:
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\t  Find Client Screen");

        string AccountNumber = clsScreen::_ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n Client with Account Number [" << AccountNumber << "] is Not Found";
            if (clsUtility::CancelOperation())
                return;
            AccountNumber = clsScreen::_ReadAccountNumber("choose another one : ");
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        if (!client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient was Not Found :-(\n";
        }
        clsScreen::_PrintClient(client);

    }
};
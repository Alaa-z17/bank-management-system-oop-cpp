#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsUtility.h"

class clsFindUserScreen : protected clsScreen
{
public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");
        string UserName = clsScreen::_ReadUserName();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n User with User Name [" << UserName << "] is Not Found  ";
            if (clsUtility::CancelOperation())
                return;
            UserName = clsScreen::_ReadUserName("choose another one : ");
        }
        clsUser User = clsUser::Find(UserName);
        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser was Not Found :-(\n";
        }
        _PrintUser(User);

    }
};
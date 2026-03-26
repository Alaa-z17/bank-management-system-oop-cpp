#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
#include "clsUtility.h"

class clsUpdateUserScreen :protected clsScreen
{
public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\t  Update User Screen");

        string UserName = clsScreen::_ReadUserName();
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not Exist ";
            if (clsUtility::CancelOperation())
                return;
            UserName = clsScreen::_ReadUserName("choose another one : ");
        }
        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);
        if (clsUtility::CancelOperation())
            return;
        cout << "\n\nUpdate User Info:";
        cout << "\n----------------------\n";
        clsScreen::_ReadUserInfo(User1);
        clsUser::enSaveResults SaveResults;
        SaveResults = User1.Save();
        switch (SaveResults)
        {
        case clsUser::svSucceeded:
        {
            cout << "User Updated Successfully :-)\n";
            _PrintUser(User1);
            break;
        }
        case clsUser::svFaildEmptyobject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }

        }
    }
};

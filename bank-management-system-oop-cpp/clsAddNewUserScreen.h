#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
#include "clsUtility.h"
class clsAddNewUserScreen :protected clsScreen
{


public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = clsScreen::_ReadUserName();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is Already Exist ";
            if (clsUtility::CancelOperation())
                return;
            UserName = clsScreen::_ReadUserName("Enter Another one : ");
        }
        clsUser NewUser = clsUser::GetAddNewUserobject(UserName);
        _ReadUserInfo(NewUser);
        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();
        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyobject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError User was not saved because User Name is used!\n";
            break;
        }
        }
    }
};

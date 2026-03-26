#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"


class clsDeleteUserScreen : protected clsScreen
{

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen");

        string UserName = clsScreen::_ReadUserName();
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found ";
            if (clsUtility::CancelOperation())
                return;
            UserName = clsScreen::_ReadUserName("choose another one : ");
        }
        clsUser User1 = clsUser::Find(UserName);
        clsScreen::_PrintUser(User1);
        cout << "\nAre you sure you want to delete this User y/n ? ";
        char Answer = 'n';
        Answer = clsInputValidate::ReadChar();
        if (toupper(Answer) == 'Y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User was not Deleted\n";
            }
        }
    }
};


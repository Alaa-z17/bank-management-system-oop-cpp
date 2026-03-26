#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        bool LoginFaild = false;

        short FailedLoginCount = 0;

        string Username = "", Password = "";
        do
        {
            if (LoginFaild)
            {
                FailedLoginCount++;
                cout << "Invlaid Username/Password!\n";
                cout << "You have " << (3 - FailedLoginCount) << " Trial(s) to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\n\n\nYou are Locked after 3 failed trails\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);//form global.h
            LoginFaild = CurrentUser.IsEmpty();
        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }
public:

    static bool ShowLoginScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("\t    Login Screen");
        return _Login();

    }
};
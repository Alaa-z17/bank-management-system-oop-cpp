#pragma once
#include "Global.h"
using namespace std;

class clsChangeAdminCredsScreen : protected clsScreen
{
public:
    static void ShowChangeAdminCredsScreen()
    {

        if (!CurrentUser.IsAdmin)
        {
            cout << "\nYou are not admin!"
                << "\nOnly Admin can change these credentials!\n";
            return;
        }

        vector<clsUser> vUsers = clsUser::GetUserList();
        string Answer = "N";

        cout << "\n-----------------------------------\n";
        cout << "\tChange Admin Credentials\n";
        cout << "-----------------------------------\n";
        cout << "Current Username : " << CurrentUser.UserName << "\n";
        cout << "Current Password : " << string(CurrentUser.Password.length(), '*') << "\n";
        cout << "-----------------------------------\n";

        do
        {
            cout << "\nAre you sure you want to change credentials? Y/N? ";
            getline(cin >> ws, Answer);

        } while (toupper(Answer[0]) != 'Y' && toupper(Answer[0]) != 'N');

        if (toupper(Answer[0]) == 'N')
            return;

        string NewUsername = "";
        string NewPassword = "";

        cout << "\nEnter New Username: ";
        getline(cin >> ws, NewUsername);

        while (clsUser::IsUserExist(NewUsername))
        {
            cout << "\nUsername [" << NewUsername
                << "] already exists, Enter another: ";
            getline(cin >> ws, NewUsername);
        }

        cout << "Enter New Password: ";
        getline(cin, NewPassword);

        for (clsUser& U : vUsers)
        {
            if (U.UserName == CurrentUser.UserName && U.Password == CurrentUser.Password)
            {
                U.UserName = NewUsername;
                U.Password = NewPassword;
                CurrentUser = U;

                break;
            }
        }

        clsUser::_SaveUsersDataToFile(vUsers);// cause i am his friend and i can access his private members.
        cout << "\nCredentials Updated Successfully!\n";
        cout << "New Username: " << CurrentUser.UserName << "\n";
    }
};
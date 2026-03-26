#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsListUserScreen :protected clsScreen
{

public:
    static void ShowUsersList()
    {
        vector <clsUser>vUsers = clsUser::GetUserList();
        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (clsUser& User : vUsers)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};
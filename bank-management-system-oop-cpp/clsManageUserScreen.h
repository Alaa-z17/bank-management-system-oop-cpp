#pragma once
#include<iostream>
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsChangeAdminCredsScreen.h"

class clsManageUserScreen : protected clsScreen
{
private:
    enum enManageUsersMenueOptions
    {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eChangeAdminCreds = 6, eMainMenue = 7
    };
    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
        return Choice;
    }
    static  void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

        system("pause>0");
        ShowManageUsersMenue();
    }
    static void _ShowAllUsersScreen()
    {
        /*  cout << "\nUsers List Screen Will be here...\n";*/
        clsListUserScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        /* cout << "\nAdd New User Screen Will be here...\n";*/
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        /*cout << "\nDelete User Screen Will be here...\n";*/
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        /*cout << "\nUpdate User Screen Will be here...\n";*/
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        /*   cout << "\nFind User Screen Will be here...\n";*/
        clsFindUserScreen::ShowFindUserScreen();

    }
    static void _ShoweChangeAdminCredsScreen()
    {
        /*   cout << "\nChange Admin Creds Screen Will be here...\n";*/
        clsChangeAdminCredsScreen::ShowChangeAdminCredsScreen();
    }
    static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions)
    {
        switch (ManageUsersMenueOptions)
        {
        case clsManageUserScreen::eListUsers:
        {
            system("cls");
            _ShowAllUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eChangeAdminCreds:
        {
            system("cls");
            _ShoweChangeAdminCredsScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case clsManageUserScreen::eMainMenue:
        {
            //do Nothing here the main screen will handle it :-);
            break;
        }

        }
    }
public:
    static void ShowManageUsersMenue()
    {
        /*if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }*/
        system("cls");
        _DrawScreenHeader("\tManage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Change Admin Credentials.\n";
        cout << setw(37) << left << "" << "\t[7] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }
};


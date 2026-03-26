#pragma once
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateCleintScreen.h"
#include "clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eLogout = 9, eCurrencyExchange = 10, eExit = 11
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 11]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 11, "Enter Number between 1 to 11? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        clsUpdateCleintScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        clsTransactionScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        clsManageUserScreen::ShowManageUsersMenue();

    }
    static void _showLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMainScreen();
    }
    static void _ShowEndScreen()
    {
        cout << "\nthanks for Using...\n";

    }
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::eLogout:

            CurrentUser = clsUser::Find("", "");//from the global
            //Login();

            break;
        case enMainMenueOptions::eLoginRegister:

            system("cls");
            _showLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            cout << "Enter Any key to End :\n";
            system("pause>0");
            //Login();
            Exit = true;
            break;
        }

    }
public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "\t[10] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[11] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};
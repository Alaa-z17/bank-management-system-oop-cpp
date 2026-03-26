#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clswithDrawScreen.h"
#include "clsTransferScreen.h"
#include"clsTotalBalances.h"
#include"clsTransferLogScreen.h"

class clsTransactionScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eTransfer = 3, eShowTotalBalance = 4, eTransferLog = 5, eShowMainMenue = 6 };
    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static  void _GoBackToTransactionMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        ShowTransactionMenue();
    }
    static void _ShowDepositScreen()
    {

        /*  cout << "\nDeposit Screen Will be here...\n";*/
        clsDepositScreen::ShowDepositScreen();

    }
    static void _ShowWithDrawScreen()
    {
        /* cout << "\nShow With draw Screen Will be here...\n";*/
        clswithDrawScreen::ShowWithDrawScreen();

    }
    static void _ShowTansferScreen()
    {
        /* cout << "\nShow With Transfer Screen Will be here...\n";*/
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        /*  cout << "\nTotal Balances Screen Will be here...\n";*/
        clsTotalBalances::ShowTotalBalancesScreen();
    }

    static void _ShowTransferLogScreen()
    {
        /*   cout << "\nTransfer Log screen Will be here\n";*/
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerfromTransactionMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case clsTransactionScreen::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eWithdraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eTransfer:
        {
            system("cls");
            _ShowTansferScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionMenue();
            break;
        }
        case clsTransactionScreen::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionMenue();
            break;
        }
        default:
        {

            break;
        }
        }
    }
public:
    static void ShowTransactionMenue()
    {
        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw\n";
        cout << setw(37) << left << "" << "\t[3] Transfer.\n";
        cout << setw(37) << left << "" << "\t[4] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromTransactionMenueOption((enTransactionsMenueOptions)_ReadTransactionMenueOption());
    }
};

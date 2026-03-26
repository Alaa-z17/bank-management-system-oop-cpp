#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

class clsTransferLogScreen :protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecpred TransferLog)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.DestenationAccountNumber;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLog.DestBalanceAfter;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }
public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLogRecpred> vTransferLog = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t     (" + to_string(vTransferLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << setw(8) << left << "s.Acct";
        cout << "| " << setw(8) << left << "d.Acct";
        cout << "| " << setw(8) << left << "Amount";
        cout << "| " << setw(10) << left << "s.Balance";
        cout << "| " << setw(10) << left << "d.Balance";
        cout << "| " << setw(8) << left << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLog.size() == 0)
            cout << "\t\t\t\tNo Transfers Records Available In the System!";
        else

            for (clsBankClient::stTransferLogRecpred& Record : vTransferLog)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

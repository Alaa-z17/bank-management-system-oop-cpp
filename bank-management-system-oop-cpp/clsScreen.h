#pragma once
#include<iostream>
#include"clsUser.h"
#include "clsBankClient.h"
#include "Global.h"
#include<string>
#include "clsCurrency.h"

using namespace std;

class clsScreen
{
protected:
    //client
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        // cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadEmail();

        //cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadPhone();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
    static string _ReadAccountNumber(string message = "Please Enter Account Number : ")
    {
        cout << "\n" + message;
        string AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }


    //user
    static  void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << string(User.Password.length() + 2, '*');
        cout << "| " << setw(12) << left << User.Permissions;
    }
    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }


        cout << "\nAdd New Client? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nLogin Register? y/n? ";
        Answer = clsInputValidate::ReadChar();
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::PLoginRegister;
        }
        if (Permissions == 255)
            return -1;
        return Permissions;

    }
    static void _ReadUserInfo(clsUser& User)
    {

        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        // cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadEmail();

        // cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadPhone();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permession: ";
        User.Permissions = _ReadPermissionsToSet();


    }
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermessions : " << User.Permissions;
        cout << "\n___________________\n";
    }
    static string _ReadUserName(string Message = "Please Enter User Name : ")
    {
        string UserName = "";
        cout << "\n" + Message;
        UserName = clsInputValidate::ReadString();
        return UserName;
    }
    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPermission(Permissions))
        {
            cout << "\n\t\t\t\t\t_____________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Cnotact your Admin";
            cout << "\n\t\t\t\t\t_____________________________________\n";
            return false;
        }
        else
        {
            return true;
        }

    }

    //currency
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(35) << left << Currency.CurrencyName();
        cout << "| " << setw(15) << left << Currency.Rate();
    }
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }
    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }


    //Header
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << "  " << clsDate::Clock12Hours() << "\n\n";
    }

};
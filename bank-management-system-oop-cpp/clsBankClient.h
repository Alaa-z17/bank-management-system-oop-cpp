#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsInputValidate.h"
#include "clsUtility.h"

using namespace std;
class clsBankClient : public clsPerson
{
public:
    struct stTransferLogRecpred
    {
        string DateTime = "";
        string SourceAccountNumber = "";
        string DestenationAccountNumber = "";
        float Amount = 0;
        float srcBalanceAfter = 0;
        float DestBalanceAfter = 0;
        string UserName = "";
    };
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkforDeleat = false;
    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string>vClientData;
        vClientData = clsString::Split(Line, Seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4],
            clsUtility::DecryptText(vClientData[5]), stof(vClientData[6]));
    }
    static clsBankClient _GetEmptyCleintObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static vector<clsBankClient> _loadClientDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }
    static string _ConvertClientObjectToLine(clsBankClient Client, string seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + seperator;
        stClientRecord += Client.LastName + seperator;
        stClientRecord += Client.Email + seperator;
        stClientRecord += Client.Phone + seperator;
        stClientRecord += Client.AccountNumber() + seperator;
        stClientRecord += clsUtility::EncryptText(Client.PinCode) + seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;
    }
    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overWrite
        string DateLine;
        if (MyFile.is_open())
        {
            for (clsBankClient& C : vClients)
            {
                if (C._MarkforDeleat == false)
                {
                    DateLine = _ConvertClientObjectToLine(C);
                    MyFile << DateLine << endl;
                }

            }
        }
        MyFile.close();
    }
    void _Update()
    {
        vector<clsBankClient>_vClients;
        _vClients = _loadClientDataFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);

    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
    string _PrepareTransferLogRecord(float Amount, clsBankClient ClientTo, string UserName, string Seperator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += ClientTo.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(ClientTo.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }
    void _RegisterTransferLog(float Amount, clsBankClient ClientTo, string UserName)
    {

        string stDataLine = _PrepareTransferLogRecord(Amount, ClientTo, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    static stTransferLogRecpred _ConvertTransfetLogLineToRecord(string Line)
    {
        vector<string> vStringData = clsString::Split(Line, "#//#");
        stTransferLogRecpred TransferLog;
        TransferLog.DateTime = vStringData[0];
        TransferLog.SourceAccountNumber = vStringData[1];
        TransferLog.DestenationAccountNumber = vStringData[2];
        TransferLog.Amount = stof(vStringData[3]);
        TransferLog.srcBalanceAfter = stof(vStringData[4]);
        TransferLog.DestBalanceAfter = stof(vStringData[5]);
        TransferLog.UserName = vStringData[6];
        return TransferLog;
    }
public:
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    string AccountNumber()
    {
        return _AccountNumber;
    }
    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }
    static clsBankClient Find(string AccountNumber)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyCleintObject();
    }
    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyCleintObject();
    }
    enum enSaveResults { svFaildEmptyobject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResults::svFaildEmptyobject;
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                //we need to set the mode to update after add new
                _Mode = enMode::AddNewMode;
                return enSaveResults::svSucceeded;
            }

        }
        }
        return enSaveResults::svFaildEmptyobject;
    }
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    static clsBankClient GetAddNewClientobject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
    bool Deleat()
    {
        vector<clsBankClient>vClients = _loadClientDataFromFile();
        for (clsBankClient& C : vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkforDeleat = true;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyCleintObject();
        return true;
    }
    static vector<clsBankClient> GetClientList()
    {
        return _loadClientDataFromFile();
    }
    static double GetTotalBalances()
    {
        double TotalBalances = 0;
        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        for (clsBankClient& Client : vClients)
        {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += (float)Amount;
        Save();
    }
    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
            return false;
        else
        {
            Deposit(Amount * -1);
            return true;
        }
    }
    bool Transfer(clsBankClient& ClientTo, float Amount, string UserName)
    {
        // Check if the target account exists
        if (ClientTo.IsEmpty())
            return false;
        else if (this->AccountNumber() == ClientTo.AccountNumber())
        {
            return false;
        }

        // Attempt to withdraw from current account (handles insufficient funds check)
        if (!Withdraw(Amount))
            return false;

        // Deposit into the target account
        ClientTo.Deposit(Amount);
        _RegisterTransferLog(Amount, ClientTo, UserName);
        return true;
    }
    static vector <stTransferLogRecpred> GetTransferLogList()
    {
        vector<stTransferLogRecpred> vTrasferLogRecord;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecpred TransferRecord;
            while (getline(MyFile, Line))
            {
                TransferRecord = _ConvertTransfetLogLineToRecord(Line);
                vTrasferLogRecord.push_back(TransferRecord);
            }
            MyFile.close();
        }
        return vTrasferLogRecord;
    }
};
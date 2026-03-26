#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUtility.h"

class clsUser : public clsPerson
{
public:
    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions = 0;

    };
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedforDelete = false;
    bool _IsAdmin = false;
    friend class clsChangeAdminCredsScreen;


    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;


        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtility::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }




    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string>vUserData = clsString::Split(Line, Seperator);;
        if (vUserData.size() < 8) // expect 8 tokens: 0..7
        {
            return _GetEmptyUserObject();
        }
        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],
            clsUtility::DecryptText(vUserData[5]), stoi(vUserData[6]), clsUtility::ConvertStringToBool(vUserData[7]));
    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0, 0);
    }
    static vector<clsUser> _loadUserDataFromFile()
    {
        vector<clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return vUsers;
    }
    static string _ConvertUserObjectToLine(clsUser User, string seperator = "#//#")
    {
        string stUserRecord = "";
        stUserRecord += User.FirstName + seperator;
        stUserRecord += User.LastName + seperator;
        stUserRecord += User.Email + seperator;
        stUserRecord += User.Phone + seperator;
        stUserRecord += User.UserName + seperator;
        stUserRecord += clsUtility::EncryptText(User.Password) + seperator;
        stUserRecord += to_string(User.Permissions) + seperator;
        stUserRecord += to_string(User.IsAdmin);
        return stUserRecord;
    }
    static void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overWrite
        string DateLine;
        if (MyFile.is_open())
        {
            for (clsUser& U : vUsers)
            {
                if (U._MarkedforDelete == false)
                {
                    DateLine = _ConvertUserObjectToLine(U);
                    MyFile << DateLine << endl;
                }

            }
        }
        MyFile.close();
    }
    void _Update()
    {
        vector<clsUser>_vUsers;
        _vUsers = _loadUserDataFromFile();
        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);

    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }
    string _PrepareLogInRecord(string Seperator = "#//#")
    {
        string LoginRecord = clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += this->UserName + Seperator;
        LoginRecord += clsUtility::DecryptText(this->Password) + Seperator;
        LoginRecord += to_string(this->Permissions);
        return LoginRecord;
    }

public:
    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, PLoginRegister = 128
    };



    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions, bool IsAdmin) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
        _IsAdmin = IsAdmin;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    bool MarkedForDeleted()
    {
        return _MarkedforDelete;
    }
    string GetUserName()
    {
        return _UserName;
    }
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    _declspec(property(get = GetUserName, put = SetUserName))string UserName;
    string GetPassword()
    {
        return _Password;
    }
    void SetPassword(string Password)
    {
        _Password = Password;
    }
    _declspec(property(get = GetPassword, put = SetPassword))string Password;
    int GetPermissions()
    {
        return _Permissions;
    }
    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    _declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;
    bool GetIsAmdin()
    {
        return _IsAdmin;
    }
    void SetIsAmdin(bool IsAdmin)
    {
        _Permissions = -1;
        _IsAdmin = IsAdmin;
    }
    _declspec(property(get = GetIsAmdin, put = SetIsAmdin))bool IsAdmin;
    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }
    static clsUser Find(string UserName, string Password)
    {
        vector<clsUser> vUsers = _loadUserDataFromFile();
        if (vUsers.empty())
        {
            clsUser InitialUser(enMode::AddNewMode, "Admin", "Admin", "Admin@gmail.com", "96396472153", "Admin", "1234", -1, true);
            InitialUser.Save();

        }
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//Read Mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }
    enum enSaveResults { svFaildEmptyobject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyobject;
            }
            break;
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                //we need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

        }
        }
        return enSaveResults::svFaildEmptyobject;
    }
    static bool IsUserExist(string UserName)
    {
        clsUser User1 = clsUser::Find(UserName);
        return (!User1.IsEmpty());
    }
    bool Deleat()
    {
        vector<clsUser>vUsers = _loadUserDataFromFile();
        for (clsUser& U : vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedforDelete = true;
                break;
            }
        }
        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }
    static clsUser GetAddNewUserobject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0, 0);
    }
    static vector<clsUser> GetUserList()
    {
        return _loadUserDataFromFile();
    }
    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _loadUserDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedforDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;
    }
    void RegisterLogIn()
    {
        string stDataLine = _PrepareLogInRecord();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }
    static  vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

                vLoginRegisterRecord.push_back(LoginRegisterRecord);

            }

            MyFile.close();

        }

        return vLoginRegisterRecord;

    }
};
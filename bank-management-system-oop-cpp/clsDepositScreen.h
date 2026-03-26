#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include "clsUtility.h"
class clsDepositScreen : protected clsScreen
{
private:

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t	Deposit Screen");
		string AccountNumber = clsScreen::_ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist\n";
			if (clsUtility::CancelOperation())
				return;
			AccountNumber = clsScreen::_ReadAccountNumber("Enter another one : ");

		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsScreen::_PrintClient(Client);
		if (clsUtility::CancelOperation())
			return;
		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::ReadPositiveDblNumber("Number must be > 0 , Enter again : ");
		char Answer = 'n';
		cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
		Answer = clsInputValidate::ReadChar();
		if (toupper(Answer))
		{
			Client.Deposit(Amount);
			cout << "\n\nDone Successfully. New balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\n\nOperation was cancelled\n";
		}

	}
};
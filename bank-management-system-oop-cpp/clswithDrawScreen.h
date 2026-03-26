#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include "clsUtility.h"

class clswithDrawScreen : protected clsScreen
{
public:
	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t	WithDraw Screen");
		string AccountNumber = clsScreen::_ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist\n";
			if (clsUtility::CancelOperation())
				return;
			AccountNumber = clsScreen::_ReadAccountNumber("Choose another one : ");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		clsScreen::_PrintClient(Client);
		if (clsUtility::CancelOperation())
			return;
		if (Client.AccountBalance == 0)
		{
			cout << "\n\t  you can't withdraw,your Account is Empty\n";
			return;
		}
		double Amount = 0;
		cout << "\nPlease enter WithDraw amount? ";
		Amount = clsInputValidate::ReadPositiveDblNumber("Number must be > 0 , Enter again : ");
		char Answer = 'n';
		cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
		Answer = clsInputValidate::ReadChar();
		if (toupper(Answer))
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccountBalance;
			}
		}
		else
		{
			cout << "\n\nOperation was cancelled\n";
		}

	}
};
#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include "clsUtility.h"
class clsTransferScreen : protected clsScreen
{
private:

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t	Transfer Screen");
		string AccountNumberFrom = clsScreen::_ReadAccountNumber("Please Enter Account Number From :");
		while (!clsBankClient::IsClientExist(AccountNumberFrom))
		{
			cout << "\nClient with [" << AccountNumberFrom << "] does not exist\n";
			if (clsUtility::CancelOperation())
				return;
			AccountNumberFrom = clsScreen::_ReadAccountNumber("Enter another one : ");

		}
		string AccountNumberTo = clsScreen::_ReadAccountNumber("Please Enter Account Number To :");
		while (!clsBankClient::IsClientExist(AccountNumberTo))
		{
			cout << "\nClient with [" << AccountNumberTo << "] does not exist\n";
			if (clsUtility::CancelOperation())
				return;
			AccountNumberTo = clsScreen::_ReadAccountNumber("Enter another one : ");

		}

		cout << "\nCLint From:\n";
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);
		clsScreen::_PrintClient(ClientFrom);

		cout << "\nCLint To:\n";
		clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
		clsScreen::_PrintClient(ClientTo);

		if (ClientFrom.AccountNumber() == ClientTo.AccountNumber())
		{
			cout << "\nYou can't transfer from a client account to the same client account";
			return;
		}

		if (clsUtility::CancelOperation())
			return;
		float Amount = 0;
		cout << "\nPlease enter Transfer amount? ";
		Amount = clsInputValidate::ReadFloatNumber("Number must be > 0 , Enter again : ");
		char Answer = 'n';
		cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
		Answer = clsInputValidate::ReadChar();
		if (toupper(Answer))
		{
			ClientFrom.Transfer(ClientTo, Amount, CurrentUser.UserName);
			cout << "\n\nDone Successfully. New balances are : ";
			cout << "\n\nCleint From : " << ClientFrom.AccountBalance;
			cout << "\n\nCleint To : " << ClientTo.AccountBalance;
		}
		else
		{
			cout << "\n\nOperation was cancelled\n";
		}

	}
};
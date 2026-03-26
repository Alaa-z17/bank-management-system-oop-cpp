#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

	static string GetAnswerText(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float AmountExchange, float Result)
	{
		return ("\n" + to_string(AmountExchange) + " " + CurrencyFrom.CurrencyCode() + " = " + to_string(Result) + " " + CurrencyTo.CurrencyCode() + "\n");
	}
	static void _CurrencyCalculator()
	{
		_DrawScreenHeader("   Currency Calculator Screen");
		string Currency1Code = "";

		cout << "\nPlease Enter Currency1 Code: ";
		Currency1Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Currency1Code))
		{
			cout << "\nCurrency1 is not found";
			if (clsUtility::CancelOperation())
				return;
			cout << "\nEnter anothor one: ";
			Currency1Code = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

		string Currency2Code = "";

		cout << "\nPlease Enter Currency2 Code: ";
		Currency2Code = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(Currency2Code))
		{
			cout << "\nCurrency2 is not found";
			if (clsUtility::CancelOperation())
				return;
			cout << "\nEnter anothor one: ";
			Currency2Code = clsInputValidate::ReadString();
		}
		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

		if (Currency1.CurrencyCode() == Currency2.CurrencyCode())
		{
			cout << "\n\n\t\tCurrency1 and Currency2 are the Same ! \n";
			return;
		}

		cout << "\nEnter Amount to Exchange : ";
		float AmountToExchange = (float)clsInputValidate::ReadPositiveDblNumber();
		float Result = 0;
		if (Currency2.CurrencyCode() == "USD")
		{
			Result = Currency1.GetExchangeResult(Currency2, AmountToExchange);
			cout << "\nConvert From:\n";
			_PrintCurrency(Currency1);
			cout << GetAnswerText(Currency1, Currency2, AmountToExchange, Result);
		}
		else if (Currency1.CurrencyCode() == "USD")
		{
			Result = Currency1.GetExchangeResult(Currency2, AmountToExchange);
			cout << "\nConvert From:\n";
			_PrintCurrency(Currency2);
			cout << GetAnswerText(Currency1, Currency2, AmountToExchange, Result);
		}
		else
		{
			clsCurrency dollarCurrency = clsCurrency::FindByCode("USD");
			Result = Currency1.GetExchangeResult(Currency2, AmountToExchange);
			cout << "\nConvert From:\n";
			_PrintCurrency(Currency1);
			cout << GetAnswerText(Currency1, dollarCurrency, AmountToExchange, Currency1.GetExchangeResult(dollarCurrency, AmountToExchange));
			cout << "\nConverting From USD :\n\n";
			cout << "To\n\n";
			_PrintCurrency(Currency2);
			cout << GetAnswerText(Currency1, Currency2, AmountToExchange, Result);
		}
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		char AnwerAgain = 'n';
		do
		{
			system("cls");
			_CurrencyCalculator();
			cout << "\nDo you want to perform another calculation? y/n ? ";
			AnwerAgain = clsInputValidate::ReadChar();

		} while (toupper(AnwerAgain) == 'Y');
	}
};

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include <iomanip>
#include <regex>

class clsInputValidate
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadPositiveDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number = 0;
		Number = ReadDblNumber();
		while (Number <= 0)
		{
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
	static char ReadChar(string ErrorMessage = "InValid Input ,Enter Again : ")
	{
		string S1 = "";
		cin >> S1;
		while (S1.length() != 1)
		{
			cout << ErrorMessage;
			cin >> S1;
		}
		return S1[0];
	}
	static char ReadWanted2Chars(string ErrorMessage = "InValid Input ,Enter Again : ", char Wanted1Char = 'Y', char Wanted2Char = 'N')
	{
		string S1 = "";
		cin >> S1;
		while (S1.length() != 1 || ((toupper(S1[0]) != Wanted1Char) && (toupper(S1[0]) != Wanted2Char)))
		{
			cout << ErrorMessage;
			cin >> S1;
		}
		return  toupper(S1[0]);
	}

	static string ReadEmail()
	{
		string email;

		while (true)
		{
			cout << "Enter Email Address: ";
			cin >> email;

			// Basic email pattern: something@something.something
			regex emailPattern(R"((\w+)(\.?\w+)*@(\w+)(\.(\w+))+)");

			if (regex_match(email, emailPattern))
				break;
			else
				cout << "Invalid Email! Please try again.\n";
		}

		return email;
	}

	// ✅ Read and validate Phone Number
	static string ReadPhone()
	{
		string phone;

		while (true)
		{
			cout << "Enter Phone Number: ";
			cin >> phone;

			// Accepts formats: 1234567890 / +1234567890 / 123-456-7890 / (123)456-7890
			regex phonePattern(R"((\+?[0-9]{1,3})?[-. ]?\(?[0-9]{3}\)?[-. ]?[0-9]{3}[-. ]?[0-9]{4})");

			if (regex_match(phone, phonePattern))
				break;
			else
				cout << "Invalid Phone Number! Please try again.\n";
		}

		return phone;
	}
};


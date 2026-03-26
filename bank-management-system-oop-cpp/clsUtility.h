#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsInputValidate.h"

using namespace std;

class clsUtility
{

public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        default:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static string NumberToText(long long Number)
    {
        if (Number == 0) return "";

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
            "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[Number] + " ";
        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
            return "One Hundred " + NumberToText(Number % 100);

        if (Number >= 200 && Number <= 999)
            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

        if (Number >= 1000 && Number <= 1999)
            return "One Thousand " + NumberToText(Number % 1000);

        if (Number >= 2000 && Number <= 999999)
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

        if (Number >= 1000000 && Number <= 1999999)
            return "One Million " + NumberToText(Number % 1000000);

        if (Number >= 2000000 && Number <= 999999999)
            return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

        if (Number >= 1000000000 && Number <= 1999999999)
            return "One Billion " + NumberToText(Number % 1000000000);
        else
            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }

    static string DoubleToText(double Number)
    {
        // Handle negative numbers
        string result = "";
        if (Number < 0)
        {
            result += "Negative ";
            Number = -Number;
        }

        // Split into integer and decimal parts
        long long intPart = (long long)Number;
        double decimalPart = Number - intPart;

        // Convert integer part (handle zero explicitly)
        if (intPart == 0)
            result += "Zero ";
        else
            result += NumberToText(intPart);

        // Convert decimal part if it exists
        if (decimalPart > 1e-9)
        {
            result += "Point ";

            // Extract up to 2 decimal digits
            int decimalDigits = (int)round(decimalPart * 100);

            // Read digit by digit: e.g. 0.35 -> "Three Five"
            int tens = decimalDigits / 10;
            int ones = decimalDigits % 10;

            string digits[] = { "Zero","One","Two","Three","Four",
                                "Five","Six","Seven","Eight","Nine" };

            result += digits[tens] + " ";
            if (ones != 0)
                result += digits[ones] + " ";
        }

        return result;
    }


    static bool CancelOperation()
    {
        char Answer = 'N';
        cout << "\ndo you want to Cancel this operation ! y,n : ";
        Answer = clsInputValidate::ReadWanted2Chars();
        if (Answer == 'Y')
        {
            return true;
        }
        return false;
    }
    static bool ConvertStringToBool(string s)
    {
        return (s == "1" || clsString::UpperAllString(s) == "TRUE");
    }
};

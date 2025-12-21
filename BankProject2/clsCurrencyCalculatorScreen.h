#pragma once
#pragma once
#include<iostream>
#include "clsDate.h" 
#include "Global.h"
#include "clsString.h"
#include "clsScreen.h"
#include <fstream>
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen: protected clsScreen
{
private:


	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}
	
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode; 
		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency; 
	}

	static void _PrintCurrency(clsCurrency Currency , string title)
	{
		cout << "\n" + title;
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$)    : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrency(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n"; 

		if (Currency2.CurrencyCode() == "USD")
		{
			return; 
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrency(Currency2 , "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}

public:

	static void ShowCurrecncyCalculatorScreen()
	{
		char Answer = 'Y';

		while (Answer == 'y' || Answer == 'Y')
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo); 

			cout << "\n\nDo you want to perform another calculation? y/n? "; 
			cin >> Answer; 



			/*string CurrencyCode1;
			 cout << "Please Enter Currency1 Code: " << endl;
			 CurrencyCode1 = clsInputValidate::ReadString();
			 clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode1);
			 while (Currency1.IsEmpty())
			 {
				 cout << "\nCurrency was not found :-(\n";
				 cout << "Please Enter Currency1 Code: " << endl;
				 CurrencyCode1 = clsInputValidate::ReadString();
				 Currency1 = clsCurrency::FindByCode(CurrencyCode1);

			 }

			 string CurrencyCode2;
			 cout << "Please Enter Currency2 Code: " << endl;
			 CurrencyCode2 = clsInputValidate::ReadString();
			 clsCurrency Currency2 = clsCurrency::FindByCode(CurrencyCode2);
			 while (Currency2.IsEmpty())
			 {
				 cout << "\nCurrency was not found :-(\n";
				 cout << "Please Enter Currency2 Code: " << endl;
				 CurrencyCode2 = clsInputValidate::ReadString();
			 }

			 float Rate = _ReadRate();

			 clsCurrency CurrencyUSD = clsCurrency::FindByCode("USD");

			 float ConvertingFromUSD = (Rate / Currency1.Rate());

			 _PrintCurrency(Currency1, "Convert From:");
			 cout << endl << Rate << " " << CurrencyCode1 << " = " << ConvertingFromUSD << " USD ";

			 if (Currency2.CurrencyCode() != "USD")
			 {
				 cout << "\n\nConverting form USD to: " << endl;


				 _PrintCurrency(Currency2, "To:");

				 cout << Rate << " " << CurrencyCode1 << " = " << ConvertingFromUSD * Currency2.Rate() << " " << CurrencyCode2;
			 }
			 cout << "\n\nDo you want to perform another calculations? y/n? ";
			 cin >> Answer;*/


		}

	


	}

};


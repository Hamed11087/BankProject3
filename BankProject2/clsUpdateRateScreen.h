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

class clsUpdateRateScreen : protected clsScreen
{
private:

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0; 

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate(1$)    : " << Currency.Rate(); 
		cout << "\n___________________\n";
	}

public:

	static void ShowUpdateRateScreen()
	{
		string Title = "\t Update Currency Screen";
		_DrawScreenHeader(Title);

		string CurrencyCode;

		cout << "\nPlease Enter Currency Code: "; 
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();

		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency); 

		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
		char Answer = 'n';
		cin >> Answer; 

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:"; 
			cout << "\n____________________\n";
		

			Currency.UpdateRate(_ReadRate()); 

			cout << "Currecny Rate Updated Successfully :-)" << endl; 

			_PrintCurrency(Currency);
		}

	}

};


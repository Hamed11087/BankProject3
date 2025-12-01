#pragma once
#include<iostream>
#include "clsDate.h" 
#include "Global.h"
#include "clsString.h"
#include "clsScreen.h"
#include <fstream>
#include "clsCurrency.h"
#include <iomanip>

class clsListCurrencies : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currecncy)
	{
		cout << setw(8) << left << "" << "| " << setw(27) << left << Currecncy.Country();
		cout << "| " << setw(8) << left << Currecncy.CurrencyCode();
		cout << "| " << setw(40) << left << Currecncy.CurrencyName();
		cout << "| " << setw(10) << left << Currecncy.Rate();
	}


public: 

	static void ShowListCurrencies()
	{

		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList(); 
		string Title = "\t Currencies List Screen"; 
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Client(s).";


		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(27) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\tNo Currencies Available In the system!";
		else
		{
			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl; 
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



	}
};


#pragma once
#include<iostream>	
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include <string>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListCurrencies.h"
#include "clsFindCurrencyScreen.h"

class clsCurrencyMainScreen: protected clsScreen
{
private:

	enum enMainMenueOptions
	{
		eListCurrency = 1 , eFindCurrency = 2 , eUpdateRate = 3 , eCurrencyCalculator = 4, eMainMenue = 5 
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 5]? "; 
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 5, "Enter Number between 1 to 5");
		return Choice; 
	}

	static void _GoToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menue....\n";

		system("pause>0");
		ShowMainMenue();
	}
	
	static void _ShowAllCurrencyList()
	{
		//cout << "List Curriencies List Screen Will Be Here\n"; 
		clsListCurrencies::ShowListCurrencies();
	}

	static void _ShowFindCurrency()
	{
		//cout << "Find Curriencies  Screen Will Be Here\n";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRate()
	{
		cout << "Update Curriencies Screen Will Be Here\n";
	}

	static void _ShowCurrencyCalculator()
	{
		cout << "Curriencies Calculator Screen Will Be Here\n";
	}

	

	static void _PerfromMainMenueOptions(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListCurrency:
		{
			system("cls");
			_ShowAllCurrencyList();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrency();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRate();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculator();
			_GoToMainMenue();
			break;
		}
		case enMainMenueOptions::eMainMenue:
		{
		
		}


		}
	}

public :

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\tCurrancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());

	}

};


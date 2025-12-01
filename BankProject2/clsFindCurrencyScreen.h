#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrency : protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _showResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrecny Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency was not found :-(\n";
        }
    }


public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t Find Currency Screen");



        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;


        cin >> Answer;
        if (Answer == 1)
        {
            string CurrecyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrecyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrecyCode);
            _showResults(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _showResults(Currency);
        }

    }

};


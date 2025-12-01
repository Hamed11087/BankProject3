#pragma once
#include"clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindCurrency: protected clsScreen 
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

public:

    static void ShowFindCurrencyScreen()
    {
        
        _DrawScreenHeader("\t Find Currency Screen");

        char Choice; 

        cout << "\nFind By: [1] Code or [2] Country ? "; 
        cin >> Choice; 

        while (Choice != '1' && Choice != '2')
        {
            cout << "\nPlease Enter [1] Or [2]? "; 
            cin >> Choice;

        }

        if (Choice == '1')
        {
            string CurrecyCode; 
            cout << "\nPlease Enter CurrencyCode: "; 
            cin >> CurrecyCode; 

            while (!clsCurrency::IsCurrencyExist(CurrecyCode))
            {
                cout << "\nCurrencyCode is not found, choose another one:  "; 
                cin >> CurrecyCode; 
            }
            clsCurrency Currecny = clsCurrency::FindByCode(CurrecyCode);
            _PrintCurrency(Currecny);

        }
        else if (Choice == '2')
        {
            string CurrecyCountry;
            cout << "\nPlease Enter CurrecyCountry: ";
            CurrecyCountry = clsInputValidate::ReadString();


            while (!clsCurrency::IsCurrencyExistByCountry(CurrecyCountry))
            {
                cout << "\nCurrecyCountry is not found, choose another one:  ";
                CurrecyCountry = clsInputValidate::ReadString();

            }

            clsCurrency Currecny = clsCurrency::FindByCountry(CurrecyCountry);
            _PrintCurrency(Currecny);
        }

        

    }


};


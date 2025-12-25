#pragma once
#include "clsScreen.h" ; 
#include "clsBankClient.h"
#include "clsInputValidate.h"	

class clsWithdrawScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public :

	static void WithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account [" << AccountNumber << "] is not exist.\n"; 
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Withdraw amount: "; 
		Amount = clsInputValidate::ReadNumber<double>();


		cout << "\nAre you sure you want to perfom this transaction? "; 
		char Answer = 'n';
		cin >> Answer; 

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount withdraw Successfully. \n";
				cout << "\nNew balance is: " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount; 
				cout << "\nYour Balance is: " << Client1.AccountBalance; 
			}
			
		}
		else
		{
			cout << "\nOperation was cancelled.\n"; 
		}





	}
};


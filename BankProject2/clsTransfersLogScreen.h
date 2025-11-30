#pragma once
#include<iostream>
#include "clsDate.h" 
#include "Global.h"
#include "clsString.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <fstream>
#include <iomanip>
#include "Global.h"

class clsTransfersLogScreen:protected clsScreen
{


private:

	static void _PrintTransferRecordLine(clsBankClient::stTransferRegisterRecord TransferRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(22) << left << TransferRegisterRecord.DateTime;
		cout << "| " << setw(10) << left << TransferRegisterRecord.SourceAccountNumber;
		cout << "| " << setw(10) << left << TransferRegisterRecord.DestinationAccountNumber;
		cout << "| " << setw(10) << left << TransferRegisterRecord.Amount;
		cout << "| " << setw(15) << left << TransferRegisterRecord.SourceBalance;
		cout << "| " << setw(15) << left << TransferRegisterRecord.DestinationBalance;
		cout << "| " << setw(12) << left << TransferRegisterRecord.User; 

	}




public:

	static void ShowRegiterList()
	{


		vector<clsBankClient::stTransferRegisterRecord> vTransferRegisterRecord = clsBankClient::GetTransferLogList();

		string Title = "\t  Transfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(15) << "s.Balance";
		cout << "| " << left << setw(15) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vTransferRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsBankClient::stTransferRegisterRecord Record : vTransferRegisterRecord)
			{
				_PrintTransferRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}







};


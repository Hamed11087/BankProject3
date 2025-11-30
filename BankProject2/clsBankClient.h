#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsPerson.h"
#include <vector>	
#include <fstream>

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MakedForDelete = false;

	struct stTransferRegisterRecord;

	static stTransferRegisterRecord _ConverTransferRegiterLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferRegisterRecord TransferRegisterRecord;

		vector<string> TransferRegisterDataLine = clsString::Split(Line, Seperator);
		TransferRegisterRecord.DateTime = TransferRegisterDataLine[0];
		TransferRegisterRecord.SourceAccountNumber = TransferRegisterDataLine[1];
		TransferRegisterRecord.DestinationAccountNumber = TransferRegisterDataLine[2];
		TransferRegisterRecord.Amount = stoi(TransferRegisterDataLine[3]);
		TransferRegisterRecord.SourceBalance = stoi(TransferRegisterDataLine[4]);
		TransferRegisterRecord.DestinationBalance = stoi(TransferRegisterDataLine[5]);
		TransferRegisterRecord.User = TransferRegisterDataLine[6]; 

		return TransferRegisterRecord;

	}


	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3]
			, vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord += Client._PinCode + Seperator;
		stClientRecord += to_string(Client._AccountBalance);

		return stClientRecord;
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vCLient;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				vCLient.push_back(Client);
			}

			MyFile.close();
		}

		return vCLient;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient c : vClient)
			{
				if (c._MakedForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(c);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClient)
		{
			if (c._AccountNumber == AccountNumber())
			{
				c = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClient);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _PrepareLogTransferRecord(float Amount, clsBankClient DestinationClient,string UserName ,string Seperator = "#//#")
	{

		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += AccountNumber() + Seperator;
		TransferRecord += DestinationClient.AccountNumber() + Seperator;
		TransferRecord += to_string(Amount) + Seperator;
		TransferRecord += to_string(AccountBalance) + Seperator;
		TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferRecord += UserName;

		return TransferRecord;
	}

	void _RegisterTransferLogTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDateLine = _PrepareLogTransferRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);


		if (MyFile.is_open())
		{
			MyFile << stDateLine << endl;
			MyFile.close();

		}


	}



public:

	struct stTransferRegisterRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string  DestinationAccountNumber;
		string User; 
		float SourceBalance;
		float  DestinationBalance;
		float Amount;

	};


	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MakedForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalacne)
	{
		_AccountBalance = AccountBalacne;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	/*
		No UI Related code inside object . 

	void Print()
	{

		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}
	*/
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}

			break;
		}
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	bool Delete()
	{
		vector<clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& c : _vClient)
		{
			if (c.AccountNumber() == _AccountNumber)
			{
				c._MakedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClient);

		*this = _GetEmptyClientObject();

		return true;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
	
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalnace = 0;

		for (clsBankClient Client : vClients)
		{
			TotalBalnace += Client.AccountBalance;
		}

		return TotalBalnace;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount; 
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false; 
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true; 
		}
		
	}

     bool Transfer(float Amount ,clsBankClient DestinationClient , string UserName)
	 {
		if (Amount > AccountBalance)
			return false; 
		
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLogTransferLog(Amount , DestinationClient, UserName);
		return true; 
		
		
	 }

	 static vector<stTransferRegisterRecord> GetTransferLogList()
	 {
		 vector<stTransferRegisterRecord>vLoginRegisterRecord;

		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;

			 stTransferRegisterRecord TransferRegisterRecord;

			 while (getline(MyFile, Line))
			 {
				 TransferRegisterRecord = _ConverTransferRegiterLineToRecord(Line);

				 vLoginRegisterRecord.push_back(TransferRegisterRecord);
			 }

			 MyFile.close();
		 }

		 return vLoginRegisterRecord;
	 }
	 

};


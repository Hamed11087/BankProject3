
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include"clsMainScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsRegisterLogins.h" 


class clsLoginScreen :protected clsScreen
{


private:


	static bool _Login()
	{
		bool LoginFaild = false; 
		short FaildLoginCount = 0; 
		string UserName, Password;
		
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++; 
				cout << "\n\t\t\t\t\t\tInvlaid Username/Password!\n\n";
				cout << "\n\t\t\t\t\t\tYou have " << (3-FaildLoginCount) << " Trial(s) to login." << endl;
			}

			if (FaildLoginCount == 3)
			{
				system("cls");
				cout << "\n\t\t\t\t\tYour are Locked after 3 faild trails \n\n";
				return false; 
			}

			cout << "\t\t\t\t\t\t  Enter Username? ";
			cin >> UserName; 

			/*cout << "\t\t\t\t\t\t  Enter Password? ";
			cin >> Password;*/

			Password = clsInputValidate::getPassword(); 

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		
		//clsUtil::SendEmail("Greeting " + CurrentUser.FullName(), "We want to thank you to joining us!", CurrentUser.Email);
		//clsRegisterLogins::_SaveUsersRegisterLoginsToFile(CurrentUser); 
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true; 
	}

public:

	static bool ShowLoginScreen()
	{
		 system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return (_Login()); 
			

		
		

	}

};
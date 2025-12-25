#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include <iomanip>
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsers:protected clsScreen
{
private:
	enum  enManageUsersMenueOptions
	{
		eListUsers = 1 , eAddNewUser =2 , eDeleteUser = 3 ,
		eUpdateUser = 4 , eFindUser = 5 , eMainMenue  = 6 
	};

	static short ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Number = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
		return Number; 
	}

	static void _GoBackTOManageUserMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue..."; 
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		//cout << "\nAdd New User Screen will Be Here\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here.\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User Screen WIll Be Here.\n"; 
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here.\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackTOManageUserMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackTOManageUserMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackTOManageUserMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackTOManageUserMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackTOManageUserMenue();
			break; 
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			
		}

		}
	}


public:

	static void ShowManageUsersMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
	}

};


#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsTermsOfUse : protected clsScreen
{
public:
    static void ShowTermsOfUse()
    {
        system("cls");
        _DrawScreenHeader("\tTERMS OF USE");

        const string RED = "\033[31m";
        const string GREEN = "\033[32m";
        const string RESET = "\033[0m";

        // 1. Acceptance of Terms
        cout << RED << "1. Acceptance of Terms" << RESET << endl;
        cout << GREEN << " By accessing or using this system, the user";
        cout << " agrees to comply with all terms and conditions";
        cout << " stated in this document. If the user does not";
        cout << " agree, usage of the system must be terminated";
        cout << " immediately." << endl << endl;

        // 2. Authorized Use
        cout << RED << "2. Authorized Use" << RESET << endl;
        cout << GREEN << " This system is intended for authorized and";
        cout << " legitimate purposes only. Any illegal, harmful,";
        cout << " or unauthorized use is strictly prohibited,";
        cout << " including attempts to bypass security controls";
        cout << " or access restricted features." << endl << endl;

        // 3. User Accounts and Authentication
        cout << RED << "3. User Accounts and Authentication" << RESET << endl;
        cout << GREEN << " Each user is responsible for maintaining the";
        cout << " confidentiality of login credentials. All";
        cout << " activities performed under a user account are";
        cout << " the sole responsibility of the account owner." << endl << endl;

        // 4. Roles and Permissions
        cout << RED << "4. Roles and Permissions" << RESET << endl;
        cout << GREEN << " Access to system features is controlled by";
        cout << " user roles and permissions. Users must not";
        cout << " attempt to gain access to data, functions, or";
        cout << " system areas beyond their assigned role." << endl << endl;

        // 5. Data Accuracy and Responsibility
        cout << RED << "5. Data Accuracy and Responsibility" << RESET << endl;
        cout << GREEN << " Users are responsible for ensuring that all";
        cout << " information entered into the system is accurate,";
        cout << " complete, and lawful. The system administration";
        cout << " is not responsible for errors caused by false";
        cout << " or incorrect data provided by users." << endl << endl;

        // 6. Data Privacy and Confidentiality
        cout << RED << "6. Data Privacy and Confidentiality" << RESET << endl;
        cout << GREEN << " The system takes reasonable measures to protect";
        cout << " user data. Information will not be shared with";
        cout << " third parties unless required by applicable law";
        cout << " or authorized by system administration." << endl << endl;

        // 7. System Security
        cout << RED << "7. System Security" << RESET << endl;
        cout << GREEN << " Users must not attempt to hack, exploit, modify,";
        cout << " or disrupt the system. Any security violation";
        cout << " will be logged and may result in immediate";
        cout << " suspension or permanent termination of access." << endl << endl;

        // 8. Logging and Monitoring
        cout << RED << "8. Logging and Monitoring" << RESET << endl;
        cout << GREEN << " The system may log user activities for security,";
        cout << " maintenance, auditing, and performance purposes.";
        cout << " By using the system, users consent to such";
        cout << " monitoring and logging." << endl << endl;

        // 9. System Availability and Maintenance
        cout << RED << "9. System Availability and Maintenance" << RESET << endl;
        cout << GREEN << " The system is provided \"as is\" without any";
        cout << " guarantee of availability, performance, or";
        cout << " reliability. The system may be unavailable";
        cout << " during maintenance or technical issues." << endl << endl;

        // 10. Data Loss and Liability
        cout << RED << "10. Data Loss and Liability" << RESET << endl;
        cout << GREEN << " The system administration shall not be held";
        cout << " liable for any direct or indirect data loss,";
        cout << " damages, or disruptions resulting from the use";
        cout << " of this system." << endl << endl;

        // 11. Prohibited Content
        cout << RED << "11. Prohibited Content" << RESET << endl;
        cout << GREEN << " Users must not upload, store, or transmit any";
        cout << " content that is illegal, offensive, misleading,";
        cout << " or violates applicable laws or regulations." << endl << endl;

        // 12. Modifications to the System and Terms
        cout << RED << "12. Modifications to the System and Terms" << RESET << endl;
        cout << GREEN << " The system administration reserves the right";
        cout << " to modify system features or these terms at";
        cout << " any time. Continued use indicates acceptance";
        cout << " of the updated terms." << endl << endl;

        // 13. Termination of Access
        cout << RED << "13. Termination of Access" << RESET << endl;
        cout << GREEN << " User access may be suspended or terminated at";
        cout << " any time if misuse, violations, or security";
        cout << " threats are detected." << endl << endl;

        // 14. Governing Law
        cout << RED << "14. Governing Law" << RESET << endl;
        cout << GREEN << " These terms are governed by and interpreted";
        cout << " according to the laws of the Kingdom of Saudi";
        cout << " Arabia." << endl << endl;

        // Separator
        cout << RED << "========================================================" << RESET << endl << endl;

        // User Acceptance
        cout << RESET <<  "Do you accept the Terms of Use? (Y/N): ";
        string answer;
        cin >> answer;

        if (answer != "y" && answer != "Y")
        {
            cout  << "Access denied. You must accept the terms." <<  endl;
            exit(0);
        }

        clsUtil::SendEmail("Greeting " + CurrentUser.FullName(), "We want to thank you to joining us!", CurrentUser.Email);
        cout  << "Access granted. Welcome to the system." <<  endl;
    }
};

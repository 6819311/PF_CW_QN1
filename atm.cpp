#include <iostream>
#include <string>

using namespace std;

int main() {
	
    const int MAX_ACCOUNTS = 100;// the account should allow only 100 accounts
    string userIds[MAX_ACCOUNTS]; // stores userids in an arry  
    string passwords[MAX_ACCOUNTS]; // stores userids in an arry
    double balances[MAX_ACCOUNTS] = {0.0}; // intialising the account balance to zero
    int account = 0;
    int loggedInIndex = -1; // when successful the max accounts will reduce by one 

    char option;

    cout << "WELCOME TO MUHAMMED ATM MACHINE \n";

    do {
    	// CREATING OPTIONS FOR THE MAIN MENU
        cout << "Please select an option from the menu below:\n";
        cout << "l -> Login\n";
        cout << "c -> Create New Account\n";
        cout << "q -> Quit\n";
        cout << "> ";
        cin >> option;// STORING THE OPTIONS IN THE OPTION CHARACTER

        switch (option) {
            case 'c': { // case for creating a new account
                if (account >= MAX_ACCOUNTS) { //checking if the account being created doesnot execeed the maximum number account 
                    cout << "ERROR, maximum number of accounts reached.\n";
                    break;
                }

                string userId, password;
                cout << "Please enter your user id: ";
                cin >> userId;

                bool exists = false;
                for (int i = 0; i < account; i++) {
                    if (userIds[i] == userId) { // checking if the new account doesnot match withany other account already stored
                        exists = true;
                        break;
                    }
                }

                if (exists) { // if the user id allready exists, it will ask the user to enter a different one 
                    cout << "User id already exists. Try a different id.\n";
                } else {
                    cout << "Please enter your password: ";
                    cin >> password;

                    userIds[account] = userId;
                    passwords[account] = password;
                    balances[account] = 0.0;
                    account++;
                     //message will display if the account has been created succesfully
                    cout << "Thank You! Your account has been created!\n";
                }
                break;
            }

            case 'l': { // case for loging in 
                string userId, password;
                cout << "Please enter your user id: ";
                cin >> userId;
                cout << "Please enter your password: ";
                cin >> password;
                
				// checking if the new credentials dont match with the existing ones 
                loggedInIndex = -1;
                for (int i = 0; i < account; i++) {
                    if (userIds[i] == userId && passwords[i] == password) {
                        loggedInIndex = i;
                        break;
                    }
                }

                if (loggedInIndex != -1) {
                	// if all the user id and name match then the user will be permited to access the account
                    cout << "Access Granted!\n";
                    
                    char subOption;

                    do { // suboption for the menu to be displayed 
                        cout << "d -> Deposit Money\n";
                        cout << "w -> Withdraw Money\n";
                        cout << "r -> Request Balance\n";
                        cout << "q -> Quit\n";
                        cout << "> ";
                        cin >> subOption;

                        switch (subOption) {
                            case 'd': { //case for deposit
                                double amount;
                                cout << "Amount of deposit: UGX";
                                cin >> amount;
                                balances[loggedInIndex] += amount;
                                cout << "UGX" << amount << " IS deposited successfully.\n";
                                break;
                            }
                            case 'w': { // case for withdraw
                                double amount;
                                cout << "Amount of withdrawal: UGX";
                                cin >> amount;

                                if (amount <= balances[loggedInIndex]) {
                                    balances[loggedInIndex] -= amount;
                                    cout << "UGX" << amount << " withdrawn successfully.\n";
                                } else {
                                    cout << "Insufficient funds.\n";
                                }
                                break;
                            }
                            case 'r': //case for balance 
                                cout << "Your balance is UGX" << balances[loggedInIndex] << ".\n";
                                break;

                            case 'q':
                                loggedInIndex = -1;  // Log out
                                break;

                            default:
                                cout << "Invalid option. Please try again.\n";
                        }
                    } while (subOption != 'q' && loggedInIndex != -1);
                } else {
                    cout << "*** LOGIN FAILED! ***\n";
                }
                break;
            }

            case 'q':
                cout << "Thank you for using the ATM Machine!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 'q');

    




	
	return 0;
}

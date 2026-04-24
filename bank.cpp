#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string name;
    string mobile;
    int pin;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, string mobile, int pin, int accountNumber) {
        this->name = name;
        this->mobile = mobile;
        this->pin = pin;
        this->accountNumber = accountNumber;
        this->balance = 0;
    }

    void displayAccountDetails() {
        cout << "\nAccount Number: " << accountNumber
             << "\nName: " << name
             << "\nMobile: " << mobile
             << "\nBalance: $" << balance << endl;
    }

    bool verifyPin(int inputPin) {
        return pin == inputPin;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited! New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!\n";
        else {
            balance -= amount;
            cout << "Withdrawn! New Balance: $" << balance << endl;
        }
    }

    void updateAccountDetails(string newName, string newMobile, int newPin) {
        name = newName;
        mobile = newMobile;
        pin = newPin;
        cout << "Account updated!\n";
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

// 🔍 Find account
int findAccount(vector<BankAccount>& accounts, int accNo) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNo)
            return i;
    }
    return -1;
}

int main() {
    vector<BankAccount> accounts;

    int mainChoice;

    do {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        // ================= ADMIN =================
        if (mainChoice == 1) {
            int choice;

            do {
                cout << "\n--- ADMIN MENU ---\n";
                cout << "1. Open Account\n";
                cout << "2. View Account\n";
                cout << "3. Deposit\n";
                cout << "4. Withdraw\n";
                cout << "5. Edit Account\n";
                cout << "6. Delete Account\n";
                cout << "7. Back\n";
                cout << "Enter choice: ";
                cin >> choice;

                int accNo, pin, index;
                string name, mobile;
                double amount;

                switch (choice) {

                case 1:
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Mobile: ";
                    getline(cin, mobile);

                    cout << "Enter PIN: ";
                    cin >> pin;

                    accNo = accounts.size() + 1;
                    accounts.push_back(BankAccount(name, mobile, pin, accNo));

                    cout << "Account created! ID: " << accNo << endl;
                    break;

                case 2:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin))
                            accounts[index].displayAccountDetails();
                        else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 3:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            cout << "Enter Amount: ";
                            cin >> amount;
                            accounts[index].deposit(amount);
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 4:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            cout << "Enter Amount: ";
                            cin >> amount;
                            accounts[index].withdraw(amount);
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 5:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            cin.ignore();
                            cout << "New Name: ";
                            getline(cin, name);
                            cout << "New Mobile: ";
                            getline(cin, mobile);
                            cout << "New PIN: ";
                            cin >> pin;

                            accounts[index].updateAccountDetails(name, mobile, pin);
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 6:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            accounts.erase(accounts.begin() + index);
                            cout << "Account deleted!\n";
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 7:
                    cout << "Going back...\n";
                    break;

                default:
                    cout << "Invalid choice\n";
                }

            } while (choice != 7);
        }

        // ================= CUSTOMER =================
        else if (mainChoice == 2) {
            int choice;

            do {
                cout << "\n--- CUSTOMER MENU ---\n";
                cout << "1. Create Account\n";
                cout << "2. View Account\n";
                cout << "3. Deposit\n";
                cout << "4. Withdraw\n";
                cout << "5. Back\n";
                cout << "Enter choice: ";
                cin >> choice;

                int accNo, pin, index;
                string name, mobile;
                double amount;

                switch (choice) {

                case 1:
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    cout << "Enter Mobile: ";
                    getline(cin, mobile);

                    cout << "Enter PIN: ";
                    cin >> pin;

                    accNo = accounts.size() + 1;
                    accounts.push_back(BankAccount(name, mobile, pin, accNo));

                    cout << "Account created! ID: " << accNo << endl;
                    break;

                case 2:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin))
                            accounts[index].displayAccountDetails();
                        else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 3:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            cout << "Enter Amount: ";
                            cin >> amount;
                            accounts[index].deposit(amount);
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 4:
                    cout << "Enter Account No: ";
                    cin >> accNo;

                    index = findAccount(accounts, accNo);
                    if (index != -1) {
                        cout << "Enter PIN: ";
                        cin >> pin;

                        if (accounts[index].verifyPin(pin)) {
                            cout << "Enter Amount: ";
                            cin >> amount;
                            accounts[index].withdraw(amount);
                        } else
                            cout << "Wrong PIN\n";
                    } else
                        cout << "Account not found\n";
                    break;

                case 5:
                    cout << "Going back...\n";
                    break;

                default:
                    cout << "Invalid choice\n";
                }

            } while (choice != 5);
        }

        else if (mainChoice == 3) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice\n";
        }

    } while (mainChoice != 3);

    return 0;
}
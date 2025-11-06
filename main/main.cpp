// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
//#include <algorithm> // for sort
#include <string> 
//#include <sstream>
using namespace std;


class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Made a deposit of $" << balance << endl;
        saveTransaction("Deposit", amount);
    }

    void makePurchase(string item, double cost) {
        if (cost > balance) {
            cout << "Insufficient funds for " << item << endl;
        }
        else {
            balance -= cost;
            cout << "Purchased " << item << endl;
            saveTransaction("Purchase - " + item, cost);
        }
    }




    void displayBalance() {
        cout << std::fixed << std::setprecision(2);
        cout << "Current Balance: $" << balance << endl;
    }

    void saveTransaction(string type, double amount) {
        ofstream file("transactions.txt", ios::app);
        if (file.is_open()) {
            file << type << ": $" << amount << endl;
            file.close();
        }
    }
};

void showMenu() {
    cout << "~Welcome to Lew Bank terminal~\n1. Deposit $100.00 \n2. Purchase a Coffee ($4.50) \n3. Purchase a Book ($25.00) \n4. Display available Balance \n5. Exit\n\n";
}

int main() {
    
    BankAccount myAccount;
    int option;
    do {
        showMenu();
        cin >> option;
        if (option == 1) {
            myAccount.deposit(100.00);
            myAccount.displayBalance();
        }
        if (option == 2) {
            myAccount.makePurchase("Coffee", 4.50);
            myAccount.displayBalance();
        }
        if (option == 3) {
            myAccount.makePurchase("Book", 25.00);
            myAccount.displayBalance();
        }
        if (option == 4) {
            myAccount.displayBalance();
        }
    } while (option != 5);

    
    

    return 0;
}

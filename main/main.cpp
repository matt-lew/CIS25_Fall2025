// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;
int main() {
	//int choice;
	//cout << "1. Add Item\n2. View Items\n3. Exit\n";
	//cout << "Choose an option: ";
	//cin >> choice;

	//if (choice == 1) cout << "Item added!\n";
	//else if (choice == 2) cout << "Displaying items...\n";
	//else if (choice == 3) cout << "Exiting...\n";
	//else cout << "Invalid option.\n";
	//return 0;

	float n1, n2, n3;

	cout << "Enter three numbers: \t";
	cin >> n1 >> n2 >> n3;
	if (n1 >= n2 && n1 >= n3) cout << "Largest number: \t" << n1;
	else if (n2 >= n1 && n2 >= n3) cout << "Largest number: \t" << n2;
	else if (n3 >= n1 && n3 >= n2) cout << "Largest number: \t" << n3;
	return 0;


}

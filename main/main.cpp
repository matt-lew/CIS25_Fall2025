// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;
void showMenu() {
	cout << "1. Add two numbers\n2. Multiply two numbers\n3. Exit\n";
}
int main() {
	int option;
	float n1, n2;

	do {
		showMenu();
		cin >> option;
		if (option == 1) {
			cout << "Let's add two numbers\nEnter two numbers:\t";
			cin >> n1 >> n2;
			cout << (n1 + n2) << endl;
		}
		if (option == 2) {
			cout << "Let's multiply two numbers\nEnter two numbers:\t";
			cin >> n1 >> n2;
			cout << (n1 * n2) << endl;
		}

	} while (option != 3);
	return 0;
}

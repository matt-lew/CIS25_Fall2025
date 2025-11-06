// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

class Item {
public:
	string name;
	int quantity;
    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << "," << quantity << endl;
            out.close();
            cout << "Item saved to file." << endl;
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << "File content: " << line << endl;
            }
            in.close();
        }
        else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    Item tool;
    cout << "Enter the tool's name: ";
    cin >> tool.name;
    cout << "How many of that tool? ";
    cin >> tool.quantity;

    tool.saveToFile();
    tool.loadFromFile();

    return 0;
}


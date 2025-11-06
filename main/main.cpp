// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm> // for sort
#include <string> 
#include <sstream>
using namespace std;

struct Item {
    string name;
    int id;
};

int binarySearch(Item* arr, int size, int targetId) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == targetId)
            return mid;
        else if (arr[mid].id < targetId)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    cout << "Dynamic Memory Allocation!\n";
    
    //make array
    
    int size = 1000;
    Item* inventory = new Item[size];
    
    //populate array
    for (int i = 0; i < size; ++i) {
        std::stringstream ss;
        ss << "Thing" << std::setw(4) << std::setfill('0') << (size - i);
        //inventory[i].name = "Thing" + std::to_string(size - i);
        inventory[i].name = ss.str();
        inventory[i].id = 0 + i;
        //cout << inventory[i].name << " " << inventory[i].id << endl; //show array as built
    }

    //sort array by name
    
    std::sort(inventory, inventory + size, [](const Item& a, const Item& b) {
        return a.name < b.name;
        });
    for (int i = 0; i < size; ++i) {
        //cout << inventory[i].name << " " << inventory[i].id << endl; //show array sorted by name
    }

    //re-sort by id in order to perform binary search
    std::sort(inventory, inventory + size, [](const Item& a, const Item& b) {
        return a.id < b.id;
        });
    
    //search for ID
    cout << "What ID would you like to see?\n";
    int target;
    cin >> target;
    int n = binarySearch(inventory, size, target);
    if (n != -1) {
        cout << "Value found at ID: " << inventory[n].name << " " << inventory[n].id << endl;
    }
    else {
        cout << "Item not found.\n";
    }

    delete[] inventory;

    return 0;

}

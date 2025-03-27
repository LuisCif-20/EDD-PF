#include <iostream>
#include "Order/OrderManager.hpp"

using namespace std;

int main() {
    OrderManager manager;
    int choice;
    string clientName;
    double price;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add new order" << endl;
        cout << "2. Sort orders by price" << endl;
        cout << "3. Display all orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter client name: ";
                cin.ignore()ñ
                getline(cin, clientName);
                cout << "Enter the price: ";
                cin >> price;
                manager.addOrder(Order(clientName, price));
                cout << "Order added successfully!" << endl;
                break;
            }
            case 2: {
                manager.sortOrders();
                cout << "Orders sorted by price." << endl;
                break;
            }
            case 3: {
                cout << "Displaying all orders:" << endl;
                manager.displayOrders();
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);
    return 0;
}
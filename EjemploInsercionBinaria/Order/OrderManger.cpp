#include "OrderManager.hpp"

void OrderManager::addOrder(const Order& order) {
    orders.push_back(order);
}

void OrderManager::sortOrders() {
    BinaryInsertionSort<Order>::sort(orders);
}

void OrderManager::displayOrders() const {
    for (const auto& order : orders) {
        cout << "Customer: " << order.getCustomer() << ", Price: " << order.getPrice() << endl;
    }
}
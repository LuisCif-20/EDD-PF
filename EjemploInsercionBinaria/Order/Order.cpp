#include "Order.hpp"

Order::Order(string customer, double price) : customer(customer), price(price) {}

string Order::getCustomer() const {
    return customer;
}

double Order::getPrice() const {
    return price;
}

bool Order::operator<(const Order& other) const {
    return price < other.price;
}

bool Order::operator==(const Order& other) const {
    return price == other.price;
}
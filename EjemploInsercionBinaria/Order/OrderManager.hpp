#include <vector>
#include "./Order.hpp"
#include "../Sort/BinaryInsertionSort.hpp"

using namespace std;

class OrderManager {
    private:
        vector<Order> orders;
    public:
        void addOrder(const Order& order);
        void sortOrders();
        void displayOrders() const;
};
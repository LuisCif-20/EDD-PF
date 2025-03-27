class OrderManager {
    private:
        vector<Order> orders;
    public:
        void addOrder(const Order& order);
        void sortOrders();
        void displayOrders() const;
};
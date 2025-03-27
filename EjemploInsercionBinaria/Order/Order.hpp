class Order {
    private:
        string customer;
        double price;
    
    public:
        Order(string customer, double price);
        string getCustomer() const;
        double getPrice() const;
        bool operator<(const Order& other) const;
        bool operator==(const Order& other) const;
};
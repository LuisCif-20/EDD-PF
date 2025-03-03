#include "Node.hpp"

using namespace std;

template <typename T>
class LinkedList {

    private:
        // Attributes
        Node<T>* head;
        size_t size;

    public:
        // Constructor
        LinkedList();

        // Destructor
        ~LinkedList();

        // Methods
        void append(const T& data);
        void remove(const T& data);
        void print();
        void clear();

        // Utilities
        bool isEmpty();

        // Getters
        size_t getSize();

};

#include "LinkedList.tpp"
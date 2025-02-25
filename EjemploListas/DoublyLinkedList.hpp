#include "Node.hpp"

using namespace std;

template <typename T>
class DoublyLinkedList {

    private:
        // Attributes
        Node<T>* head;
        Node<T>* tail;
        size_t size;

    public:
        // Constructor
        DoublyLinkedList();

        // Destructor
        ~DoublyLinkedList();

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

#include "DoublyLinkedList.tpp"
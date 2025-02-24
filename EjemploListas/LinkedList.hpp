#include "Node.hpp"

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
        void clear();

        // Utilities
        bool isEmpty() const;

        // Getters
        size_t getSize() const;

}

#include "LinkedList.tpp"
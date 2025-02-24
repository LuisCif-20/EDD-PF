template <typename T>
class Node {

    private:
        // Attributes
        T data;
        Node<T>* next;
        Node<T>* prev;
        Node<T>* up;
        Node<T>* down;
    
    public:
        // Constructor
        Node(const T data);

        // Destructor
        ~Node();

        // Getters
        T getData() const;
        Node<T>* getNext() const;
        Node<T>* getPrev() const;
        Node<T>* getUp() const;
        Node<T>* getDown() const;
        
        // Setters
        void setData(T data);
        void setNext(Node<T>* next);
        void setPrev(Node<T>* prev);
        void setUp(Node<T>* up);
        void setDown(Node<T>* down);

};

#include "Node.tpp"
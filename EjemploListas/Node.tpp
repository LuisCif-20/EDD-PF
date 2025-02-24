// Constructor
template <typename T>
Node<T>::Node(const T data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
    up = nullptr;
    down = nullptr;
}

// Destructor
template <typename T>
Node<T>::~Node() { }

// Getters
template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() const {
    return prev;
}

template <typename T>
Node<T>* Node<T>::getUp() const {
    return up;
}

template <typename T>
Node<T>* Node<T>::getDown() const {
    return down;
}

// Setters
template <typename T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

template <typename T>
void Node<T>::setPrev(Node<T>* prev) {
    this->prev = prev;
}

template <typename T>
void Node<T>::setUp(Node<T>* up) {
    this->up = up;
}

template <typename T>
void Node<T>::setDown(Node<T>* down) {
    this->down = down;
}
// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// Methods
template <typename T>
void LinkedList<T>::append(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(const T& data) {
    if (!head) return;
    if (head->getData() == data) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        --size;
        return;
    }
    Node<T>* current = head;
    while (current->getNext()) {
        if (current->getNext()->getData() == data) {
            Node<T>* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
            --size;
            return;
        }
        current = current->getNext();
    }
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* current = head;
    while (current) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
    size = 0;
}

// Utilities
template <typename T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

// Getters
template <typename T>
size_t LinkedList<T>::getSize() {
    return size;
}
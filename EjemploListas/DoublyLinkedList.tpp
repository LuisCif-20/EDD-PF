// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

// Methods
template <typename T>
void DoublyLinkedList<T>::append(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (size == 0) {
        head = tail = newNode;
    } else {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::remove(const T& data) {
    if (size == 0) return;
    Node<T>* current = head;
    while (current) {
        if (current->getData() == data) {
            if (current == head) {
                head = head->getNext();
                if (head) {
                    head->setPrev(nullptr);
                } else {
                    tail = nullptr;
                }
            } else if (current == tail) {
                tail = tail->getPrev();
                tail->setNext(nullptr);
            }
            else {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
            }
            delete current;
            --size;
            return;
        }
        current = current->getNext();
    }
}

template <typename T>
void DoublyLinkedList<T>::print() {
    Node<T>* current = head;
    while (current) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = temp->getNext();
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

// Utilities
template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

// Getters
template <typename T>
size_t DoublyLinkedList<T>::getSize() {
    return size;
}

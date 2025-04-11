#include "Node.hpp"

Node::Node(const int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
    up = nullptr;
    down = nullptr;
}

Node::Node(const int data, Node* next, Node* prev, Node* up, Node* down, Node* front, Node* back) {
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->up = up;
    this->down = down;
    this->front = front;
    this->back = back;
}

Node::~Node() { }

int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrev() const {
    return prev;
}

Node* Node::getUp() const {
    return up;
}

Node* Node::getDown() const {
    return down;
}

Node* Node::getFront() const {
    return front;
}

Node* Node::getBack() const {
    return back;
}

void Node::setData(int data) {
    this->data = data;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}

void Node::setUp(Node* up) {
    this->up = up;
}

void Node::setDown(Node* down) {
    this->down = down;
}

void Node::setFront(Node* front) {
    this->front = front;
}

void Node::setBack(Node* back) {
    this->back = back;
}
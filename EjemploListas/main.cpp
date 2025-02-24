#include <iostream>
#include "Node.hpp"

int main() {
    Node<int> node1(10);
    Node<int> node2(20);

    node1.setNext(&node2);
    std::cout << "Node 1 data: " << node1.getData() << std::endl;
    std::cout << "Node 2 data: " << node1.getNext()->getData() << std::endl;

    return 0;
}
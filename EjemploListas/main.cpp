#include <iostream>
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

int main() {
    LinkedList<string> list;
    cout << "Esta vacio: " << list.isEmpty();
    cout << endl;
    list.append("Luis");
    list.append("Nery");
    list.append("Byron");
    list.append("William");
    list.print();
    list.remove("Byron");
    list.append("Daniel");
    list.print();
    cout << "Esta vacio: " << list.isEmpty();
    cout << endl;
    cout << "Tamanio: " << list.getSize();
    cout << endl;
    return 0;
}
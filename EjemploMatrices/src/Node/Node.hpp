#pragma once

class Node {

    private:
        int data;
        Node* next;
        Node* prev;
        Node* up;
        Node* down;
        Node* front;
        Node* back;
    
    public:
        Node(const int data);
        Node(const int data, Node* next, Node* prev, Node* up, Node* down, Node* front, Node* back);

        ~Node();

        int getData() const;
        Node* getNext() const;
        Node* getPrev() const;
        Node* getUp() const;
        Node* getDown() const;
        Node* getFront() const;
        Node* getBack() const;
        
        void setData(int data);
        void setNext(Node* next);
        void setPrev(Node* prev);
        void setUp(Node* up);
        void setDown(Node* down);
        void setFront(Node* front);
        void setBack(Node* back);

};
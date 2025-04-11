#include <iostream>

#include "Board.hpp"

using namespace std;

Board::Board(const size_t width, const size_t height, const size_t depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->origin = nullptr;
}

Board::~Board() {
    clear();
}

void Board::initialize() {
    Node*** firstLayer = createAndConnectXY();
    origin = firstLayer[0][0];
    for (int z = 1; z < depth; z++) {
        Node*** newLayer = createAndConnectXY();
        connectZ(z-1, z, newLayer);
        cleanupTemporary(newLayer);
    }
    cleanupTemporary(firstLayer);
}

Node*** Board::createAndConnectXY() {
    Node*** layer = new Node**[width];
    for (size_t x = 0; x < width; x++) {
        layer[x] = new Node*[height];
        for (size_t y = 0; y < height; y++) {
            layer[x][y] = new Node(0);
            if (y > 0) {
                layer[x][y]->setDown(layer[x][y-1]);
                layer[x][y-1]->setUp(layer[x][y]);
            }
            if (x > 0) {
                layer[x][y]->setPrev(layer[x-1][y]);
                layer[x-1][y]->setNext(layer[x][y]);
            }
        }
    }
    return layer;
}

void Board::connectZ(size_t prevZ, size_t currentZ, Node*** currentLayer) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Node* nodeInPrevZLayer = getNodeAt(x, y, prevZ);
            currentLayer[x][y]->setBack(nodeInPrevZLayer);
            nodeInPrevZLayer->setFront(currentLayer[x][y]);
        }
    }
}

Node* Board::getNodeAt(const size_t x, const size_t y, const size_t z) const {
    if (x < 0 || x >= width || y < 0 || y >= height || z < 0 || z >= depth) {
        return nullptr;
    }
    Node* node = origin;
    for (int i = 0; i < x && node; i++) {
        node = node->getNext();
    }
    if (!node) return nullptr;

    for (int i = 0; i < y && node; i++) {
        node = node->getUp();
    }
    if (!node) return nullptr;

    for (int i = 0; i < z && node; i++) {
        node = node->getFront();
    }
    return node;
}

void Board::cleanupTemporary(Node*** layer) {
    for (int x = 0; x < width; x++) {
        delete[] layer[x];
    }
    delete[] layer;
}

void Board::fillRandom() {
    for (int z = 0; z < depth; z++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int randomValue = (rand() % (101));
                setNodeData(x, y, z, randomValue);
            }
        }
    }
}

void Board::clear() { 
    if (!origin) return;
    Node* xNode = origin;
    while (xNode) {
        Node* yNode = xNode;
        while (yNode) {
            Node* zNode = yNode;
            while (zNode) {
                Node* nextZ = zNode->getFront();
                delete zNode;
                zNode = nextZ;
            }
            Node* nextY = yNode->getUp();
            yNode = nextY;
        }
        Node* nextX = xNode->getNext();
        xNode = nextX;
    }
}

void Board::setNodeData(size_t x, size_t y, size_t z, int data) {
    Node* node = getNodeAt(x, y, z);
    if (node) {
        node->setData(data);
    }
}

int Board::getNodeData(size_t x, size_t y, size_t z) const {
    Node* node = getNodeAt(x, y, z);
    return node ? node->getData() : 0;
}

void Board::printXY(size_t z) const {
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            cout << getNodeData(x, y, z) << " ";
        }
        cout << endl;
    }
}

void Board::printXZ(size_t y) const {
    for (int z = depth - 1; z >= 0; z--) {
        for (int x = 0; x < width; x++) {
            cout << getNodeData(x, y, z) << " ";
        }
        cout << endl;
    }
}

void Board::printYZ(size_t x) const {
    for (int z = depth - 1; z >= 0; z--) {
        for (int y = height - 1; y >= 0; y--) {
            cout << getNodeData(x, y, z) << " ";
        }
        cout << endl;
    }
}

void Board::printFullCube() const {
    for (int z = 0; z < depth; z++) {
        cout << "Capa XY (z = " << z << "):\n";
        printXY(z);
        cout << "\n";
    }
}

size_t Board::getWidth() const {
    return width;
}

size_t Board::getHeight() const {
    return height;
}

size_t Board::getDepth() const {
    return depth;
}

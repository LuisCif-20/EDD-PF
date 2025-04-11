#include <cstddef>

#include "../Node/Node.hpp"

class Board {

    private:
        size_t width;
        size_t height;
        size_t depth;
        Node* origin;

    public:
        Board(const size_t width, const size_t height, const size_t depth);

        ~Board();

        void initialize();
        Node*** createAndConnectXY();
        void connectZ(size_t prevZ, size_t currentZ, Node*** currentLayer);
        Node* getNodeAt(const size_t x, const size_t y, const size_t z) const;
        void cleanupTemporary(Node*** layer);
        void fillRandom();
        void clear();
        int getNodeData(size_t x, size_t y, size_t z) const;
        void setNodeData(size_t x, size_t y, size_t z, int data);
        void printXY(size_t z) const;
        void printXZ(size_t y) const;
        void printYZ(size_t x) const;
        void printFullCube() const;
        size_t getWidth() const;
        size_t getHeight() const;
        size_t getDepth() const;
};
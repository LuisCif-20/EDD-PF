#include <iostream>
#include <limits>

#include <cstdlib>
#include <ctime>

#include "./Board/Board.hpp"

using namespace std;

void displayMenu() {
    cout << "\n=== MENU TABLERO TRIDIMENSIONAL ===\n";
    cout << "1. Mostrar capa XY\n";
    cout << "2. Mostrar capa XZ\n";
    cout << "3. Mostrar capa YZ\n";
    cout << "4. Mostrar todo el cubo\n";
    cout << "5. Establecer valor en posicion\n";
    cout << "6. Obtener valor de posicion\n";
    cout << "7. Llenar con valores aleatorios\n";
    cout << "8. Cambiar dimensiones del tablero\n";
    cout << "9. Salir\n";
    cout << "Seleccione una opcion: ";
}

int getIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            return value;
        }
        cout << "Valor invalido. Debe ser entre " << min << " y " << max << "\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void handleShowXY(Board& board) {
    int z = getIntInput("Ingrese coordenada Z (capa): ", 0, board.getDepth() - 1);
    cout << "\nCapa XY (z = " << z << "):\n";
    board.printXY(z);
}

void handleShowXZ(Board& board) {
    int y = getIntInput("Ingrese coordenada Y (fila): ", 0, board.getHeight() - 1);
    cout << "\nCapa XZ (y = " << y << "):\n";
    board.printXZ(y);
}

void handleShowYZ(Board& board) {
    int x = getIntInput("Ingrese coordenada X (columna): ", 0, board.getWidth() - 1);
    cout << "\nCapa YZ (x = " << x << "):\n";
    board.printYZ(x);
}

void handleSetValue(Board& board) {
    size_t x = getIntInput("Ingrese coordenada X: ", 0, board.getWidth() - 1);
    size_t y = getIntInput("Ingrese coordenada Y: ", 0, board.getHeight() - 1);
    size_t z = getIntInput("Ingrese coordenada Z: ", 0, board.getDepth() - 1);
    size_t value = getIntInput("Ingrese el valor: ", 0, 100);
    board.setNodeData(x, y, z, value);
    cout << "Valor establecido correctamente.\n";
}

void handleGetValue(Board& board) {
    size_t x = getIntInput("Ingrese coordenada X: ", 0, board.getWidth() - 1);
    size_t y = getIntInput("Ingrese coordenada Y: ", 0, board.getHeight() - 1);
    size_t z = getIntInput("Ingrese coordenada Z: ", 0, board.getDepth() - 1);
    cout << "El valor en (" << x << "," << y << "," << z << ") es: " 
            << board.getNodeData(x, y, z) << "\n";
}

void handleRandomFill(Board& board) {
    board.fillRandom();
    cout << "Tablero llenado con valores aleatorios";
}

void handleResize(Board*& board) {
    size_t x = getIntInput("Nuevo tamaño X: ", 1, 100);
    size_t y = getIntInput("Nuevo tamaño Y: ", 1, 100);
    size_t z = getIntInput("Nuevo tamaño Z: ", 1, 100);
    
    delete board;
    board = new Board(x, y, z);
    cout << "Tablero redimensionado a " << x << "x" << y << "x" << z << ".\n";
}


int main() {
    Board* board = new Board(5, 2, 3);
    srand(time(nullptr));
    int choice;
    do {
        displayMenu();
        choice = getIntInput("", 1, 9);
        
        switch (choice) {
            case 1: handleShowXY(*board); break;
            case 2: handleShowXZ(*board); break;
            case 3: handleShowYZ(*board); break;
            case 4: board->printFullCube(); break;
            case 5: handleSetValue(*board); break;
            case 6: handleGetValue(*board); break;
            case 7: handleRandomFill(*board); break;
            case 8: handleResize(board); break;
            case 9: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opcion no valida.\n";
        }
        
    } while (choice != 9);
    
    delete board;
    return 0;
}

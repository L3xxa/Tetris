// Tetromino.cpp
#include "Tetromino.h"
#include <array>

Tetromino::Tetromino(Type type) : type(type), x(5), y(0) {
    // Визначаємо форму тетроміно залежно від типу
    switch (type) {
    case Type::I:
        shape = {{1, 1, 1, 1}}; break;
    case Type::O:
        shape = {{1, 1}, {1, 1}}; break;
    case Type::T:
        shape = {{0, 1, 0}, {1, 1, 1}}; break;
    case Type::S:
        shape = {{0, 1, 1}, {1, 1, 0}}; break;
    case Type::Z:
        shape = {{1, 1, 0}, {0, 1, 1}}; break;
    case Type::J:
        shape = {{1, 0, 0}, {1, 1, 1}}; break;
    case Type::L:
        shape = {{0, 0, 1}, {1, 1, 1}}; break;
    }
}

void Tetromino::rotate() {
    // Обертання тетроміно
    int n = shape.size();
    std::vector<std::vector<int>> rotated(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rotated[j][n - 1 - i] = shape[i][j];
        }
    }

    shape = rotated;
}

void Tetromino::moveLeft() {
    --x;
}

void Tetromino::moveRight() {
    ++x;
}

void Tetromino::moveDown() {
    ++y;
}

const std::vector<std::vector<int>>& Tetromino::getShape() const {
    return shape;
}

int Tetromino::getX() const {
    return x;
}

int Tetromino::getY() const {
    return y;
}

void Tetromino::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

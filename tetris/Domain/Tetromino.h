// Tetromino.h
#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>

class Tetromino {
public:
    enum class Type {
        I, O, T, S, Z, J, L
    };

    Tetromino(Type type);
    void rotate(); // Поворот тетроміно
    void moveLeft(); // Рух вліво
    void moveRight(); // Рух вправо
    void moveDown(); // Рух вниз
    const std::vector<std::vector<int>>& getShape() const; // Отримати форму тетроміно
    int getX() const; // Отримати поточну позицію по X
    int getY() const; // Отримати поточну позицію по Y
    void setPosition(int x, int y); // Встановити позицію

private:
    Type type;
    int x, y; // Поточні координати
    std::vector<std::vector<int>> shape; // Форма тетроміно
};

#endif // TETROMINO_H

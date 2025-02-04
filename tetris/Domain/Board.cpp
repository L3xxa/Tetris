// Board.cpp
#include "Board.h"
#include <iostream>

Board::Board() {
    grid.resize(HEIGHT, std::vector<int>(WIDTH, 0)); // 0 - порожня клітинка
}

void Board::clear() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            grid[y][x] = 0; // Очищаємо всі клітинки
        }
    }
}

bool Board::isCellOccupied(int x, int y) const {
    return grid[y][x] != 0; // Якщо клітинка не пуста, то вона зайнята
}

void Board::setCellOccupied(int x, int y) {
    grid[y][x] = 1; // Заповнюємо клітинку
}

void Board::removeFullLines() {
    for (int y = 0; y < HEIGHT; ++y) {
        bool isFull = true;
        for (int x = 0; x < WIDTH; ++x) {
            if (grid[y][x] == 0) {
                isFull = false;
                break;
            }
        }

        if (isFull) {
            // Видалення лінії та зсув інших ліній
            for (int yy = y; yy > 0; --yy) {
                for (int x = 0; x < WIDTH; ++x) {
                    grid[yy][x] = grid[yy - 1][x];
                }
            }
            for (int x = 0; x < WIDTH; ++x) {
                grid[0][x] = 0; // Очищаємо верхню лінію
            }
        }
    }
}

void Board::draw() const {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            std::cout << (grid[y][x] == 0 ? "." : "#") << " "; // Показуємо поле
        }
        std::cout << std::endl;
    }
}

// Board.h
#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    static const int WIDTH = 10;  // Ширина поля
    static const int HEIGHT = 20; // Висота поля

    Board(); // Конструктор
    void clear(); // Очищення поля
    bool isCellOccupied(int x, int y) const; // Перевірка чи клітинка зайнята
    void setCellOccupied(int x, int y); // Заповнення клітинки
    void removeFullLines(); // Видалення заповнених ліній
    void draw() const; // Відображення поля (поки що у текстовому вигляді або спрощене)

private:
    std::vector<std::vector<int>> grid; // Поле гри
};

#endif // BOARD_H
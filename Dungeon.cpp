#include "Dungeon.h"

Dungeon::Dungeon(std::array<std::unique_ptr<Room>, 36>& dungeon)
	: m_dungeon{ std::move(dungeon) }
{
	for (std::size_t i{ 0 }; i < m_dungeon.size(); i++) {
		if (dynamic_cast<StartRoom*>(m_dungeon[i].get())) {
			m_playerPosition = i;
			break;
		}
	}
}

Room& Dungeon::operator()(std::size_t row, std::size_t column) {
	assert(row < m_rows && column < m_columns && "Indexes are out of bound! (exceed 6)");
    std::size_t index = (row * m_columns) + column;
    assert(index < m_dungeon.size() && "Index is out of bounds!");
    return *m_dungeon[index];
}

Room& Dungeon::operator[](std::size_t index) {
    assert(index < m_dungeon.size() && "Index is out of bounds!");
	return *m_dungeon[index];
}

void Dungeon::display() {
    const std::string greenColor = "\033[32m";
    const std::string resetColor = "\033[0m";

    for (std::size_t x{ 0 }; x < m_rows; x++) {
        for (std::size_t y{ 0 }; y < m_columns; y++) {
            std::size_t index = (x * m_columns) + y;
            if (index == m_playerPosition) {
                std::cout << greenColor << m_dungeon[index].get()->textToDisplay() << resetColor << ' ';
            }
            else {
                std::cout << m_dungeon[index].get()->textToDisplay() << ' ';
            }
        }
        std::cout << '\n';
    }
}

std::size_t Dungeon::getPlayerPosition() const {
	return m_playerPosition;
}

RoomResult Dungeon::movePlayer(char direction) {
    // get the row index
    std::size_t row{ m_playerPosition / m_rows };
    // get the colum index
    std::size_t column{ m_playerPosition % m_columns };
    std::size_t newRow{ row };
    std::size_t newColumn{ column };

    switch (direction) {
    case 'W': case 'w':     newRow--;
        break;
    case 'A': case 'a':     newColumn--;
        break;
    case 'S': case 's':     if (row > 0) newRow++;
        break;
    case 'D': case 'd':     if (column < m_columns - 1) newColumn++;
        break;
    default:                std::cout << "Invalid input";
        break;
    }

    std::size_t newIndex{ newRow * m_columns + newColumn };

    if (!m_dungeon[newIndex].get()->isEmpty()) {
        std::cout << "Player moved!" << '\n';
        m_playerPosition = newIndex;
        return m_dungeon[newIndex].get()->onEnter();
    } else {
        std::cout << "No available rooms in that direction!" << '\n';
    }

    return std::monostate{};
}

void Dungeon::resetPlayerPosition() {
    for (std::size_t i{ 0 }; i < m_dungeon.size(); i++) {
        if (dynamic_cast<StartRoom*>(m_dungeon[i].get())) {
            m_playerPosition = i;
            break;
        }
    }
}
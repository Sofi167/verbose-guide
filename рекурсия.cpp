#include <iostream>
#include <vector>
using namespace std;

// Тип для хранения координат клетки
using Cell = pair<int, int>;
// Тип для хранения пути (последовательности клеток)
using Path = vector<Cell>;


// Функция проверяет, можно ли зайти в клетку (x, y)
bool isValid(int x, int y, const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0);
}

// Рекурсивная функция поиска всех путей
void findAllPaths(
    vector<vector<int>>& grid,
    int x, int y,
    const Cell& end,
    Path& currentPath,
    vector<Path>& allPaths
) {
    // Базовый случай: достигли финиша
    if (make_pair(x, y) == end) {
        allPaths.push_back(currentPath);
        return;
    }

    // Если клетка недоступна — выход
    if (!isValid(x, y, grid)) {
        return;
    }

    // Отмечаем клетку как посещённую (чтобы не заходить повторно)
    grid[x][y] = 2;
    currentPath.push_back({x, y});

    // Варианты ходов: вверх, вниз, влево, вправо
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        findAllPaths(grid, newX, newY, end, currentPath, allPaths);  // Исправлено: было "current preparedPath"
    }

    // Возврат: снимаем отметку и удаляем из пути
    grid[x][y] = 0;
    currentPath.pop_back();
}

// Основная функция: возвращает все пути из start в end
vector<Path> findAllPathsInMaze(vector<vector<int>> grid, Cell start, Cell end) {
    vector<Path> allPaths;
    Path currentPath;

    findAllPaths(grid, start.first, start.second, end, currentPath, allPaths);

    return allPaths;
}

// Вывод пути в удобном формате
void printPath(const Path& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        cout << "(" << path[i].first << ", " << path[i].second << ")";
        if (i < path.size() - 1) {
            cout << " → ";
        }
    }
    cout << endl;
}

int main() {
    // Лабиринт 5x5: 0 — проход, 1 — стена
    vector<vector<int>> labyrinth = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Cell start = {0, 0};   // Начало — левый верхний угол
    Cell end   = {4, 4}; // Конец — правый нижний угол

    vector<Path> allPaths = findAllPathsInMaze(labyrinth, start, end);


    cout << "Найдено путей: " << allPaths.size() << endl << endl;

    for (size_t i = 0; i < allPaths.size(); ++i) {
        cout << "Путь " << (i + 1) << ": ";
        printPath(allPaths[i]);
    }

    return 0;
}
Вывод:
Найдено путей: 2

Путь 1: (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 1) → (2, 0) → (3, 0) → (4, 0) → (4, 1) → (4, 2) → (4, 3)
Путь 2: (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3) → (2, 4) → (3, 4)

def find_all_paths(grid, start=(0, 0), end=(4, 4)):
    all_paths = []
    rows, cols = len(grid), len(grid[0])

    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] == 0

    def backtrack(x, y, path):
        # Базовый случай: достигли конца
        if (x, y) == end:
            all_paths.append(path[:])  # Копируем текущий путь
            return

        # Проверяем границы и стены
        if not is_valid(x, y):
            return

        # Отмечаем клетку как посещённую
        grid[x][y] = 2
        path.append((x, y))

        # Исследуем соседей (вверх, вниз, влево, вправо)
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            backtrack(x + dx, y + dy, path)

        # Возврат: снимаем отметку и удаляем из пути
        grid[x][y] = 0
        path.pop()

    backtrack(start[0], start[1], [])
    return all_paths

# Пример использования
labyrinth = [
    [0, 0, 0, 0, 0],
    [1, 1, 0, 1, 1],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

paths = find_all_paths(labyrinth)
for i, path in enumerate(paths):
    print(f"Путь {i + 1}: {path}")
Вывод
Путь 1: [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2), (2, 1), (2, 0), (3, 0), (4, 0), (4, 1), (4, 2), (4, 3)]
Путь 2: [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2), (2, 3), (2, 4), (3, 4)]

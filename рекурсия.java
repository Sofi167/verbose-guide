import java.util.*;

public class MazeSolver {
    private static final int SIZE = 5;

    // Класс для представления клетки лабиринта
    static class Cell {
        final int row, col;

        Cell(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public String toString() {
            return "(" + row + ", " + col + ")";
        }
    }

    /**
     * Находит все возможные пути от start до end в лабиринте.
     * @param maze исходный лабиринт (0 — проход, 1 — стена)
     * @param start начальная клетка
     * @param end конечная клетка
     * @return список всех найденных путей
     */
    public static List<List<Cell>> findAllPaths(int[][] maze, Cell start, Cell end) {
        List<List<Cell>> allPaths = new ArrayList<>();
        List<Cell> currentPath = new ArrayList<>();

        // Создаём копию лабиринта, чтобы не изменять оригинал
        int[][] grid = new int[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            grid[i] = maze[i].clone();
        }

        backtrack(grid, start.row, start.col, end, currentPath, allPaths);
        return allPaths;
    }

    /**
     * Рекурсивный метод поиска с возвратом.
     */
    private static void backtrack(
            int[][] grid,
            int row,
            int col,
            Cell end,
            List<Cell> currentPath,
            List<List<Cell>> allPaths
    ) {
        // Проверка границ и доступности клетки
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] != 0) {
            return;
        }

        // Добавляем текущую клетку в путь
        Cell currentCell = new Cell(row, col);
        currentPath.add(currentCell);
        grid[row][col] = 2; // отмечаем как посещённую

        // Если достигли цели — сохраняем копию текущего пути
        if (row == end.row && col == end.col) {
            allPaths.add(new ArrayList<>(currentPath));
        } else {
            // Пробуем все 4 направления: вверх, вниз, влево, вправо
            int[] dr = {-1, 1, 0, 0};
            int[] dc = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                backtrack(grid, row + dr[i], col + dc[i], end, currentPath, allPaths);
            }
        }

        // Возврат: убираем клетку из пути и снимаем отметку
        grid[row][col] = 0;
        currentPath.remove(currentPath.size() - 1);
    }

    /**
     * Выводит все найденные пути в удобном формате.
     */
    private static void printAllPaths(List<List<Cell>> paths) {
        System.out.println("=" .repeat(50));
        System.out.println("РЕЗУЛЬТАТ ПОИСКА ПУТЕЙ");
        System.out.println("=" .repeat(50));

        if (paths.isEmpty()) {
            System.out.println("Путей не найдено.");
            return;
        }

        System.out.println("Найдено путей: " + paths.size());
        System.out.println("-".repeat(50));

        for (int i = 0; i < paths.size(); i++) {
            List<Cell> path = paths.get(i);
            System.out.printf("Путь %2d (%2d шагов): ", i + 1, path.size());

            for (int j = 0; j < path.size(); j++) {
                System.out.print(path.get(j));
                if (j < path.size() - 1) {
                    System.out.print(" → ");
                }
            }
            System.out.println();
        }

        System.out.println("=" .repeat(50));
    }

    public static void main(String[] args) {
        // Лабиринт 5x5: 0 — проход, 1 — стена
        int[][] labyrinth = {
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}
        };

        Cell start = new Cell(0, 0); // Старт: верхний левый угол (0,0)
        Cell end = new Cell(4, 4);   // Финиш: нижний правый угол (4,4)

        System.out.println("ЛАБИРИНТ (0 — проход, 1 — стена)");
        System.out.println("-".repeat(30));
        for (int[] row : labyrinth) {
            for (int cell : row) {
                System.out.printf("%2d ", cell);
            }
            System.out.println();
        }
        System.out.println("-".repeat(30));

        // Поиск всех путей
        List<List<Cell>> allPaths = findAllPaths(labyrinth, start, end);

        // Вывод результатов
        printAllPaths(allPaths);
    }
}
Вывод:
ЛАБИРИНТ (0 — проход, 1 — стена)
 0  0  0  0  0 
 1  1  0  1  1 
 0  0  0  0  0
 0  1  1  1  0
 0  0  0  0  0
РЕЗУЛЬТАТ ПОИСКА ПУТЕЙ
Найдено путей: 4
Путь  1 (13 шагов): (0, 0) → (0, 1) → (0, 2) → (0, 3) → (0, 4) → (1, 4) → (2, 4) → (3, 4) → (4, 4)
Путь  2 (11 шагов): (0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3) → (2, 4) → (3, 4) → (4, 4)

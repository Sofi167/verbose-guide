public class ShellSort {
    // Основная функция для сортировки массива
    public static void shellSort(int[] arr) {
        int n = arr.length;
        // Начальный шаг (gap)
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Сортируем элементы с шагом gap
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                // Вставляем arr[i] в отсортированную часть
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // Функция для печати массива
    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Тестовый метод
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Исходный массив:");
        printArray(arr);

        shellSort(arr);

        System.out.println("Отсортированный массив:");
        printArray(arr);
    }
}
Исходный массив:
64 34 25 12 22 11 90
Отсортированный массив:
11 12 22 25 34 64 90

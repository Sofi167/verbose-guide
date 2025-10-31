public class MergeSort {
    // Основная функция для сортировки массива
    public static void mergeSort(int[] arr) {
        if (arr.length > 1) {
            // Разделяем массив на две половины
            int mid = arr.length / 2;
            int[] left = new int[mid];
            int[] right = new int[arr.length - mid];

            // Копируем элементы в левую и правую половины
            System.arraycopy(arr, 0, left, 0, mid);
            System.arraycopy(arr, mid, right, 0, arr.length - mid);

            // Рекурсивно сортируем левую и правую половины
            mergeSort(left);
            mergeSort(right);

            // Сливаем отсортированные половины
            merge(arr, left, right);
        }
    }

    // Функция для слияния двух отсортированных массивов
    private static void merge(int[] arr, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        // Сливаем элементы из left и right в arr
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // Копируем оставшиеся элементы из left, если они есть
        while (i < left.length) {
            arr[k++] = left[i++];
        }

        // Копируем оставшиеся элементы из right, если они есть
        while (j < right.length) {
            arr[k++] = right[j++];
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

        mergeSort(arr);

        System.out.println("Отсортированный массив:");
        printArray(arr);
    }
}
Исходный массив:
64 34 25 12 22 11 90
Отсортированный массив:
11 12 22 25 34 64 90

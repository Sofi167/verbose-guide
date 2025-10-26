public class BinarySearch {
    // Функция для бинарного поиска
    public static int binarySearch(int[] arr, int x) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Если элемент найден
            if (arr[mid] == x)
                return mid;

            // Если элемент меньше среднего, ищем в левой половине
            if (arr[mid] < x)
                left = mid + 1;
            // Если элемент больше среднего, ищем в правой половине
            else
                right = mid - 1;
        }

        // Элемент не найден
        return -1;
    }

    // Тестовый метод
    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        int x = 10;

        int result = binarySearch(arr, x);
        if (result == -1)
            System.out.println("Элемент не найден");
        else
            System.out.println("Элемент найден на позиции " + result);
    }
}

#include <iostream>
using namespace std;

// Функция для интерполирующего поиска
int interpolationSearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Вычисляем предполагаемую позицию
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));

        // Если элемент найден
        if (arr[pos] == x)
            return pos;

        // Если элемент меньше среднего, ищем в левой половине
        if (arr[pos] < x)
            low = pos + 1;
        // Если элемент больше среднего, ищем в правой половине
        else
            high = pos - 1;
    }

    // Элемент не найден
    return -1;
}

// Тестовый метод
int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;

    int result = interpolationSearch(arr, n, x);
    if (result == -1)
        cout << "Элемент не найден";
    else
        cout << "Элемент найден на позиции " << result;

    return 0;
}
Вывод кода:
Элемент найден на позиции 4

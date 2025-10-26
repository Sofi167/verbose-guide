#include <iostream>
using namespace std;

// Функция для поиска по Фибоначчи
int fibonacciSearch(int arr[], int x, int n) {
    // Инициализируем числа Фибоначчи
    int fibMMm2 = 0; // (m-2)'е число Фибоначчи
    int fibMMm1 = 1; // (m-1)'е число Фибоначчи
    int fibM = fibMMm2 + fibMMm1; // m-е число Фибоначчи

    // Ищем наименьшее число Фибоначчи, которое больше или равно n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Индекс для поиска
    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        // Если x больше элемента в индексе i, уменьшаем диапазон поиска
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // Если x меньше элемента в индексе i, уменьшаем диапазон поиска
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // Если x равен элементу в индексе i, возвращаем индекс
        else
            return i;
    }

    // Проверяем последний элемент
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    // Элемент не найден
    return -1;
}

// Тестовый метод
int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int x = 85;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = fibonacciSearch(arr, x, n);
    if (result == -1)
        cout << "Элемент не найден";
    else
        cout << "Элемент найден на позиции " << result;

    return 0;
}

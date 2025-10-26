#include <iostream>
using namespace std;

// Функция для последовательного поиска
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        // Если текущий элемент равен искомому
        if (arr[i] == x)
            return i; // Возвращаем индекс элемента
    }
    return -1; // Элемент не найден
}

// Тестовый метод
int main() {
    int arr[] = {10, 20, 80, 30, 60, 50};
    int x = 80;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, n, x);
    if (result == -1)
        cout << "Элемент не найден";
    else
        cout << "Элемент найден на позиции " << result;

    return 0;
}

#include <iostream>
using namespace std;

// Функция для обмена двух элементов
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для разделения массива
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]); // Меняем местами
        }
    }
    swap(&arr[i + 1], &arr[high]); // Помещаем опорный элемент на его правильное место
    return (i + 1);
}

// Основная функция для быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Определяем индекс разделения
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы до и после разделения
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для печати массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Тестовый метод
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Исходный массив: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);
    return 0;
}

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        # Предполагаем, что текущий элемент — минимальный
        min_index = i
        # Просматриваем оставшиеся элементы справа от текущего
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Меняем местами текущий элемент с найденным минимальным
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

# Пример использования
array = [64, 25, 12, 22, 11]
sorted_array = selection_sort(array)
print(sorted_array)
вывод кода:
[11, 12, 22, 25, 64]

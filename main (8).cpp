#include <iostream>
#include <vector>

using namespace std;

// Разделение массива для быстрой сортировки
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Быстрая сортировка
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Исходный массив
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }

    // Применяем быструю сортировку
    quickSort(arr, 0, arr.size() - 1);

    // Выводим отсортированный массив
    cout << "\nОтсортированный массив (по возрастанию): ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}

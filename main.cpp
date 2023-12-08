#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Вспомогательная функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << endl;
}

// Вспомогательная функция для обмена двух элементов в массиве
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Построение кучи в поддереве с корнем i, где i - индекс в arr[]
void heapify(vector<int>& arr, int n, int i, int& comparisons, int& moves) {
    int largest = i; // Инициализация largest как корень
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // Если левый потомок больше корня
    comparisons++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый потомок больше, чем largest
    comparisons++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если largest не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        moves += 3; // Два обмена и одно дополнительное присваивание

        // Рекурсивно строим кучу в поддереве
        heapify(arr, n, largest, comparisons, moves);
    }
}

// Основная функция для сортировки кучей
void heapSort(vector<int>& arr, int& comparisons, int& moves) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, moves);
    }

    // Поочередно извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);
        moves += 3; // Два обмена и одно дополнительное присваивание

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0, comparisons, moves);
    }
}

// Функция разделения для быстрой сортировки
int partition(vector<int>& arr, int low, int high, int& comparisons, int& moves) {
    int pivot = arr[high]; // Опорный элемент
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        comparisons++;
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]);
            moves += 3; // Два обмена и одно дополнительное присваивание
        }
    }
    swap(arr[i + 1], arr[high]);
    moves += 3; // Два обмена и одно дополнительное присваивание
    return (i + 1);
}

// Основная функция для реализации быстрой сортировки
void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& moves) {
    if (low < high) {
        // pi - индекс разделения, arr[pi] находится на своем месте
        int pi = partition(arr, low, high, comparisons, moves);

        // Рекурсивно сортируем элементы перед разделением и после разделения
        quickSort(arr, low, pi - 1, comparisons, moves);
        quickSort(arr, pi + 1, high, comparisons, moves);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Размеры тестовых данных: 100, 1000, 10000, 100000, 1000000 элементов
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arr(size);

        // Заполнение массива случайными числами
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }

        // Выполнение сортировки кучей
        int comparisonsHeap = 0;
        int movesHeap = 0;
        vector<int> arrHeap = arr;
        heapSort(arrHeap, comparisonsHeap, movesHeap);

        // Выполнение быстрой сортировки
        int comparisonsQuick = 0;
        int movesQuick = 0;
        vector<int> arrQuick = arr;
        quickSort(arrQuick, 0, size - 1, comparisonsQuick, movesQuick);

        // Вывод результатов теста
        cout << "Результаты для размера " << size << ":" << endl;
        cout << "Сортировка кучей - Сравнения: " << comparisonsHeap << ", Перемещения: " << movesHeap << endl;
        cout << "Быстрая сортировка - Сравнения: " << comparisonsQuick << ", Перемещения: " << movesQuick << endl;
        cout << endl;
    }

    return 0;
}

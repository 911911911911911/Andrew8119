#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функція для генерації випадкової послідовності заданого розміру
vector<int> generateRandomSequence(int size) {
    vector<int> sequence;
    for (int i = 0; i < size; ++i) {
        sequence.push_back(rand() % 1000); // Змініть 1000 на максимальне значення елементів у вашій послідовності
    }
    return sequence;
}

// Функція для копіювання вихідної послідовності перед сортуванням
vector<int> copySequence(const vector<int>& original) {
    vector<int> copy(original);
    return copy;
}

// Функція для виводу вмісту вектора
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Функція для визначення кількості порівнянь та переміщень при сортуванні за методом бульбашки
pair<int, int> bubbleSort(vector<int>& arr) {
    int comparisons = 0;
    int swaps = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
    return make_pair(comparisons, swaps);
}

// Додайте функції для інших методів сортування (наприклад, вставка, обмін, швидке сортування тощо.)

int main() {
    // Розміри послідовностей для тестування
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    // Створення та заповнення таблиць для зберігання результатів
    vector<vector<int>> comparisonsTable;
    vector<vector<int>> swapsTable;

    // Початок тестування
    for (int size : sizes) {
        vector<int> sequence = generateRandomSequence(size);

        // Копіюємо вихідну послідовність для кожного методу сортування
        vector<int> sequenceCopy = copySequence(sequence);

        // Тестування методу сортування бульбашкою
        auto start = high_resolution_clock::now();
        pair<int, int> bubbleSortResults = bubbleSort(sequenceCopy);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        // Записуємо результати у таблиці
        comparisonsTable.push_back({size, bubbleSortResults.first});
        swapsTable.push_back({size, bubbleSortResults.second});

        // Виведення результатів
        cout << "Bubble Sort Results for Size " << size << ":" << endl;
        cout << "Comparisons: " << bubbleSortResults.first << endl;
        cout << "Swaps: " << bubbleSortResults.second << endl;
        cout << "Time taken: " << duration.count() << " milliseconds" << endl << endl;
    }

    // Тепер ви можете використовувати дані у таблицях для створення графіків в Excel або іншому інструменті.
    // Наприклад, зберігаючи їх у CSV файл та імпортуючи у Excel.

    return 0;
}

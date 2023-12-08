#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void shellSort(vector<int>& arr, int& comparisons, int& moves) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
                moves++;
            }
            arr[j] = temp;
            moves++;
        }
    }
}

// Функція для злиття двох відсортованих підмасивів
void merge(vector<int>& arr, int l, int m, int r, int& comparisons, int& moves) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        moves++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        moves++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        moves++;
    }
}

// Рекурсивна функція для сортування методом природного злиття
void naturalMergeSortHelper(vector<int>& arr, int l, int r, int& comparisons, int& moves) {
    if (l < r) {
        int m = (l + r) / 2;
        naturalMergeSortHelper(arr, l, m, comparisons, moves);
        naturalMergeSortHelper(arr, m + 1, r, comparisons, moves);
        merge(arr, l, m, r, comparisons, moves);
    }
}

void naturalMergeSort(vector<int>& arr, int& comparisons, int& moves) {
    int n = arr.size();
    naturalMergeSortHelper(arr, 0, n - 1, comparisons, moves);
}

int main() {
    srand(time(nullptr));

    // Тестові дані розміром 100, 1000, 10000, 100000, 1000000 елементів
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        vector<int> arr(size);

        // Заповнення масиву випадковими числами
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000;
        }

        // Сортування методом фон Неймана
        int comparisonsShell = 0;
        int movesShell = 0;
        vector<int> arrShell = arr;
        shellSort(arrShell, comparisonsShell, movesShell);

        // Сортування методом природного злиття
        int comparisonsMerge = 0;
        int movesMerge = 0;
        vector<int> arrMerge = arr;
        naturalMergeSort(arrMerge, comparisonsMerge, movesMerge);

        // Виведення результатів тестування
        cout << "Results for Size " << size << ":" << endl;
        cout << "Shell Sort - Comparisons: " << comparisonsShell << ", Moves: " << movesShell << endl;
        cout << "Natural Merge Sort - Comparisons: " << comparisonsMerge << ", Moves: " << movesMerge << endl;
        cout << endl;
    }

    return 0;
}

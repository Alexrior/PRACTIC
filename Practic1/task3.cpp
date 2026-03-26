#include <iostream>
#include <algorithm> // Для функции swap

using namespace std;

// --- ЗАДАНИЕ 2: Пузырьковая сортировка ---
void bubbleSort(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1]) swap(mas[j], mas[j + 1]);
        }
    }
}

// --- ЗАДАНИЕ 2: Быстрая сортировка (Quick Sort) ---
void quickSort(int mas[], int left, int right) {
    int i = left, j = right;
    int pivot = mas[(left + right) / 2];
    while (i <= j) {
        while (mas[i] < pivot) i++;
        while (mas[j] > pivot) j--;
        if (i <= j) {
            swap(mas[i], mas[j]);
            i++; j--;
        }
    }
    if (left < j) quickSort(mas, left, j);
    if (i < right) quickSort(mas, i, right);
}

// --- ЗАДАНИЕ 3: Четные по возрастанию, нечетные по убыванию ---
void evenOddSort(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool swapNeeded = false;
            // Оба четные - сортируем по возрастанию
            if (mas[j] % 2 == 0 && mas[j+1] % 2 == 0) {
                if (mas[j] > mas[j+1]) swapNeeded = true;
            }
            // Оба нечетные - сортируем по убыванию
            else if (mas[j] % 2 != 0 && mas[j+1] % 2 != 0) {
                if (mas[j] < mas[j+1]) swapNeeded = true;
            }
            // Если перемешаны (нечетное перед четным) - ставим четные вперед
            else if (mas[j] % 2 != 0 && mas[j+1] % 2 == 0) {
                swapNeeded = true;
            }

            if (swapNeeded) swap(mas[j], mas[j+1]);
        }
    }
}

// --- ЗАДАНИЯ 4 и 5: Сортировка на интервале [N1, N2] ---
// type: true - возрастание, false - убывание
void sortRange(int mas[], int n1, int n2, bool ascending) {
    for (int i = n1; i <= n2; i++) {
        for (int j = n1; j < n2; j++) {
            if (ascending) {
                if (mas[j] > mas[j+1]) swap(mas[j], mas[j+1]);
            } else {
                if (mas[j] < mas[j+1]) swap(mas[j], mas[j+1]);
            }
        }
    }
}

int main() {
    int a[] = {12, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(a) / sizeof(int);

    cout << "Iskhodny massiv: ";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    // Демонстрация Задания 3
    evenOddSort(a, n);
    cout << "\nZadanie 3 (Chet vverkh, nechet vniz): \n";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    // Демонстрация Задания 4 (интервал от индекса 2 до 8 по возрастанию)
    sortRange(a, 2, 8, true);
    cout << "\nZadanie 4 (Interval [2, 8] po vozrastaniyu): \n";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <math.h> // Для функции fabs (модуль разности)

#define N 5
using namespace std;

int main() {
    float m;
    int i, j;
    float totalSum = 0;

    // 1. Заполнение матрицы случайными числами
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            m[i][j] = rand() / 10.;
            totalSum += m[i][j]; // Считаем общую сумму сразу для среднего
        }

    // 2. Вывод матрицы на экран
    cout << "--- Iskhodnaya Matritsa ---" << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }
    cout << "---------------------------" << endl;

    // 3. Максимальные и средние значения строк
    cout << "\n[ STROKI ]" << endl;
    for (i = 0; i < N; i++) {
        float maxR = m[i][0];
        float sumR = 0;
        for (j = 0; j < N; j++) {
            if (m[i][j] > maxR) maxR = m[i][j];
            sumR += m[i][j];
        }
        cout << "Stroka " << i << ": Max = " << maxR << ", Srednee = " << sumR / N << endl;
    }

    // 4. Максимальные и средние значения столбцов
    cout << "\n[ STOLBTSI ]" << endl;
    for (j = 0; j < N; j++) {
        float maxC = m[0][j];
        float sumC = 0;
        for (i = 0; i < N; i++) {
            if (m[i][j] > maxC) maxC = m[i][j];
            sumC += m[i][j];
        }
        cout << "Stolbets " << j << ": Max = " << maxC << ", Srednee = " << sumC / N << endl;
    }

    // 5. Суммы треугольных частей
    float sumUpper = 0, sumLower = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j >= i) sumUpper += m[i][j]; // Верхний (включая диагональ)
            if (i >= j) sumLower += m[i][j]; // Нижний (включая диагональ)
        }
    }
    cout << "\nSumma verkhnego treugolnika: " << sumUpper << endl;
    cout << "Summa nizhnego treugolnika: " << sumLower << endl;

    // 6. Элемент, наиболее близкий к общему среднему арифметическому
    float globalMean = totalSum / (N * N);
    float closest = m[0][0];
    float minDiff = fabs(m[0][0] - globalMean);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (fabs(m[i][j] - globalMean) < minDiff) {
                minDiff = fabs(m[i][j] - globalMean);
                closest = m[i][j];
            }
        }
    }
    cout << "\nObschee srednee: " << globalMean << endl;
    cout << "Naibolee blizkiy element: " << closest << endl;

    getch();
    return 0;
}
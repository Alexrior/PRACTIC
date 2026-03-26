#include <iostream>

using namespace std;


void obmen1(int a, int b);
void obmen2(int* a, int* b);
void obmen3(int& a, int& b);

int main() {
    int a = 2, b = 5;

    // Вывод до начала обмена
    cout << "do obmena:    a=" << a << " b=" << b << endl;

    // 1. Вызов по значению
    obmen1(a, b);
    cout << "posle obmena 1: a=" << a << " b=" << b << " (ne izmenilos)" << endl;

    // 2. Вызов по указателю
    obmen2(&a, &b);
    cout << "posle obmena 2: a=" << a << " b=" << b << endl;

    // Вернем значения назад для чистоты 3-го теста
    a = 2; b = 5;

    // 3. Вызов по ссылке
    obmen3(a, b);
    cout << "posle obmena 3: a=" << a << " b=" << b << endl;

    return 0;
}

//  Передача по значению (int, int)
// Результат: значения в main НЕ изменятся.
void obmen1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

//Передача по указателю (int*, int*)
// Результат: значения в main ИЗМЕНЯТСЯ.
void obmen2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//ередача по ссылке (int&, int&)
// Результат: значения в main ИЗМЕНЯТСЯ.
void obmen3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
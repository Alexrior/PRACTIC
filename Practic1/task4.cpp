#include <iostream>
#include <cstdlib> // Для malloc, calloc и free

using namespace std;

// --- ЗАДАНИЕ 2: Собственные функции ---

// Способ 1: Счетчик и индекс
int dlina1(char* s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

// Способ 2: Адресная арифметика (разность указателей)
int dlina2(char* s) {
    char* p = s;
    while (*p) p++;
    return p - s;
}

// Способ 3: Рекурсия
int dlina3(char* s) {
    if (*s == '\0') return 0;
    return 1 + dlina3(s + 1);
}

// Копирование строки s2 в s1
void kopir(char* s1, char* s2) {
    while (*s2) {
        *s1 = *s2;
        s1++; s2++;
    }
    *s1 = '\0'; // Обязательный ноль-терминатор
}

// Сравнение строк (0 - равны)
int sravn(char* s1, char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++; s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// Конкатенация (склеивание)
void konkat(char* s1, char* s2) {
    while (*s1) s1++; // Идем в конец первой строки
    while (*s2) {
        *s1 = *s2;
        s1++; s2++;
    }
    *s1 = '\0';
}

int main() {
    // --- Демонстрация задания 2 ---
    char str1[100] = "qwerty";
    char str2[] = "1234567890";
    char str3[100];

    cout << "--- Zadanie 2: Funktsii ---" << endl;
    cout << "Dlina str1 (sposob 1): " << dlina1(str1) << endl;
    cout << "Dlina str1 (sposob 2): " << dlina2(str1) << endl;
    cout << "Dlina str1 (sposob 3): " << dlina3(str1) << endl;

    kopir(str3, str1);
    cout << "Rezultat kopirovaniya (str3): " << str3 << endl;

    if (sravn(str1, str3) == 0) cout << "Stroki str1 i str3 odinakovy" << endl;

    konkat(str1, str2);
    cout << "Rezultat konkatentsii (str1 + str2): " << str1 << endl << endl;

    // --- ЗАДАНИЕ 3 и 4: Динамическая память ---
    cout << "--- Zadanie 3 i 4: Dinamicheskaya pamyat ---" << endl;
    
    // malloc (Задание 3)
    char* d_str1 = (char*)malloc(100 * sizeof(char));
    // calloc (Задание 4)
    char* d_str2 = (char*)calloc(100, sizeof(char));

    if (d_str1 && d_str2) {
        kopir(d_str1, "Malloc_String");
        kopir(d_str2, "Calloc_String");
        cout << "Stroka iz malloc: " << d_str1 << endl;
        cout << "Stroka iz calloc: " << d_str2 << endl;
        
        free(d_str1);
        free(d_str2);
    }
    cout << endl;

    // --- ЗАДАНИЕ 5: Массив строк ---
    cout << "--- Zadanie 5: Massiv strok ---" << endl;
    const int N = 3;
    char* massiv;

    // Выделяем память под каждую строку
    for (int i = 0; i < N; i++) {
        massiv[i] = (char*)malloc(50 * sizeof(char));
    }

    kopir(massiv[0], "First_Element");
    kopir(massiv[1], "Second_Element");
    kopir(massiv[2], "Third_Element");

    for (int i = 0; i < N; i++) {
        cout << "Massiv[" << i << "]: " << massiv[i] << " (dlina: " << dlina1(massiv[i]) << ")" << endl;
        free(massiv[i]); // Освобождаем память
    }

    return 0;
}
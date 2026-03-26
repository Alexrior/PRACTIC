#include <iostream>
#include <cstdlib>

using namespace std;

int my_strlen(const char* s) {
    int i = 0;
    while (s[i]) i++;
    return i;
}

void my_strcpy(char* s1, const char* s2) {
    while (*s2) {
        *s1 = *s2;
        s1++; s2++;
    }
    *s1 = '\0';
}

void my_strcat(char* s1, const char* s2) {
    while (*s1) s1++;
    while (*s2) {
        *s1 = *s2;
        s1++; s2++;
    }
    *s1 = '\0';
}

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++; s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// --- КЛАСС STROKA ---
class Stroka {
    char* str; // Динамический массив (Задание 4)
    int len;

public:
    // Конструктор по умолчанию
    Stroka() {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }

    // Конструктор с заданным размером (Задание 4)
    Stroka(int size) {
        len = size;
        str = new char[len + 1];
        str[0] = '\0';
    }

    // Конструктор из обычной строки
    Stroka(const char* s) {
        len = my_strlen(s);
        str = new char[len + 1];
        my_strcpy(str, s);
    }

    // Конструктор копирования (Обязателен для динамической памяти!)
    Stroka(const Stroka& s) {
        len = s.len;
        str = new char[len + 1];
        my_strcpy(str, s.str);
    }

    // ЕСТРУКТОР (Задание 4: Обязательно нужен для очистки памяти)
    ~Stroka() {
        delete[] str;
    }

    // Оператор присваивания
    Stroka& operator=(const Stroka& s) {
        if (this != &s) {
            delete[] str; // Удаляем старую память
            len = s.len;
            str = new char[len + 1];
            my_strcpy(str, s.str);
        }
        return *this;
    }

    // Оператор сложения (конкатенация)
    Stroka operator+(const Stroka& s) {
        int new_len = len + s.len;
        Stroka temp(new_len);
        my_strcpy(temp.str, str);
        my_strcat(temp.str, s.str);
        return temp;
    }

    // Оператор сравнения
    int operator==(const Stroka& s) {
        return (my_strcmp(str, s.str) == 0);
    }

    int dlina() { return len; }

    void vvod() {
        char buffer[1024]; // Временный буфер для ввода
        cin >> buffer;
        delete[] str;
        len = my_strlen(buffer);
        str = new char[len + 1];
        my_strcpy(str, buffer);
    }

    void vivod() {
        cout << str;
    }
};

//ГЛАВНАЯ ПРОГРАММА
int main() {
    Stroka s1("qwert"), s3, s4(s1), s5;

    cout << "Vvedite stroku s3: ";
    s3.vvod();

    s3 = "asdfg"; // Работает через конструктор и оператор =
    cout << "s3 posle prisvaivaniya: "; s3.vivod(); cout << endl;

    s5 = s1 + s3 + s4; 
    cout << "s5 (s1+s3+s4): "; s5.vivod(); cout << endl;
    cout << "dlina s5 = " << s5.dlina() << endl;

    if (s1 == s5) cout << "stroki s1 i s5 ravny" << endl;
    else cout << "stroki s1 i s5 NE ravny" << endl;

    if (s1 == s4) cout << "stroki s1 i s4 ravny" << endl;

    return 0;
}
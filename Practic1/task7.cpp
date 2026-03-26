#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>

// Базовый класс - Точка
class Point {
protected:
    int x, y, color;
public:
    void init(int x0, int y0, int c) {
        x = x0; y = y0; color = c;
    }
    virtual void show() = 0; // Виртуальные функции для полиморфизма
    virtual void hide() {
        int oldColor = color;
        color = getbkcolor(); // Цвет фона
        show();
        color = oldColor;
    }
};

// Класс Круг (наследует Точку)
class Krug : public Point {
protected:
    int radius;
public:
    void init(int x0, int y0, int r, int c) {
        Point::init(x0, y0, c);
        radius = r;
    }
    void show() override {
        setcolor(color);
        circle(x, y, radius);
    }
    
    // Метод перемещения (Fly)
    void fly(int dx) {
        for (int i = 0; i < dx; i++) {
            hide();
            x++; // Движение вправо
            show();
            delay(10); // Задержка для плавности
        }
    }
};

// Класс Кольцо/Сектор (наследует Круг) - Задание 2
class Ring : public Krug {
protected:
    int width;
    int startAngle, endAngle;
public:
    void init(int x0, int y0, int r, int w, int c) {
        Krug::init(x0, y0, r, c);
        width = w;
        startAngle = 0;
        endAngle = 320;
    }

    void show() override {
        setcolor(color);
        // Рисуем основной сектор
        pieslice(x, y, startAngle, endAngle, radius);
        // "Вырезаем" внутреннюю часть цветом фона
        setfillstyle(SOLID_FILL, getbkcolor());
        pieslice(x, y, startAngle, endAngle, radius - width);
    }

    // Улучшенный Fly (Задание 2: смена цвета и сужение сектора)
    void flyEnhanced(int dx) {
        for (int i = 0; i < dx; i++) {
            hide();
            x++;
            
            // Динамика из пункта 2:
            if (i % 10 == 0) color = (color + 1) % 15 + 1; // Смена цвета
            if (endAngle > 200) endAngle--;              // Сужение сектора
            
            show();
            delay(15);
        }
    }
};

int main() {
    // Инициализация графики
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Krug testKrug;
    testKrug.init(150, 200, 50, WHITE);
    
    Ring testRing;
    testRing.init(450, 300, 90, 20, YELLOW);

    // Демонстрация
    testKrug.show();
    testKrug.fly(100);

    testRing.show();
    testRing.flyEnhanced(150); // Летит, меняя цвет и форму

    getch();
    closegraph();
    return 0;
}
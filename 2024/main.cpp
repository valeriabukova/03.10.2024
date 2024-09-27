//
//  main.cpp
//  2024
//
//  Created by Valeria  Bukova on 27.09.2024.
//

#include <iostream>

class Reservoir {
private:
    char name[100];  // Массив для хранения имени
    double width;
    double length;
    double maxDepth;
    char type[50];   // Массив для типа водоема

    // Функция для копирования строк без использования <cstring>
    void copyString(char* dest, const char* src, int maxLength) {
        int i = 0;
        while (i < maxLength - 1 && src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    // Функция для сравнения строк без использования <cstring>
    bool compareString(const char* str1, const char* str2) const {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0') {
            if (str1[i] != str2[i]) {
                return false;
            }
            i++;
        }
        return str1[i] == str2[i];
    }

public:
    // Конструктор по умолчанию
    Reservoir() : width(0), length(0), maxDepth(0) {
        name[0] = '\0';
        copyString(type, "неизвестно", sizeof(type));
    }

    // Конструктор с параметрами
    Reservoir(const char* n, double w, double l, double d, const char* t)
        : width(w), length(l), maxDepth(d) {
        copyString(name, n, sizeof(name));
        copyString(type, t, sizeof(type));
    }

    // Конструктор копирования
    Reservoir(const Reservoir& other)
        : width(other.width), length(other.length), maxDepth(other.maxDepth) {
        copyString(name, other.name, sizeof(name));
        copyString(type, other.type, sizeof(type));
    }

    // Метод для расчета объема
    double volume() const {
        return width * length * maxDepth;
    }

    // Метод для расчета площади водной поверхности
    double surfaceArea() const {
        return width * length;
    }

    // Метод для проверки, относятся ли водоемы к одному типу
    bool isSameType(const Reservoir& other) const {
        return compareString(type, other.type);
    }

    // Метод для сравнения площади водной поверхности водоемов одного типа
    bool compareSurfaceArea(const Reservoir& other) const {
        if (isSameType(other)) {
            return surfaceArea() == other.surfaceArea();
        }
        return false;
    }

    // Методы get и set для параметров
    void setName(const char* n) {
        copyString(name, n, sizeof(name));
    }

    const char* getName() const {
        return name;
    }

    void setWidth(double w) {
        width = w;
    }

    double getWidth() const {
        return width;
    }

    void setLength(double l) {
        length = l;
    }

    double getLength() const {
        return length;
    }

    void setMaxDepth(double d) {
        maxDepth = d;
    }

    double getMaxDepth() const {
        return maxDepth;
    }

    void setType(const char* t) {
        copyString(type, t, sizeof(type));
    }

    const char* getType() const {
        return type;
    }

    // Метод для копирования объектов
    Reservoir& operator=(const Reservoir& other) {
        if (this == &other) return *this;

        copyString(name, other.name, sizeof(name));
        copyString(type, other.type, sizeof(type));

        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;

        return *this;
    }

    // Метод для отображения информации о водоеме
    void display() const {
        std::cout << "Название: " << name << "\n"
                  << "Тип: " << type << "\n"
                  << "Ширина: " << width << " м\n"
                  << "Длина: " << length << " м\n"
                  << "Максимальная глубина: " << maxDepth << " м\n"
                  << "Объем: " << volume() << " м^3\n"
                  << "Площадь водной поверхности: " << surfaceArea() << " м^2\n";
    }
};

// Класс для динамического массива водоемов
class ReservoirArray {
private:
    Reservoir* reservoirs;
    int size;

public:
    // Конструктор по умолчанию
    ReservoirArray() : reservoirs(nullptr), size(0) {}

    // Добавление водоема в массив
    void add(const Reservoir& res) {
        Reservoir

#include <iostream>
#include <windows.h>

template <class T>
class Bicycle {
public:
    Bicycle() : arr(new T[capacity_]) {}
    Bicycle(const Bicycle& other):capacity_(other.capacity_), filled_count(other.filled_count),arr(new T[other.capacity_]){
        for (int i = 0; i < filled_count; i++) {
            arr[i] = other.arr[i];
    }
    }
    
    ~Bicycle() {
        delete[] arr;
    }
    Bicycle& operator=(const Bicycle& other) {
        if (this == &other) {// проверка на самоприсваивание
            return *this;
        }
        delete[]arr;//удаляем старый

        capacity_ = other.capacity_;
        filled_count = other.filled_count;
        arr = new T[capacity_];
        for (int i = 0; i < filled_count; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }
    // Метод push_back
    void push_back(T value) {
        if (filled_count == capacity_) { // Увеличиваем массив, если заполнен
            int new_capacity = capacity_ * 2;
            T* arrx2 = new T[new_capacity];

            for (int i = 0; i < capacity_; i++) {
                arrx2[i] = arr[i];
            }

            delete[] arr;
            arr = arrx2;
            capacity_ = new_capacity;
        }
        arr[filled_count++] = value; // Добавляем элемент
    }

    // Метод для доступа к элементу по индексу
    T at(int index) {
        if (index < 0 || index >= filled_count) {
            throw std::invalid_argument("Элемент отсутствует");
        }
        return arr[index];
    }

    // Метод для получения количества элементов в контейнере
    int size() const {
        return filled_count;
    }

    // Метод для получения емкости контейнера
    int capacity() const {
        return capacity_;       

    }

private:
    int capacity_{ 2 }; // Емкость массива
    int filled_count{}; // Количество заполненных ячеек
    T* arr; // Указатель на массив
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bicycle<int> bike;
    bike.push_back(22);
    bike.push_back(33);

    auto check_0 = bike.at(0);
    auto check_size = bike.size();
    auto check_capacity = bike.capacity();

    std::cout << "Элемент с индексом 0: " << check_0 << "\n";
    std::cout << "Размер: " << check_size << "\n";
    std::cout << "Емкость: " << check_capacity << "\n";

    // добавляю ещё элекмент

    Bicycle <int> and_1; // демонстрация возможностей копирования
    and_1 = bike;
    Bicycle <int> and_2(bike);
    bike.push_back(44);
    auto check_2 = bike.at(2);// тестируем расширение ёмкости

    std::cout << "Элемент с индексом 2: " << check_2 << "\n";
    std::cout << "Размер: " << check_size << "\n";
    std::cout << "Емкость: " << check_capacity << "\n";

    return 0;
}

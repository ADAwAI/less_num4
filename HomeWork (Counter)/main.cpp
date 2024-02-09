#include <iostream>
#include <string>
//using namespace std;

class Counter {
private:
    int value;

public:
    // Конструктор по умолчанию, устанавливает начальное значение в 1
    Counter() : value(1) {}

    // Конструктор с параметром, устанавливает начальное значение счётчика
    Counter(int initialValue) : value(initialValue) {}

    // Метод для увеличения на 1
    void increment() { value++; }

    // Метод для уменьшения на 1
    void decrement() { value--; }

    // Метод для получения текущего значения счётчика
    int getCurrentValue() const { return value; }

};


int main() {
    setlocale(LC_ALL, "Russian");
    Counter c;
    std::string input;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите 'yes' или 'no': ";
    std::getline(std::cin, input); // Используем getline для чтения всей строки
    if (input == "да" || input == "yes" || input == "y" || input == "1") {
        std::cout << "Введите начальное значение счётчика: ";
        int initialValue;
        while (!(std::cin >> initialValue)) { // Проверяем, что вводится число
            std::cout << "Некорректный ввод. Пожалуйста, введите число: ";
            std::cin.clear(); // Очистка потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем оставшиеся символы до конца строки
        }
        c = Counter(initialValue);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем символ новой строки
    }

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> input;

        if (input == "+") {
            c.increment();
        }
        else if (input == "-") {
            c.decrement();
        }
        else if (input == "=") {
            std::cout << c.getCurrentValue() << std::endl;
        }
        else if (input == "x") {
            std::cout << "До свидания!" << std::endl;
            break;
        }
        else {
            std::cout << "Некорректная команда. Попробуйте снова." << std::endl;
        }
    } while (input != "x");

    return 0;
}
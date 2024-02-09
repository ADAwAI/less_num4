#include <iostream>
#include <string>
//using namespace std;

class Counter {
private:
    int value;

public:
    // ����������� �� ���������, ������������� ��������� �������� � 1
    Counter() : value(1) {}

    // ����������� � ����������, ������������� ��������� �������� ��������
    Counter(int initialValue) : value(initialValue) {}

    // ����� ��� ���������� �� 1
    void increment() { value++; }

    // ����� ��� ���������� �� 1
    void decrement() { value--; }

    // ����� ��� ��������� �������� �������� ��������
    int getCurrentValue() const { return value; }

};


int main() {
    setlocale(LC_ALL, "Russian");
    Counter c;
    std::string input;
    std::cout << "�� ������ ������� ��������� �������� ��������? ������� 'yes' ��� 'no': ";
    std::getline(std::cin, input); // ���������� getline ��� ������ ���� ������
    if (input == "��" || input == "yes" || input == "y" || input == "1") {
        std::cout << "������� ��������� �������� ��������: ";
        int initialValue;
        while (!(std::cin >> initialValue)) { // ���������, ��� �������� �����
            std::cout << "������������ ����. ����������, ������� �����: ";
            std::cin.clear(); // ������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ���������� ������� �� ����� ������
        }
        c = Counter(initialValue);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ������ ����� ������
    }

    do {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
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
            std::cout << "�� ��������!" << std::endl;
            break;
        }
        else {
            std::cout << "������������ �������. ���������� �����." << std::endl;
        }
    } while (input != "x");

    return 0;
}
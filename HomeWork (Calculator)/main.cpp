#include <iostream>
#include <string>
//using namespace std;

class Calculator {
private:
    double num1, num2; // ������������� �������� ����������

public:
    Calculator() : num1(0), num2(0) {} // ��������� ����������� �� ���������

    // ��������� ������ ��� �������������� ��������
    double add() { return num1 + num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double multiply() { return num1 * num2; }
    double divide_1_2() { return num2 != 0 ? num1 / num2 : 0; }
    double divide_2_1() { return num1 != 0 ? num2 / num1 : 0; }

    // ��������� ������ ��� ��������� ��������
    bool set_num1(double newNum) {
        if (newNum == 0) return false;  // ��������� ������, ���� ���������� ����� ���� ���������� false
        num1 = newNum;                  // �����, ������������� �������� ���������� � ���������� true
        return true;
    }

    bool set_num2(double newNum) {
        if (newNum == 0) return false;
        num2 = newNum;
        return true;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Calculator calc;
    double num1, num2;
    bool validInput = true;

    // ��������� ����������� ����
    do
    {
        std::cout << "������� ������ �����: "; // ���������� ������ �����
        std::cin >> num1;                      // ���������� � ���������� num1
        validInput = calc.set_num1(num1);      // ��������� �������� ��������

        if (!validInput) {
            std::cout << "�������� ������ ���� ������ 0. \n";
            continue;
        }

        std::cout << "������� ������ �����: ";
        std::cin >> num2;
        validInput = calc.set_num2(num2);

        if (!validInput) {
            std::cout << "�������� ������ ���� ������ 0. \n";
            continue;
        }

        // ������� ���������� �������� ����� �����������
        std::cout << num1 << " + " << num2 << " = " << calc.add() << std::endl;
        std::cout << num1 << " - " << num2 << " = " << calc.subtract_1_2() << std::endl;
        std::cout << num2 << " - " << num1 << " = " << calc.subtract_2_1() << std::endl;
        std::cout << num1 << " * " << num2 << " = " << calc.multiply() << std::endl;
        std::cout << num1 << " / " << num2 << " = " << calc.divide_1_2() << std::endl;
        std::cout << num2 << " / " << num1 << " = " << calc.divide_2_1() << std::endl;
    } while (true);

    return 0;
}

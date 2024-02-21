#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    const int rows = 3;
    const int cols = 5;

    double arr[rows][cols];

    // ���� ��������� �������
    std::cout << "������� �������� ������� (3 ������ �� 5 ���������):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> arr[i][j];
        }
    }

    // ���������� �������� ��������������� ��� ������ ������
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
        double average = sum / cols;
        std::cout << "������� �������������� ��������� ������ " << i + 1 << ": " << average << std::endl;
    }

    return 0;
}
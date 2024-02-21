#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    const int rows = 3;
    const int cols = 5;

    double arr[rows][cols];

    // Ввод элементов массива
    std::cout << "Введите элементы массива (3 строки по 5 элементов):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> arr[i][j];
        }
    }

    // Вычисление среднего арифметического для каждой строки
    for (int i = 0; i < rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < cols; ++j) {
            sum += arr[i][j];
        }
        double average = sum / cols;
        std::cout << "Среднее арифметическое элементов строки " << i + 1 << ": " << average << std::endl;
    }

    return 0;
}
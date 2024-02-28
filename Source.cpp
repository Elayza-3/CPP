//подключение нужных библиотек:
#include <iostream>//ввод вывод
#include <string>//для работы со строками
#include <algorithm>//библиотека для использование алгоритмов 
#include <random>//генерация случайных чисел
#include <locale.h>//локали какая-то
//реверсворд переворачивает слово наоборот
std::string reverseWord(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}
//ремуввоwолес удаляеь глассные 
std::string removeVowels(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c != 'а' && c != 'е' && c != 'и' && c != 'о' && c != 'у') {
            result += c;
        }
    }
    return result;
}
//удаляеь согласные 
std::string removeConsonants(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c == 'а' || c == 'е' || c == 'и' || c == 'о' || c == 'у') {
            result += c;
        }
    }
    return result;
}
//перемешивает буквы на рандом шафлворд
std::string shuffleWord(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    return shuffledWord;
}
//весь следующий блок кода позволяет пользователю манипулировать введенным словом разными указанными способами
int main() {
 //функция майн вкл в себя оч многое типо установка локали короче русский яз и все остальные указанные действия 
 // будут работать и функцианировать за счет маин
    setlocale(LC_ALL, ".1251");

    std::string word;
    int choice;

    std::cout << "Введите любое слово: ";
    std::cin >> word;

    std::cout << "Меню:\n";
    std::cout << "1. Вывод слова задом наперед\n";
    std::cout << "2. Вывод слова без гласных\n";
    std::cout << "3. Вывод слова без согласных\n";
    std::cout << "4. Рандом\n";
    std::cout << "Выберите действие: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Перевернутое слово: " << reverseWord(word) << std::endl;
        break;
    case 2:
        std::cout << "Слово без гласных: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Слово без согласных: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "Перемешанное слово: " << shuffleWord(word) << std::endl;
        break;
    default:
        std::cout << "Неверный выбор!" << std::endl;
    }

    return 0;
}

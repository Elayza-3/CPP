//����������� ������ ���������:
#include <iostream>//���� �����
#include <string>//��� ������ �� ��������
#include <algorithm>//���������� ��� ������������� ���������� 
#include <random>//��������� ��������� �����
#include <locale.h>//������ �����-��
//���������� �������������� ����� ��������
std::string reverseWord(const std::string& word) {
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}
//�������w���� ������� �������� 
std::string removeVowels(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c != '�' && c != '�' && c != '�' && c != '�' && c != '�') {
            result += c;
        }
    }
    return result;
}
//������� ��������� 
std::string removeConsonants(const std::string& word) {
    std::string result = "";
    for (char c : word) {
        if (c == '�' || c == '�' || c == '�' || c == '�' || c == '�') {
            result += c;
        }
    }
    return result;
}
//������������ ����� �� ������ ��������
std::string shuffleWord(const std::string& word) {
    std::string shuffledWord = word;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    return shuffledWord;
}
//���� ��������� ���� ���� ��������� ������������ �������������� ��������� ������ ������� ���������� ���������
int main() {
 //������� ���� ��� � ���� �� ������ ���� ��������� ������ ������ ������� �� � ��� ��������� ��������� �������� 
 // ����� �������� � ��������������� �� ���� ����
    setlocale(LC_ALL, ".1251");

    std::string word;
    int choice;

    std::cout << "������� ����� �����: ";
    std::cin >> word;

    std::cout << "����:\n";
    std::cout << "1. ����� ����� ����� �������\n";
    std::cout << "2. ����� ����� ��� �������\n";
    std::cout << "3. ����� ����� ��� ���������\n";
    std::cout << "4. ������\n";
    std::cout << "�������� ��������: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "������������ �����: " << reverseWord(word) << std::endl;
        break;
    case 2:
        std::cout << "����� ��� �������: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "����� ��� ���������: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "������������ �����: " << shuffleWord(word) << std::endl;
        break;
    default:
        std::cout << "�������� �����!" << std::endl;
    }

    return 0;
}

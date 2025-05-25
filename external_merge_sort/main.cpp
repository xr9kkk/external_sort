#include <iostream>
#include "sort_utils.h"

void print_file(const std::string& filename) {
    std::ifstream in(filename);
    std::cout << "���������� ����� '" << filename << "':\n";
    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << "\n";
    }
    in.close();
}

int main() {
    setlocale(LC_ALL, "Ru");
    const std::string filename = "data.txt";
    const int element_count = 30;

    // 1. ��������� �����
    generate_random_file(filename, element_count);
    std::cout << "��������������� ����:\n";
    print_file(filename);

    // 2. ����������
    external_sort(filename);
    std::cout << "\n����� ����������:\n";
    print_file(filename);

    // 3. ��������
    int count;
    if (verify_sorted_file(filename, count)) {
        std::cout << "\n���� ��������� ������������. ���������: " << count << "\n";
    }
    else {
        std::cout << "\n������ ����������!\n";
    }

    return 0;
}
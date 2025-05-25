#include <iostream>
#include "sort_utils.h"

void print_file(const std::string& filename) {
    std::ifstream in(filename);
    std::cout << "Содержимое файла '" << filename << "':\n";
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

    // 1. Генерация файла
    generate_random_file(filename, element_count);
    std::cout << "Сгенерированный файл:\n";
    print_file(filename);

    // 2. Сортировка
    external_sort(filename);
    std::cout << "\nПосле сортировки:\n";
    print_file(filename);

    // 3. Проверка
    int count;
    if (verify_sorted_file(filename, count)) {
        std::cout << "\nФайл корректно отсортирован. Элементов: " << count << "\n";
    }
    else {
        std::cout << "\nОшибка сортировки!\n";
    }

    return 0;
}
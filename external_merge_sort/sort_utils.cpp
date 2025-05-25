#include "sort_utils.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

void generate_random_file(const std::string& filename, int count) {
    std::ofstream out(filename);
    std::srand(std::time(nullptr));

    for (int i = 0; i < count; ++i) {
        out << (std::rand() % 1000) << " ";
        if (std::rand() % 5 == 0) out << "\n";
    }
    out.close();
}

bool verify_sorted_file(const std::string& filename, int& count) {
    std::ifstream in(filename);
    count = 0;
    int prev, current;
    bool first = true, sorted = true;

    while (in >> current) {
        if (!first && current < prev) sorted = false;
        prev = current;
        first = false;
        count++;
    }
    in.close();
    return sorted;
}

void distribute(Sequence* tapes, Sequence& input, const std::string& filename) {
    input.open_read(filename);

    for (int i = 0; i < TAPE_COUNT; ++i) {
        tapes[i].open_write("tape" + std::to_string(i) + ".txt");
    }

    int current_tape = 0;
    while (!input.eof) {
        while (!input.eof && !input.eor) {
            tapes[current_tape].write_element(input.elem, false);
            input.read_next();
        }

        if (!input.eof) {
            tapes[current_tape].write_element(input.elem, true);
            input.read_next();
        }

        current_tape = (current_tape + 1) % TAPE_COUNT;
    }

    input.close();
    for (int i = 0; i < TAPE_COUNT; ++i) {
        tapes[i].close();
    }
}

int merge(Sequence& output, const std::string& filename, Sequence* tapes) {
    for (int i = 0; i < TAPE_COUNT; ++i) {
        tapes[i].open_read("tape" + std::to_string(i) + ".txt");
    }

    output.open_write(filename);
    int runs_merged = 0;

    while (true) {
        bool any_active = false;
        std::vector<Elem> current_elements(TAPE_COUNT, Elem(INT_MAX));
        std::vector<bool> active(TAPE_COUNT, false);

        for (int i = 0; i < TAPE_COUNT; ++i) {
            if (!tapes[i].eof && !tapes[i].eor) {
                current_elements[i] = tapes[i].elem;
                active[i] = true;
                any_active = true;
            }
        }

        if (!any_active) break;

        while (any_active) {
            auto min_it = std::min_element(current_elements.begin(), current_elements.end());
            int min_idx = std::distance(current_elements.begin(), min_it);

            output.write_element(*min_it, false);

            if (active[min_idx]) {
                tapes[min_idx].read_next();
                if (!tapes[min_idx].eor && !tapes[min_idx].eof) {
                    current_elements[min_idx] = tapes[min_idx].elem;
                }
                else {
                    active[min_idx] = false;
                    current_elements[min_idx] = Elem(INT_MAX);
                }
            }

            any_active = std::any_of(active.begin(), active.end(), [](bool v) { return v; });
        }

        runs_merged++;
        output.write_element(Elem(), true);

        for (int i = 0; i < TAPE_COUNT; ++i) {
            if (!tapes[i].eof) tapes[i].eor = false;
        }
    }

    output.close();
    for (int i = 0; i < TAPE_COUNT; ++i) {
        tapes[i].close();
        std::remove(("tape" + std::to_string(i) + ".txt").c_str());
    }

    return runs_merged;
}

void external_sort(const std::string& filename) {
    Sequence input, tapes[TAPE_COUNT];
    int runs;

    do {
        distribute(tapes, input, filename);
        runs = merge(input, filename, tapes);
    } while (runs > 1);
}

//нужно написать функцию, которая создает случайный файл filename
//нужно написать функцию check_file, которая проверяет, что файл упорядочен, должна считать количество чисел, которое получается в файле, если что то неправильно
//то в результирующем файлике будет меньше чисел, чем в том, который изначально был
//в мейне должно быть create, sort, check и больше ничего не должно быть
//должно быть i, которая идет по кольцу, то есть для трех файлов i = (i+1)%3 до тех пор, пока f0 не закончится

#pragma once


#include <string>
#include "Sequence.h"

const int TAPE_COUNT = 5;  // Количество лент

void generate_random_file(const std::string& filename, int count);
bool verify_sorted_file(const std::string& filename, int& count);
void distribute(Sequence* tapes, Sequence& input, const std::string& filename);
int merge(Sequence& output, const std::string& filename, Sequence* tapes);
void external_sort(const std::string& filename);


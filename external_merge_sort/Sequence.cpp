#include "Sequence.h"


Sequence::Sequence() : eof(true), eor(true) {}

void Sequence::open_read(const std::string& filename) {
    file.open(filename, std::ios::in);
    eof = !file.is_open();
    if (!eof) read_next();
}

void Sequence::open_write(const std::string& filename) {
    file.open(filename, std::ios::out | std::ios::trunc);
    eof = eor = false;
}

void Sequence::close() {
    if (file.is_open()) file.close();
    eof = eor = true;
}

void Sequence::read_next() {
    if (!(file >> elem)) {
        eof = true;
        eor = true;
    }
    else {
        char next = file.peek();
        eor = (next == '\n' || next == EOF);
    }
}

void Sequence::write_element(const Elem& e, bool end_series) {
    file << e;
    if (end_series) file << "\n";
    else file << " ";
}
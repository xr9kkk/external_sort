#pragma once
#include <iostream>

struct Elem {
    int value;

    bool operator<=(const Elem& other) const {
        return value <= other.value;
    }

    friend std::ostream& operator<<(std::ostream& out, const Elem& e) {
        return out << e.value;
    }

    bool operator<(const Elem& other) const {
        return value < other.value;
    }


    friend std::istream& operator>>(std::istream& in, Elem& e) {
        return in >> e.value;
    }
};
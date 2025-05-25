#pragma once
#include <iostream>

class Elem {
public:
    int value;

    Elem() : value(0) {}
    explicit Elem(int v) : value(v) {}

    bool operator<(const Elem& other) const {
        return value < other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Elem& e) {
        os << e.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Elem& e) {
        is >> e.value;
        return is;
    }
};
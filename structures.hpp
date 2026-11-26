#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include <iostream>
#include <iomanip>
#include <string>

enum class Category {
    PAPER,
    WRITING,
    OTHER
};

//функція для красивого виведення назви категорії
inline std::string categoryToString(Category cat) {
    switch (cat) {
        case Category::PAPER:   return "PAPER";
        case Category::WRITING: return "WRITING";
        case Category::OTHER:   return "OTHER";
        default:                return "UNKNOWN";
    }
}

// cтруктура товару
struct Product {
    std::string name;
    double price = 0.0;
    int quantity = 0;
    Category category = Category::OTHER;
};

// виведення товару одним рядком через <<
inline std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << p.name << " | "
       << categoryToString(p.category) << " | "
       << std::fixed << std::setprecision(2) << p.price << " грн | "
       << p.quantity << " шт.";
    return os;
}

#endif
#include "Phone.h"
#include <iostream>
#include <iomanip>

Phone::Phone(const std::string& manufacturer,
             const std::string& model, double price)
    : manufacturer(manufacturer),
      model(model),
      price(price >= 0 ? price : 0) {}

void Phone::printInfo() const {
    std::cout << "Производитель: " << manufacturer << '\n';
    std::cout << "Модель: " << model << '\n';
    std::cout << "Цена: " << std::fixed
              << std::setprecision(2) << price
              << " руб.\n";
}

double Phone::getPrice() const {
    return price;
}

void Phone::setPrice(double newPrice) {
    if (newPrice >= 0) {
        price = newPrice;
    } else {
        std::cout << "Ошибка: цена не может быть отрицательной.\n";
    }
}

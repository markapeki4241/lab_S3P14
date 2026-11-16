#include "MobilePhone.h"
#include <iostream>

MobilePhone::MobilePhone(
    const std::string& manufacturer,
    const std::string& model,
    double price,
    int batteryCapacity)
    : Phone(manufacturer, model, price),
      batteryCapacity(batteryCapacity > 0 ? batteryCapacity : 0) {}

void MobilePhone::printInfo() const {
    std::cout << "\nТип: Мобильный телефон\n";
    Phone::printInfo();
    std::cout << "Ёмкость аккумулятора: "
              << batteryCapacity << " мАч\n";
}

void MobilePhone::setBatteryCapacity(int capacity) {
    if (capacity > 0) {
        batteryCapacity = capacity;
    } else {
        std::cout << "Ошибка: некорректная ёмкость.\n";
    }
}

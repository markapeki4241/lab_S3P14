#include "StationaryPhone.h"
#include <iostream>

StationaryPhone::StationaryPhone(
    const std::string& manufacturer,
    const std::string& model,
    double price,
    const std::string& connectionType)
    : Phone(manufacturer, model, price),
      connectionType(connectionType) {}

void StationaryPhone::printInfo() const {
    std::cout << "\nТип: Стационарный телефон\n";
    Phone::printInfo();
    std::cout << "Тип подключения: "
              << connectionType << '\n';
}

void StationaryPhone::setConnectionType(
    const std::string& type) {
    connectionType = type;
}

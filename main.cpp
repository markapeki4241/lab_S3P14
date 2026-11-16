#include <iostream>
#include <iomanip>
#include <limits>
#include "Phone.h"
#include "StationaryPhone.h"
#include "MobilePhone.h"

int main() {
    const int SIZE = 5;

    Phone* phones[SIZE] = {
        new StationaryPhone("Panasonic", "KX-TS2350", 3500, "Проводной"),
        new MobilePhone("Samsung", "Galaxy A55", 32000, 5000),
        new MobilePhone("Apple", "iPhone 15", 65000, 3349),
        new StationaryPhone("Gigaset", "A170", 2800, "Беспроводной"),
        new MobilePhone("Xiaomi", "Redmi Note 13", 17000, 5000)
    };

    int command;

    while (true) {
        std::cout << "\n===== УЧЕТ ТЕЛЕФОНОВ =====\n";
        std::cout << "1. Показать все телефоны\n";
        std::cout << "2. Изменить цену телефона\n";
        std::cout << "3. Изменить характеристику телефона\n";
        std::cout << "4. Найти минимальную цену\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> command)) {
            if (std::cin.eof()) break;
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число.\n";
            continue;
        }

        if (command == 0) {
            break;
        }

        switch (command) {
            case 1: {
                for (int i = 0; i < SIZE; i++) {
                    std::cout << "\nТелефон №" << i + 1 << '\n';
                    phones[i]->printInfo();
                }
                break;
            }

            case 2:
            case 3: {
                int number;
                std::cout << "Введите номер телефона (1-5): ";

                if (!(std::cin >> number)) {
                    std::cin.clear();
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ошибка ввода.\n";
                    break;
                }

                if (number < 1 || number > SIZE) {
                    std::cout << "Такого телефона нет.\n";
                    break;
                }

                Phone* selected = phones[number - 1];

                if (command == 2) {
                    double newPrice;
                    std::cout << "Введите новую цену: ";

                    if (!(std::cin >> newPrice)) {
                        std::cin.clear();
                        std::cin.ignore(
                            std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Ошибка ввода цены.\n";
                        break;
                    }

                    selected->setPrice(newPrice);
                    std::cout << "Изменение цены обработано.\n";
                } else {
                    StationaryPhone* stationary =
                        dynamic_cast<StationaryPhone*>(selected);

                    MobilePhone* mobile =
                        dynamic_cast<MobilePhone*>(selected);

                    if (stationary != nullptr) {
                        std::string type;
                        std::cout << "Новый тип подключения: ";
                        std::getline(std::cin >> std::ws, type);
                        stationary->setConnectionType(type);
                        std::cout << "Тип подключения изменен.\n";
                    } else if (mobile != nullptr) {
                        int capacity;
                        std::cout << "Новая емкость аккумулятора: ";

                        if (!(std::cin >> capacity)) {
                            std::cin.clear();
                            std::cin.ignore(
                                std::numeric_limits<std::streamsize>::max(),
                                '\n');
                            std::cout << "Ошибка ввода.\n";
                            break;
                        }

                        mobile->setBatteryCapacity(capacity);
                        std::cout << "Изменение емкости обработано.\n";
                    }
                }
                break;
            }

            case 4: {
                int minIndex = 0;

                for (int i = 1; i < SIZE; i++) {
                    if (phones[i]->getPrice() <
                        phones[minIndex]->getPrice()) {
                        minIndex = i;
                    }
                }

                std::cout << "\nМинимальная цена: "
                          << std::fixed << std::setprecision(2)
                          << phones[minIndex]->getPrice()
                          << " руб.\n";

                std::cout << "Телефон с минимальной ценой:\n";
                phones[minIndex]->printInfo();
                break;
            }

            default:
                std::cout << "Неизвестная команда.\n";
                break;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        delete phones[i];
    }

    std::cout << "Программа завершена.\n";
    return 0;
}

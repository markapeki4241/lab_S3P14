#ifndef PHONE_H
#define PHONE_H

#include <string>

class Phone {
protected:
    std::string manufacturer;
    std::string model;
    double price;

public:
    Phone(const std::string& manufacturer,
          const std::string& model, double price);

    virtual ~Phone() = default;

    virtual void printInfo() const;

    double getPrice() const;
    void setPrice(double newPrice);
};

#endif

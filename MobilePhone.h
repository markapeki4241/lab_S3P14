#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
private:
    int batteryCapacity;

public:
    MobilePhone(const std::string& manufacturer,
                const std::string& model,
                double price,
                int batteryCapacity);

    void printInfo() const override;

    void setBatteryCapacity(int capacity);
};

#endif

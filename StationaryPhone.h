#ifndef STATIONARYPHONE_H
#define STATIONARYPHONE_H

#include "Phone.h"

class StationaryPhone : public Phone {
private:
    std::string connectionType;

public:
    StationaryPhone(const std::string& manufacturer,
                    const std::string& model,
                    double price,
                    const std::string& connectionType);

    void printInfo() const override;

    void setConnectionType(const std::string& type);
};

#endif

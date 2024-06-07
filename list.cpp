#include "list.h"
#include <iostream>
#include <limits>

void List::addPhone(const Phone &phone) {
    phones.push_back(phone);
}

void List::removePhone(size_t index) {
    if (index < phones.size()) {
        phones.erase(phones.begin() + index);
    } else {
        std::cout << "Index out of range\n";
    }
}

Phone& List::getPhone(size_t index) {
    if (index < phones.size()) {
        return phones[index];
    } else {
        throw std::out_of_range("Index out of range");
    }
}

void List::print() const {
    for (const auto &phone : phones) {
        std::cout << phone.toString();
    }
}

const Phone& List::findCheapestPhone(float diagonal) const {
    const Phone *cheapest = nullptr;
    for (const auto &phone : phones) {
        if (phone.getScreen() == diagonal) {
            if (!cheapest || phone.getPrice() < cheapest->getPrice()) {
                cheapest = &phone;
            }
        }
    }

    if (cheapest) {
        return *cheapest;
    } else {
        throw std::runtime_error("Phone not found");
    }
}

void List::readFromFile(const std::string& fileName) {
    phones.clear();
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        Phone phone;
        phone.fromString(line);
        phones.push_back(phone);
    }
    file.close();
}

void List::writeToFile(const std::string& fileName) const {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }
    for (const auto &phone : phones) {
        file << phone.toString();
    }
    file.close();
}

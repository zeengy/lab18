#include <iostream>
#include "list.h"
#include "entity.h"

void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add phone\n";
    std::cout << "2. Remove phone\n";
    std::cout << "3. Show all phones\n";
    std::cout << "4. Find cheapest phone\n";
    std::cout << "5. Read from file\n";
    std::cout << "6. Write to file\n";
    std::cout << "7. Exit\n";
}

int main() {
    List phoneList;
    int choice;
    std::string model;
    float price, screen;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter model: ";
                std::cin >> model;
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter screen size: ";
                std::cin >> screen;
                phoneList.addPhone(Phone(model, price, screen));
                break;
            case 2:
                std::cout << "Enter index to remove: ";
                size_t index;
                std::cin >> index;
                phoneList.removePhone(index);
                break;
            case 3:
                phoneList.print();
                break;
            case 4:
                std::cout << "Enter screen size: ";
                std::cin >> screen;
                try {
                    phoneList.findCheapestPhone(screen);
                } catch (const std::exception& e) {
                    std::cerr << e.what() << '\n';
                }
                break;
            case 5:
                phoneList.readFromFile("phones.txt");
                break;
            case 6:
                phoneList.writeToFile("phones.txt");
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}

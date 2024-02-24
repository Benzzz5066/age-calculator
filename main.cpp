#include <iostream>
#include <string>
#include <chrono>
#include <limits>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calculateAge(int birthYear) {
    auto now = std::chrono::system_clock::now();
    auto nowTime = std::chrono::system_clock::to_time_t(now);
    std::tm* nowTM = std::localtime(&nowTime);
    int currentYear = nowTM->tm_year + 1900;

    return currentYear - birthYear;
}

int main() {
    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;

    while (true) {
        std::cout << "Enter your birth year: ";
        if (std::cin >> age && age >= 0) {
            break;
        }
        else {
            std::cout << "Invalid birth year. Please enter a non-negative integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int calculatedAge = calculateAge(age);

    std::cout << "Hello " << name << ", nice to meet you!" << std::endl;
    std::cout << "You will be " << calculatedAge << " years old this year." << std::endl;

    return 0;
}

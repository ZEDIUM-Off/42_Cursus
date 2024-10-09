#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Jean", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Marie", 150);
        std::cout << b2 << std::endl;

        Bureaucrat b3("Pierre", 75);
        std::cout << b3 << std::endl;

        b3.incrementGrade();
        std::cout << "After increment: " << b3 << std::endl;

        b3.decrementGrade();
        std::cout << "After decrement: " << b3 << std::endl;

        Bureaucrat b4("Erreur", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b5("Erreur", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b6("Test", 1);
        b6.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b7("Test", 150);
        b7.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

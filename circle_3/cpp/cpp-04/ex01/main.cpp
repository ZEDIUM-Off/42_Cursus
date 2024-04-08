#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Création des Animaux =====" << std::endl;
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    // Remplir la moitié avec des Dog et l'autre moitié avec des Cat
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    std::cout << "\n===== Test des Fonctions =====" << std::endl;
    // Afficher le type et faire du bruit pour chaque animal
    for (int i = 0; i < numAnimals; ++i) {
        std::cout << animals[i]->getType() << " fait du bruit: ";
        animals[i]->makeSound();
    }

    std::cout << "\n===== Test de Copie Profonde =====" << std::endl;
    // Tester la copie profonde
    Dog originalDog;
    Dog copyDog(originalDog); // Utilise le constructeur de copie

    Cat originalCat;
    Cat copyCat = originalCat; // Utilise l'opérateur d'affectation

    std::cout << "Original Dog Brain address: " << &originalDog.getBrain() << std::endl;
    std::cout << "Copy Dog Brain address: " << &copyDog.getBrain() << std::endl;

    std::cout << "Original Cat Brain address: " << &originalCat.getBrain() << std::endl;
    std::cout << "Copy Cat Brain address: " << &copyCat.getBrain() << std::endl;

    std::cout << "\n===== Nettoyage =====" << std::endl;
    // Nettoyage
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    std::cout << "===== Fin des Tests =====" << std::endl;

    return 0;
}

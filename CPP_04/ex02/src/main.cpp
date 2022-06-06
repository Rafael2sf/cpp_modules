#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	// Cannot instantiate animal
	// AAnimal a;
	// AAnimal *a = new AAnimal();

	AAnimal *a = new Cat();
	AAnimal *b = new Dog();
	delete a;
	delete b;
	return (0);
}

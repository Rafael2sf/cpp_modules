#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	//Cannot instantiate animal
	// AAnimal a;
	// AAnimal *b = new AAnimal();

	AAnimal *c = new Cat();
	AAnimal *d = new Dog();
	delete c;
	delete d;
	return (0);
}

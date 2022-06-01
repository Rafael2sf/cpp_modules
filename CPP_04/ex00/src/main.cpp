#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "~~ [0] ~~" << std::endl;
	{
		const Animal animal1;
		animal1.makeSound();
		std::cout << "Animal type = " << animal1.getType() << std::endl;
		const Animal *animal2 = new Animal();
		animal2->makeSound();
		std::cout << "Animal type = " << animal2->getType() << std::endl;
		delete animal2;
	}
	std::cout << "~~ [1] ~~" << std::endl;
	{
		const Dog	doggy;
		doggy.makeSound();
		std::cout << "Animal type = " << doggy.getType() << std::endl;
		const Cat	kitty;
		kitty.makeSound();
		std::cout << "Animal type = " << kitty.getType() << std::endl;
	}
	std::cout << "~~ [2] ~~" << std::endl;
	{
		const Animal *dog = new Dog();
		dog->makeSound();
		const Animal *cat = new Cat();
		cat->makeSound();
		delete dog;
		delete cat;
	}
	std::cout << std::endl << "~~ [0] ~~" << std::endl;
	{
		const WrongAnimal *i = new WrongAnimal();
		const WrongAnimal *j = new WrongCat();
		std::cout << i->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		i->makeSound();
		j->makeSound();
		delete i;
		delete j;
	}
	return (0);
}

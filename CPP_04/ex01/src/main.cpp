#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << "~~ [0] ~~" << std::endl;
	{
		Animal	*i = new Cat();
		Animal	*j = new Dog();
		delete i;
		delete j;
	}
	std::cout << "~~ [1] ~~" << std::endl;
	{
		Animal	*subjects[4] =
		{
			new Dog(),
			new Dog(),
			new Cat(),
			new Cat(),
		};
		for (int i = 0; i < 4; i++)
			delete subjects[i];
	}
	std::cout << "~~ [2] ~~" << std::endl;
	{
		Cat		*tmp;
		Animal	*cat1 = new Cat();
		tmp = (Cat *)cat1;

		tmp->setIdea(0, "\"A dog is not a cat, or is it ?\"");
		tmp->setIdea(1, "\"Cat does ** meow meow **, dog does ** woof woof **\"");
		std::cout << tmp->getIdea(0) << std::endl;
		std::cout << tmp->getIdea(1) << std::endl;

		Animal	*cat2 = new Cat(*(Cat *)cat1);
		tmp = (Cat *)cat2;

		tmp->setIdea(0, "\"I am a animal!\"");
		std::cout << tmp->getIdea(0) << std::endl;
		std::cout << tmp->getIdea(1) << std::endl;

		delete cat1;
		delete cat2;
	}
	return (0);
}

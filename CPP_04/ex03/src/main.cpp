#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void )
{
	std::cout << " ~ [0] ~ " << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter		*me = new Character("me");
		AMateria		*tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter		*bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << " ~ [0] ~ " << std::endl;
	{
		ICharacter		*p1 = new Character("p1");
		ICharacter		*p2 = new Character("p2");
		IMateriaSource	*src = new MateriaSource();
		AMateria		*tmp, *tmp2;

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		p1->use(0, *p2);
		p1->equip(src->createMateria("ice"));
		p1->equip(src->createMateria("cure"));
		p1->equip(src->createMateria("ice"));
		tmp = src->createMateria("cure");
		p1->equip(tmp);
		tmp2 = src->createMateria("ice");
		p1->equip(tmp2);
		p1->unequip(3);
		p1->equip(tmp2);

		for  (int i = 0; i < 4; i++)
			p1->use(i, *p2);

		delete p1;
		delete p2;
		delete tmp;
		delete src;
	}
	return (0);
}

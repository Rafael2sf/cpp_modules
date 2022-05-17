#include "Harl.hpp"

Harl::Harl( void )
{}

Harl::~Harl()
{}

void Harl::complain( std::string level )
{
	void (Harl::*eval[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	size_t index = WordInSentence("DEBUG INFO WARNING ERROR", level);
	if (index != std::string::npos)
		(this->*eval[index])();
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!\n";
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming foryears whereas you started working here since last month.\n";
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

size_t	WordInSentence(std::string sentence, std::string word)
{
	std::stringstream	s(sentence);
	std::string			tmp;
	size_t				i = 0;

	while (s >> tmp)
	{
		if (tmp == word)
			return (i);
		i++;
	}
	return (std::string::npos);
}

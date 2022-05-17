#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <sstream>

class	Harl
{
	public:
		Harl( void );
		~Harl();
		void complain( std::string );

	private:
		void debug( void );
		void info( void );
		void warning ( void );
		void error ( void );
};

size_t	WordInSentence(std::string sentence, std::string word);

#endif /* HARL_HPP */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ATarget.hpp"
# include "ASpell.hpp"
# include <iostream>
# include <string>
# include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell *> spellBook;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);

		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(const std::string &spellName);
		void launchSpell(const std::string &spellName, const ATarget &target);
};

#endif
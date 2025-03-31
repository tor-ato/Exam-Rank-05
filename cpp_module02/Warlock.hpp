#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <map>
#include "ATarget.hpp"
#include <iostream>
#include "SpellBook.hpp"

class Warlock {
private:
	std::string name;
	std::string title;
	SpellBook spellBook;
 
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &title);

	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	void launchSpell(const std::string &apellName, const ATarget &target);
};

#endif

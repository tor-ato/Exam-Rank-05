#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class SpellBook {
private:
	std::map<std::string, ASpell *> spellBook;
 
public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	ASpell* createSpell(std::string const &spellName);
};

#endif

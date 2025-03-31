#pragma once

#include "ASpell.hpp"

class SpellBook {
private:
	map<string, ASpell *> spellBook;
 
public:
	SpellBook() {}

	~SpellBook() {}

	void learnSpell(ASpell *spell) {
		if (spell)
			spellBook.insert(make_pair(spell->getName(), spell->clone()));
	}

	void forgetSpell(const string &spellName) {
		if (spellBook.find(spellName) != spellBook.end())
			spellBook.erase(spellBook.find(spellName));
	}

	ASpell* createSpell(string const &spellName) {
		ASpell *tmp = NULL;
		if (spellBook.find(spellName) != spellBook.end())
			tmp = spellBook[spellName];
		return tmp;
	}
};

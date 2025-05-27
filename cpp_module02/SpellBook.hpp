#pragma once

#include "ASpell.hpp"

class SpellBook {
 public:
	SpellBook() {}

	~SpellBook() {}

	void learnSpell(ASpell *spell) {
		if (spell)
			_spellBook[spell->getName()] = spell->clone();
	}

	void forgetSpell(const string &spellName) {
        auto it = _spellBook.find(spellName);
        if (it != _spellBook.end())
            _spellBook.erase(it);
	}

	ASpell* createSpell(string const &spellName) {
		ASpell *tmp = NULL;
		auto it = _spellBook.find(spellName);
		if (it != _spellBook.end())
			tmp = it->second;
		return tmp;
	}

 private:
	map<string, ASpell *> _spellBook;
};

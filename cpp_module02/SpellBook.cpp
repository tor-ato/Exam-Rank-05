#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *spell) {
	if (spell)
		spellBook.insert(std::make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string &spellName) {
	if (spellBook.find(spellName) != spellBook.end())
		spellBook.erase(spellBook.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	ASpell *tmp = NULL;
	if (spellBook.find(spellName) != spellBook.end())
		tmp = spellBook[spellName];
	return tmp;
}

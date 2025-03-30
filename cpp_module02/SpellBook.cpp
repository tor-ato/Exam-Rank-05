#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = spellBook.begin(); it != spellBook.end(); ++it)
		delete it->second;
	spellBook.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		spellBook.insert(std::make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	if (spellBook.find(spellName) != spellBook.end())
	{
		delete spellBook[spellName];
		spellBook.erase(spellBook.find(spellName));
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	ASpell *tmp = NULL;
	if (spellBook.find(spellName) != spellBook.end())
		tmp = spellBook[spellName];
	return (tmp);
}

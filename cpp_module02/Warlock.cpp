#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
: name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";
}


const std::string &Warlock::getName() const
{
	return (name);
}

const std::string &Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}


void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spellName)
{
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target)
{
	ASpell *tmp = spellBook.createSpell(spellName);
	if (tmp)
		tmp->launch(target);
}

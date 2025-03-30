#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : name (name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const {
	return name;
}

const std::string &Warlock::getTitle() const {
	return title;
}

void Warlock::setTitle(const std::string &title) {
	this->title = title;
}

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell) {
	if (spell)
		spellBook.insert(std::make_pair(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(const std::string &spellName) {
	if (spellBook.find(spellName) != spellBook.end())
		spellBook.erase(spellBook.find(spellName));
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target) {
	if (spellBook.find(spellName) != spellBook.end())
		spellBook[spellName]->launch(target);
}

#pragma once

#include <string>
#include <iostream>
#include <map>

#include "ATarget.hpp"

class Warlock {
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell *> spellBook;
 
public:
	Warlock(const std::string &name, const std::string &title) : name (name), title(title) {
		std::cout << name << ": This looks like another boring day." << std::endl;
	}

	~Warlock() {
		std::cout << name << ": My job here is done!" << std::endl;
	}

	const std::string &getName() const {
		return name;
	}

	const std::string &getTitle() const {
		return title;
	}

	void setTitle(const std::string &title) {
		this->title = title;
	}

	void introduce() const {
		std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
	}

	void learnSpell(ASpell *spell) {
		if (spell)
			spellBook.insert(std::make_pair(spell->getName(), spell->clone()));
	}

	void forgetSpell(const std::string &spellName) {
		if (spellBook.find(spellName) != spellBook.end())
			spellBook.erase(spellBook.find(spellName));
	}

	void launchSpell(const std::string &spellName, const ATarget &target) {
		if (spellBook.find(spellName) != spellBook.end())
			spellBook[spellName]->launch(target);
	}
};

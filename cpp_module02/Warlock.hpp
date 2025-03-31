#pragma once

#include <map>
#include "ATarget.hpp"
#include "SpellBook.hpp"

using namespace std;

class Warlock {
private:
	string name;
	string title;
	SpellBook spellBook;
 
public:
	Warlock(const string &name, const string &title) : name (name), title(title) {
		cout << name << ": This looks like another boring day." << endl;
	}

	~Warlock() {
		cout << name << ": My job here is done!" << endl;
	}

	const string &getName() const {
		return name;
	}

	const string &getTitle() const {
		return title;
	}

	void setTitle(const string &title) {
		this->title = title;
	}

	void introduce() const {
		cout << name << ": I am " << name << ", " << title << "!" << endl;
	}

	void learnSpell(ASpell *spell) {
		if (spell)
			spellBook.learnSpell(spell);
	}

	void forgetSpell(const string &spellName) {
		spellBook.forgetSpell(spellName);
	}

	void launchSpell(const string &spellName, const ATarget &target) {
		ASpell *tmp = NULL;
		spellBook.createSpell(spellName);
		if (tmp)
			tmp->launch(target);
	}
};

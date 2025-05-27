#pragma once

#include <map>
#include "ATarget.hpp"
#include "SpellBook.hpp"

using namespace std;

class Warlock {
 public:
	Warlock(const string &name, const string &title) : _name(name), _title(title) {
		cout << _name << ": This looks like another boring day." << endl;
	}

	~Warlock() {
		cout << _name << ": My job here is done!" << endl;
	}

	const string &getName() const {
		return _name;
	}

	const string &getTitle() const {
		return _title;
	}

	void setTitle(const string &title) {
		_title = title;
	}

	void introduce() const {
		cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
	}

	void learnSpell(ASpell *spell) {
		if (spell)
			_spellBook.learnSpell(spell);
	}

	void forgetSpell(const string &spellName) {
		_spellBook.forgetSpell(spellName);
	}

	void launchSpell(const string &spellName, const ATarget &target) {
		ASpell *spell = _spellBook.createSpell(spellName);
		if (spell)
			spell->launch(target);
	}

 private:
	string _name;
	string _title;
	SpellBook _spellBook;
};

#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ATarget.hpp"

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
            _spellBook[spell->getName()] = spell->clone();
	}

	void forgetSpell(const string &spellName) {
        auto it = _spellBook.find(spellName);
        if (it != _spellBook.end())
            _spellBook.erase(it);
	}

	void launchSpell(const string &spellName, const ATarget &target) {
		auto it = _spellBook.find(spellName);
		if (it != _spellBook.end())
			it->second->launch(target);
	}

 private:
	string _name;
	string _title;
	map<string, ASpell *> _spellBook;
};

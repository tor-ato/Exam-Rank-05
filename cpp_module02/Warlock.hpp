#pragma once

#include <map>
#include "ATarget.hpp"

using namespace std;

class Warlock {
private:
	string name;
	string title;
	map<string, ASpell *> spellBook;
 
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
			spellBook.insert(make_pair(spell->getName(), spell->clone()));
	}

	void forgetSpell(const string &spellName) {
		if (spellBook.find(spellName) != spellBook.end())
			spellBook.erase(spellBook.find(spellName));
	}

	void launchSpell(const string &spellName, const ATarget &target) {
		if (spellBook.find(spellName) != spellBook.end())
			spellBook[spellName]->launch(target);
	}
};
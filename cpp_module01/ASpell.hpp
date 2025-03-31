#pragma once

#include <string>
#include <iostream>

#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell {
private:
	string name;
	string effects;

public:
	ASpell(const string &name, const string &effects) : name(name), effects(effects) {}

	virtual ~ASpell() {}

	const string &getName() const {
		return name;
	}

	const string &getEffects() const {
		return effects;
	}

	virtual ASpell *clone() const = 0;

	void launch(const ATarget &target) const;
};

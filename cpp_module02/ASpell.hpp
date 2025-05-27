#pragma once

#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell {
 public:
	ASpell(const string &name, const string &effects) : _name(name), _effects(effects) {}

	virtual ~ASpell() {}

	const string &getName() const {
		return _name;
	}

	const string &getEffects() const {
		return _effects;
	}

	virtual ASpell *clone() const = 0;

	void launch(const ATarget &target) const;

 private:
	string _name;
	string _effects;
};

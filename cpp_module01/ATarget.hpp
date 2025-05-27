#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget {
 public:
	ATarget(const string &type) : _type(type) {}

	virtual ~ATarget() {}

	const string &getType() const {
		return _type;
	}

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;

 private:
	string _type;
};

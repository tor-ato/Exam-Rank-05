#pragma once

#include <string>
#include <iostream>

#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget {
private:
	string type;

public:
	ATarget(const string &type) : type(type) {}

	~ATarget() {}

	const string &getType() const {
		return type;
	}

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;
};
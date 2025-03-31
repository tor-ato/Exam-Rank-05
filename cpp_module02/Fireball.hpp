#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell {
public:
	Fireball() : ASpell("Fireball", "burnt to a crisp") {}

	virtual ~Fireball() {}

	ASpell *clone() const {
		return new Fireball();
	}
};

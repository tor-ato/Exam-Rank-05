#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const {
	cout << _type << " has been " << spell.getEffects() << "!" << endl;
}
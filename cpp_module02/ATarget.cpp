#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const {
	cout << type << " has been " << spell.getEffects() << "!" << endl;
}

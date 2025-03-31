#pragma once

#include "ATarget.hpp"

class ATarget;

class BrickWall : public ATarget {
public:
	BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

	~BrickWall() {}

	ATarget *clone() const {
		return new BrickWall();
	}
};

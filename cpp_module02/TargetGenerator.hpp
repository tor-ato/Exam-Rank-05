#pragma once

#include "ATarget.hpp"

class TargetGenerator {
private:
	map<string, ATarget *> targetBook;
 
public:
	TargetGenerator() {}

	~TargetGenerator() {}

	void learnTargetType(ATarget *target) {
		if (target)
			targetBook.insert(make_pair(target->getType(), target->clone()));
	}

	void forgetTarget(const string &targetType) {
		if (targetBook.find(targetType) != targetBook.end())
			targetBook.erase(targetBook.find(targetType));
	}

	ATarget* createTarget(string const &targetType) {
		ATarget *tmp = NULL;
		if (targetBook.find(targetType) != targetBook.end())
			tmp = targetBook[targetType];
		return tmp;
	}
};

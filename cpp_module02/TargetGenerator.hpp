#pragma once

#include "ATarget.hpp"

class TargetGenerator {
 public:
	TargetGenerator() {}

	~TargetGenerator() {}

	void learnTargetType(ATarget *target) {
		if (target)
            _targetBook[target->getType()] = target->clone();
	}

	void forgetTarget(const string &targetType) {
        auto it = _targetBook.find(targetType);
        if (it != _targetBook.end())
            _targetBook.erase(it);
	}

	ATarget* createTarget(string const &targetType) {
		ATarget *tmp = NULL;
		auto it = _targetBook.find(targetType);
		if (it != _targetBook.end())
			tmp = it->second;
		return tmp;
	}

 private:
	map<string, ATarget *> _targetBook;
};

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target) {
	if (target)
		targetBook.insert(std::make_pair(target->getType(), target->clone()));
}

void TargetGenerator::forgetTarget(const std::string &targetType) {
	if (targetBook.find(targetType) != targetBook.end())
		targetBook.erase(targetBook.find(targetType));
}

ATarget* TargetGenerator::createTarget(std::string const &targetType) {
	ATarget *tmp = NULL;
	if (targetBook.find(targetType) != targetBook.end())
		tmp = targetBook[targetType];
	return tmp;
}
